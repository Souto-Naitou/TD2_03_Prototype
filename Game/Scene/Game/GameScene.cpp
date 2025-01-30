#include "GameScene.h"
#include <Features/SceneTransition/TransFadeInOut.h>
#include <Features/Object3d/Object3dSystem.h>
#include <Core/Win32/WinSystem.h>
#include <Features/DeltaTimeManager/DeltaTimeManager.h>

void GameScene::Initialize()
{
	/// インスタンスの取得
	pInput_ = Input::GetInstance();
	pSceneTransition_ = SceneTransitionManager::GetInstance();

	DeltaTimeManager::GetInstance()->SetDeltaTime(0, 1.0f / 60.0f);

	/// アイの初期化
	debugEye_ = std::make_unique<GameEye>();
	debugEye_->SetName("debug");
	debugEye_->SetTranslate(Vector3(0, 39.19f, -97.0f));
	debugEye_->SetRotate(Vector3(0.37f, 0, 0));

	gameEye_ = std::make_unique<GameEye>();
	gameEye_->SetName("game");
	gameEye_->SetTranslate(Vector3(0, 0, 0));
	gameEye_->SetRotate(Vector3(0, 0, 0));
	
	//システムにカメラを登録
	Object3dSystem::GetInstance()->SetSharedGameEye(debugEye_.get());

	//オブジェクトの初期化
	skydome_ = std::make_unique<Skydome>();
	skydome_->Initialize();
	solar_ = std::make_unique<Solar>();
	solar_->Initialize();
	mercury_ = std::make_unique<Mercury>();
	mercury_->Initialize();
	venus_ = std::make_unique<Venus>();
	venus_->Initialize();
	mars_ = std::make_unique<Mars>();
	mars_->Initialize();
	jupiter_ = std::make_unique<Jupiter>();
	jupiter_->Initialize();
	saturn_ = std::make_unique<Saturn>();
	saturn_->Initialize();
	earth_ = std::make_unique<Earth>();
	earth_->Initialize();
	//プレイヤー
	player_ = std::make_unique<Player>();
	player_->Initialize();
	player_->SetEye(gameEye_.get());
	player_->SetEarth(earth_.get());



}

void GameScene::Finalize()
{
	debugEye_.reset();
	gameEye_.reset();
	solar_->Finalize();
	mercury_->Finalize();
	venus_->Finalize();
	mars_->Finalize();
	jupiter_->Finalize();
	saturn_->Finalize();
	earth_->Finalize();
	skydome_->Finalize();
}

void GameScene::Update()
{
	debugEye_->Update();
	gameEye_->Update();
	//プレイヤーの更新
	player_->Update();
	//オブジェクトの更新
	skydome_->Update();
	solar_->Update();
	mercury_->Update();
	venus_->Update();
	mars_->Update();
	jupiter_->Update();
	saturn_->Update();
	earth_->Update();
	//プレイヤーの後更新処理
	player_->PostUpdate();

	if (pInput_->TriggerKey(DIK_SPACE))
	{
		pSceneTransition_->ChangeScene("ClearScene", std::make_unique<TransFadeInOut>());
	}

#ifdef _DEBUG
	if (pInput_->TriggerKey(DIK_TAB)) {
		//すべてのオブジェクトをgame用に再登録 ※切り替えは今は未実装
		eyeNumber++;
		if (eyeNumber > 1)
			eyeNumber = 0;
		switch (eyeNumber)
		{
		case 0:
			Object3dSystem::GetInstance()->SetSharedGameEye(debugEye_.get());
			break;
		case 1:
			Object3dSystem::GetInstance()->SetSharedGameEye(gameEye_.get());
			break;
		default:
			break;
		}
	}
#endif // _DEBUG
}

void GameScene::Draw2dBackGround()
{
}

void GameScene::Draw3d()
{
	//オブジェクトの描画
	skydome_->Draw();
	solar_->Draw();
	mercury_->Draw();
	venus_->Draw();
	mars_->Draw();
	jupiter_->Draw();
	saturn_->Draw();
	earth_->Draw();
}

void GameScene::Draw2dMidground()
{
}

void GameScene::Draw3dMidground()
{
}

void GameScene::DrawLine()
{
}

void GameScene::Draw2dForeground()
{
}
