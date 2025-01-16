#pragma once

#include <Interfaces/IScene.h>
#include <Features/GameEye/GameEye.h>
#include <Features/Input/Input.h>
#include <Features/SceneTransition/SceneTransitionManager.h>
#include <memory>

class ClearScene : public IScene
{
public:
    /// <summary>
    /// ������
    /// </summary>
    void Initialize() override;

    /// <summary>
    /// �I��
    /// </summary>
    void Finalize() override;

    /// <summary>
    /// �X�V
    /// </summary>
    void Update() override;

    /// <summary>
    /// �w�i�`��
    /// </summary>
    void Draw2dBackGround() override;

    /// <summary>
    /// 3D�`��
    /// </summary>
    void Draw3d() override;

    /// <summary>
    /// ���i�`��
    /// </summary>
    void Draw2dMidground() override;

    /// <summary>
    /// 3D���i�`��
    /// </summary>
    void Draw3dMidground() override;

    /// <summary>
    /// ���C���`��
    /// </summary>
    void DrawLine() override;

    /// <summary>
    /// �O�i�`��
    /// </summary>
    void Draw2dForeground() override;


private:
    std::unique_ptr<GameEye>                    gameEye_            = {};           // !< �Q�[���A�C
    

private:
    Input*                                      pInput_             = nullptr;      // !< ����
    SceneTransitionManager*                     pSceneTransition_   = nullptr;      // !< �V�[���J��
};