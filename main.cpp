#include <Novice.h>
#include "Game/Camera/Camera.h"
#include "Block/Block.h"
#include "Game/KeyInput/KeyInput.h"
#include "Game/Texture/Texture.h"

const char kWindowTitle[] = "LC1A_08_キクタニタクマ_タイトル";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 640, 480);

	Camera* camera = new Camera;

	Block block1(camera, { 100.0f,100.0f }, Easing::EaseInSine);
	Block block2(camera, { 100.0f,300.0f }, Easing::EaseOutSine);

	Texture tex("./white1x1.png", 1, 1, 1);

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		KeyInput::Input();

		///
		/// ↓更新処理ここから
		///
		block1.Update();
		block2.Update();
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		camera->Update();
		block1.Draw(tex);
		block2.Draw(tex);
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (KeyInput::Released(DIK_ESCAPE)) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
