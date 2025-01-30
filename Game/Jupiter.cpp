#include "Jupiter.h"

void Jupiter::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Jupiter");
	//座標の変更
	model_->SetTranslate({ 11.0f,11.0f,-11.0f });
	
}

void Jupiter::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Jupiter::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Jupiter::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
