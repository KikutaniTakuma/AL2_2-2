#include "Block.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/Texture/Texture.h"

Block::Block(Camera* cameraPointa, Vector2D pos, std::function<float(float)> function) :
	Object(cameraPointa),
	ease(pos, {pos.x + 400.0f, pos.y}, 0.02f, function),
	flg(false),
	func(function),
	startPos(pos)
{
	this->pos.Set(pos, { 50.0f, 50.0f });

	shadow.reserve(0);

	frame.Restart();
}

void Block::Update() {
	if (KeyInput::Pushed(DIK_SPACE)) {
		flg = true;
		frame.Restart();
		shadow.resize(0);
	}
	if (flg) {
		frame.Start();

		pos.worldPos = ease.Update();

		if (frame % 5 == 0) {
			shadow.emplace_back(pos);
		}

		if (!ease) {
			flg = false;
			frame.Stop();
			ease.Set(startPos, { startPos.x + 400.0f, startPos.y }, 0.02f, func);
		}
	}
}

void Block::Draw(Texture& tex) {
	pos.worldMatrix.Translate(pos.worldPos);

	Quad start = pos;
	Quad end = pos;

	start.worldPos = startPos;
	end.worldPos.x = startPos.x + 400.0f;

	start.worldMatrix.Translate(start.worldPos);
	end.worldMatrix.Translate(end.worldPos);

	camera->DrawQuad(start, tex, 0, false, MyMath::GetRGB(255, 0, 0, 255));
	camera->DrawQuad(end, tex, 0, false, MyMath::GetRGB(255, 0, 0, 255));

	for (auto& i : shadow) {
		camera->DrawQuad(i, tex, 0, false, MyMath::GetRGB(100, 100, 100, 100));
	}

	camera->DrawQuad(pos, tex, 0, false);
}

void Block::Reset() {

}