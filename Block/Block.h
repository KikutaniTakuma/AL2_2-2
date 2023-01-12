#pragma once

#include "Game/Object/Object.h"
#include "Game/Easing/Easing.h"
#include <vector>
#include "Game/Frame/Frame.h"

class Block : public Object {
public:
	Block(Camera* cameraPointa, Vector2D pos, std::function<float(float)> function);

private:
	Vector2D startPos;
	std::vector<Quad> shadow;
	std::function<float(float)> func;
	Easing ease;
	Frame frame;
	bool flg;

public:
	void Update() override;
	void Draw(class Texture& tex) override;
	void Reset() override;
};