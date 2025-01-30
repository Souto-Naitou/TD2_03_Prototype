#include "Saturn.h"

void Saturn::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Saturn");
	//座標の変更
	model_->SetTranslate({ -13.0f,-13.0f,13.0f });
}

void Saturn::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Saturn::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Saturn::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
