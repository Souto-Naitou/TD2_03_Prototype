#pragma once
#include "Features/Object3d/Object3d.h"
#include <memory>
class Skydome
{
public:
	~Skydome();

	void Initialize();
	void Update();
	void Draw();

private:
	//モデル
	std::unique_ptr<Object3d> model_ = nullptr;

};

