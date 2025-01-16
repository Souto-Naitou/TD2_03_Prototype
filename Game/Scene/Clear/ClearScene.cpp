#include "ClearScene.h"
#include <Features/SceneTransition/TransFadeInOut.h>
#include <Core/Win32/WinSystem.h>

void ClearScene::Initialize()
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

void ClearScene::Finalize()
{
    gameEye_.reset();
}

void ClearScene::Update()
{
    gameEye_->Update();

    if (pInput_->TriggerKey(DIK_SPACE))
    {
        pSceneTransition_->ChangeScene("TitleScene", std::make_unique<TransFadeInOut>());
    }
}

void ClearScene::Draw2dBackGround()
{
}

void ClearScene::Draw3d()
{
}

void ClearScene::Draw2dMidground()
{
}

void ClearScene::Draw3dMidground()
{
}

void ClearScene::DrawLine()
{
}

void ClearScene::Draw2dForeground()
{
}
