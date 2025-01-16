#include "Mars.h"

void Mars::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Mars");
	//座標の変更
	model_->SetTranslate({ -9.0f,9.0f,-9.0f });
}

void Mars::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Mars::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Mars::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
