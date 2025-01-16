#include "Mercury.h"

void Mercury::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Mercury");
	//座標の変更
	model_->SetTranslate({ 5.0f,5.0f,5.0f });
}

void Mercury::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Mercury::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Mercury::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
