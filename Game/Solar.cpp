#include "Solar.h"

void Solar::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Solar");
	model_->SetScale({ 2.0f,2.0f,2.0f });
	//速度０に
	velocity_ = { 0.0f,0.0f,0.0f };
}

void Solar::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Solar::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Solar::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
