#include "Ohajiki.h"

#include <Common/define.h>
#include <Windows.h>
#include <Features/SceneManager/SceneManager.h>
#include <Scene/Factory/SceneFactory.h>

void Ohajiki::Initialize()
{
    /// ���N���X�̏���������
    NimaFramework::Initialize();

    /// �V�[���t�@�N�g���̐ݒ�
    pSceneFactory_ = new SceneFactory();
    pSceneManager_->SetSceneFactory(pSceneFactory_);

    /// �������[�h�p�X�̒ǉ�
    pModelManager_->AddAutoLoadPath("resources/models");

    /// ���f����S�ă��[�h
    pModelManager_->LoadAllModel();

    /// �V�[���̐���
    pSceneManager_->ReserveScene("RequiredScene");
}

void Ohajiki::Finalize()
{
    /// ���N���X�̏I������
    NimaFramework::Finalize();

    pSceneManager_->Finalize();

    /// �V�[���t�@�N�g���̉��
    delete pSceneFactory_;
}

void Ohajiki::Update()
{
    /// ���N���X�̍X�V����
    NimaFramework::Update();

    /// �V�[���X�V
    pSceneManager_->Update();

    /// �p�[�e�B�N���X�V
    pParticleManager_->Update();
}

void Ohajiki::Draw()
{
    /// �`�揈��
    pDirectX_->PresentDraw();
    pSRVManager_->PresentDraw();

    /// �w�i�X�v���C�g�̕`��
    pSpriteSystem_->PresentDraw();
    pSceneManager_->SceneDraw2dBackGround();

    /// 3D�`��
    pObject3dSystem_->PresentDraw();
    pSceneManager_->SceneDraw3d();

    /// �p�[�e�B�N���`��
    pParticleSystem_->PresentDraw();
    pParticleManager_->Draw();

    /// �O�i�X�v���C�g�̕`��
    pSpriteSystem_->PresentDraw();
    pSceneManager_->SceneDraw2dForeground();

    pImGuiManager_->EndFrame();
    pDirectX_->PostDraw();
}
