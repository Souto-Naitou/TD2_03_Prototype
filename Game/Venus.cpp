#include "Venus.h"

void Venus::Initialize()
{
	//ベースの初期化
	BasePlanet::Initialize();
	//名前の変更
	model_->SetName("Venus");
	//座標の変更
	model_->SetTranslate({ -7.0f,-7.0f,7.0f });
	
}

void Venus::Update()
{
	//ベースの更新
	BasePlanet::Update();

}

void Venus::Draw()
{
	//ベースの描画
	BasePlanet::Draw();

}

void Venus::Finalize()
{
	//ベースの終了
	BasePlanet::Finalize();

}
