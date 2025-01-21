#include "Earth.h"

void Earth::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Solar");
	model_->SetScale({ 2.0f,2.0f,2.0f });
	//速度０に
	velocity_ = { 0.0f,0.0f,0.0f };
}

void Earth::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Earth::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Earth::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
