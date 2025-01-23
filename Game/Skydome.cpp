#include "Skydome.h"

void Skydome::Initialize()
{
	//モデルの生成と初期化
	model_ = std::make_unique<Object3d>();
	model_->Initialize("skydome.obj");
	model_->SetScale({ 3.0f,3.0f,3.0f });
	model_->SetName("Skydome");
	model_->SetEnableLighting(false);
}

void Skydome::Update()
{
	//更新処理
	model_->Update();
}

void Skydome::Draw()
{
	//描画処理
	model_->Draw();
}

void Skydome::Finalize()
{
	//終了処理
	model_->Finalize();
}


