#pragma once

#include <Interfaces/IScene.h>
#include <Features/GameEye/GameEye.h>
#include <Features/Input/Input.h>
#include <Features/SceneTransition/SceneTransitionManager.h>
#include "Skydome.h"
#include "Solar.h"
#include "Mercury.h"
#include "Venus.h"
#include "Mars.h"
#include "Jupiter.h"
#include "Saturn.h"
#include <array>
#include <memory>

class GameScene : public IScene
{
public:
	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize() override;

	/// <summary>
	/// 終了
	/// </summary>
	void Finalize() override;

	/// <summary>
	/// 更新
	/// </summary>
	void Update() override;

	/// <summary>
	/// 背景描画
	/// </summary>
	void Draw2dBackGround() override;

	/// <summary>
	/// 3D描画
	/// </summary>
	void Draw3d() override;

	/// <summary>
	/// 中景描画
	/// </summary>
	void Draw2dMidground() override;

	/// <summary>
	/// 3D中景描画
	/// </summary>
	void Draw3dMidground() override;

	/// <summary>
	/// ライン描画
	/// </summary>
	void DrawLine() override;

	/// <summary>
	/// 前景描画
	/// </summary>
	void Draw2dForeground() override;


private:
	std::unique_ptr<GameEye>                    debugEye_ = {};           // !< デバッグアイ
	std::unique_ptr<GameEye>                    gameEye_ = {};			   // !< ゲームアイ

	std::vector<GameEye> eyeArray_;
	int eyeNumber_ = 0;

private:
	Input* pInput_ = nullptr;      // !< 入力
	SceneTransitionManager* pSceneTransition_ = nullptr;      // !< シーン遷移

private: /// オブジェクト
	//天球
	std::unique_ptr<Skydome> skydome_ = nullptr;
	//太陽
	std::unique_ptr<Solar> solar_ = nullptr;
	//水星
	std::unique_ptr<Mercury> mercury_ = nullptr;
	//金星
	std::unique_ptr<Venus> venus_ = nullptr;
	//火星
	std::unique_ptr<Mars> mars_ = nullptr;
	//木星
	std::unique_ptr<Jupiter> jupiter_ = nullptr;
	//土星
	std::unique_ptr<Saturn> saturn_ = nullptr;

};