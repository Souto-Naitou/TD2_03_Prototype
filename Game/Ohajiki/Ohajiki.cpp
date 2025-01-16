#include "Ohajiki.h"

#include <Common/define.h>
#include <Windows.h>
#include <Features/SceneManager/SceneManager.h>
#include <Scene/Factory/SceneFactory.h>

void Ohajiki::Initialize()
{
    /// 基底クラスの初期化処理
    NimaFramework::Initialize();

    /// シーンファクトリの設定
    pSceneFactory_ = new SceneFactory();
    pSceneManager_->SetSceneFactory(pSceneFactory_);

    /// 自動ロードパスの追加
    pModelManager_->AddAutoLoadPath("resources/models");
    pTextureManager_->AddSearchPath("resources/images");

    /// モデルを全てロード
    pModelManager_->LoadAllModel();

    /// シーンの生成
    pSceneManager_->ReserveScene("TitleScene");
}

void Ohajiki::Finalize()
{
    /// 基底クラスの終了処理
    NimaFramework::Finalize();

    pSceneManager_->Finalize();

    /// シーンファクトリの解放
    delete pSceneFactory_;
}

void Ohajiki::Update()
{
    /// 基底クラスの更新処理
    NimaFramework::Update();

    /// シーン更新
    pSceneManager_->Update();

    /// パーティクル更新
    pParticleManager_->Update();
}

void Ohajiki::Draw()
{
    /// 描画処理
    pDirectX_->PresentDraw();
    pSRVManager_->PresentDraw();

    /// 背景スプライトの描画
    pSpriteSystem_->PresentDraw();
    pSceneManager_->SceneDraw2dBackGround();

    /// 3D描画
    pObject3dSystem_->PresentDraw();
    pSceneManager_->SceneDraw3d();

    /// パーティクル描画
    pParticleSystem_->PresentDraw();
    pParticleManager_->Draw();

    /// 前景スプライトの描画
    pSpriteSystem_->PresentDraw();
    pSceneManager_->SceneDraw2dForeground();

    pImGuiManager_->EndFrame();
    pDirectX_->PostDraw();
}
