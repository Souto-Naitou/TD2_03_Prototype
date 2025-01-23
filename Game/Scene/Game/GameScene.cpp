#include "GameScene.h"
#include <Features/SceneTransition/TransFadeInOut.h>
#include <Features/Object3d/Object3dSystem.h>
#include <Core/Win32/WinSystem.h>

void GameScene::Initialize()
{
	/// インスタンスの取得
	pInput_ = Input::GetInstance();
	pSceneTransition_ = SceneTransitionManager::GetInstance();
	
	/// アイの初期化
	debugEye_ = std::make_unique<GameEye>();
	debugEye_->SetName("debug");
	debugEye_->SetTranslate(Vector3(0, 39.19f, -97.0f));
	debugEye_->SetRotate(Vector3(0.37f, 0, 0));

	gameEye_ = std::make_unique<GameEye>();
	gameEye_->SetName("game");
	gameEye_->SetTranslate(Vector3(0,0,0));
	gameEye_->SetRotate(Vector3(0,0,0));
	
	//システムにカメラを登録
	Object3dSystem::GetInstance()->SetDefaultGameEye(debugEye_.get());

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
}

void GameScene::Update()
{
	debugEye_->Update();
	gameEye_->Update();
	//オブジェクトの更新
	skydome_->Update();
	solar_->Update();
	mercury_->Update();
	venus_->Update();
	mars_->Update();
	jupiter_->Update();
	saturn_->Update();

	if (pInput_->TriggerKey(DIK_SPACE))
	{
		pSceneTransition_->ChangeScene("ClearScene", std::make_unique<TransFadeInOut>());
	}

#ifdef _DEBUG
	if (pInput_->TriggerKey(DIK_TAB)) {
		//すべてのオブジェクトをgame用に再登録 ※切り替えは今は未実装
		skydome_->SetEye(gameEye_.get());
		solar_->SetEye(gameEye_.get());
		mercury_->SetEye(gameEye_.get());
		venus_->SetEye(gameEye_.get());
		mars_->SetEye(gameEye_.get());
		jupiter_->SetEye(gameEye_.get());
		saturn_->SetEye(gameEye_.get());

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
