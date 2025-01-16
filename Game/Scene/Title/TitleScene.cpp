#include "TitleScene.h"
#include <Features/SceneTransition/TransFadeInOut.h>
#include <Core/Win32/WinSystem.h>

void TitleScene::Initialize()
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

void TitleScene::Finalize()
{
    gameEye_.reset();
}

void TitleScene::Update()
{
    gameEye_->Update();

    if (pInput_->TriggerKey(DIK_SPACE))
    {
        pSceneTransition_->ChangeScene("GameScene", std::make_unique<TransFadeInOut>());
    }
}

void TitleScene::Draw2dBackGround()
{
}

void TitleScene::Draw3d()
{
}

void TitleScene::Draw2dMidground()
{
}

void TitleScene::Draw3dMidground()
{
}

void TitleScene::DrawLine()
{
}

void TitleScene::Draw2dForeground()
{
}
