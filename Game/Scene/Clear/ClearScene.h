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
    /// ‰Šú‰»
    /// </summary>
    void Initialize() override;

    /// <summary>
    /// I—¹
    /// </summary>
    void Finalize() override;

    /// <summary>
    /// XV
    /// </summary>
    void Update() override;

    /// <summary>
    /// ”wŒi•`‰æ
    /// </summary>
    void Draw2dBackGround() override;

    /// <summary>
    /// 3D•`‰æ
    /// </summary>
    void Draw3d() override;

    /// <summary>
    /// ’†Œi•`‰æ
    /// </summary>
    void Draw2dMidground() override;

    /// <summary>
    /// 3D’†Œi•`‰æ
    /// </summary>
    void Draw3dMidground() override;

    /// <summary>
    /// ƒ‰ƒCƒ“•`‰æ
    /// </summary>
    void DrawLine() override;

    /// <summary>
    /// ‘OŒi•`‰æ
    /// </summary>
    void Draw2dForeground() override;


private:
    std::unique_ptr<GameEye>                    gameEye_            = {};           // !< ƒQ[ƒ€ƒAƒC
    

private:
    Input*                                      pInput_             = nullptr;      // !< “ü—Í
    SceneTransitionManager*                     pSceneTransition_   = nullptr;      // !< ƒV[ƒ“‘JˆÚ
};