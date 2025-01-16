#include "BasePlanet.h"

void BasePlanet::Initialize()
{
	//共通変数の初期化
	model_ = std::make_unique<Object3d>();
	model_->Initialize("uvSphere.obj");
	model_->SetScale({ 1.0f,1.0f,1.0f });
	model_->SetName("one planet");
	model_->SetEnableLighting(true);

	radius_ = 1.0f;
}

void BasePlanet::Update()
{
	////半径に応じてスケールを変える
	//model_->SetScale({ radius_,radius_ ,radius_ , });
	//モデルの更新
	model_->Update();
}

void BasePlanet::Draw()
{
	//モデルの描画
	model_->Draw();
}

void BasePlanet::Finalize()
{
	//モデルの終了処理
	model_->Finalize();
}
