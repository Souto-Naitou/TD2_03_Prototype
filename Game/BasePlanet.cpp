#include "BasePlanet.h"
#include <random>

void BasePlanet::Initialize()
{
	//共通変数の初期化
	model_ = std::make_unique<Object3d>();
	model_->Initialize("uvSphere.obj");
	model_->SetScale({ 1.0f,1.0f,1.0f });
	model_->SetName("one planet");
	model_->SetEnableLighting(true);

	radius_ = 1.0f;
	//ランダムを利用して速度設定
	std::random_device seedGenerator;
	std::mt19937 randomEngine(seedGenerator());
	std::uniform_real_distribution<float> distvelocity(-0.2f, 0.2f);
	velocity_ = { distvelocity(randomEngine),distvelocity(randomEngine), distvelocity(randomEngine) };


}

void BasePlanet::Update()
{
	//モデルの更新
	model_->Update();

	//速度の加算処理
	Vector3 position = model_->GetTranslate();
	position += velocity_;
	model_->SetTranslate(position);

	//見えない壁との衝突処理
	if (position.x > 20.0f || position.x < -20.0f) {
		velocity_.x *= -1.0f;
	}
	if (position.y > 20.0f || position.y < -20.0f) {
		velocity_.y *= -1.0f;
	}
	if (position.z > 20.0f || position.z < -20.0f) {
		velocity_.z *= -1.0f;
	}

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
