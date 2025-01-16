#include "GameScene.h"
#include <Features/SceneTransition/TransFadeInOut.h>
#include <Core/Win32/WinSystem.h>

void GameScene::Initialize()
{
    /// インスタンスの取得
    pInput_ = Input::GetInstance();
    pSceneTransition_ = SceneTransitionManager::GetInstance();

    /// ゲームアイの初期化
    gameEye_ = std::make_unique<GameEye>();
    gameEye_->SetName("main");
    gameEye_->SetTranslate(Vector3(0, 15.0f, -30.0f));
    gameEye_->SetRotate(Vector3(-1.2f, 0, 0));
}

void GameScene::Finalize()
{
    gameEye_.reset();
}

void GameScene::Update()
{
    gameEye_->Update();

    if (pInput_->TriggerKey(DIK_SPACE))
    {
        pSceneTransition_->ChangeScene("ClearScene", std::make_unique<TransFadeInOut>());
    }
}

void GameScene::Draw2dBackGround()
{
}

void GameScene::Draw3d()
{
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
