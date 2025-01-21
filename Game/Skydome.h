#pragma once
#include "Features/Object3d/Object3d.h"
#include "Features/GameEye/GameEye.h"
#include <memory>
class Skydome
{
public:
	~Skydome();

	void Initialize();
	void Update();
	void Draw();

	//カメラのセット
	void SetEye(GameEye* eye) { model_->SetGameEye(eye); }

private:
	//モデル
	std::unique_ptr<Object3d> model_ = nullptr;

};

