#pragma once
#include <Features/Object3d/Object3d.h>
#include <memory>

class BasePlanet
{
public:
	/// デストラクタ
	virtual ~BasePlanet() {};

	/// 初期化
	virtual void Initialize();
	/// 更新
	virtual void Update();
	/// 描画
	virtual void Draw();
	/// 終了
	virtual void Finalize();

protected:
	//モデル
	std::unique_ptr<Object3d> model_ = nullptr;
	//半径
	float radius_ = 0.0f;

};

