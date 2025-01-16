#include "SceneFactory.h"

#include <Scene/Title/TitleScene.h>
#include <Scene/Game/GameScene.h>
#include <Scene/Clear/ClearScene.h>

#include <cassert>

#define JUDGE_SCENE_NAME(_scName) if (_sceneName == #_scName) pNewScene = new _scName();

IScene* SceneFactory::CreateScene(const std::string& _sceneName)
{
    IScene* pNewScene = nullptr;

    JUDGE_SCENE_NAME(TitleScene)
    else JUDGE_SCENE_NAME(GameScene)
    else JUDGE_SCENE_NAME(ClearScene)


    assert(pNewScene);

    return pNewScene;
}
