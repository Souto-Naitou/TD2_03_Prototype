#pragma once
#include "ImplFollowEye.h"
#include <Features/GameEye/GameEye.h>
#include <Earth.h>
#include <memory>
class Player
{
public:
	void Initialize();
	void Update();
	void Draw();

	//setter
	void SetEye(GameEye* _eye) { implFollowEye_->SetEye(_eye); }
	void SetEarth(Earth* _earth) { earth_ = _earth; }

private:
	void InputCommand();

private:
	Input* pInput_ = nullptr;
	std::unique_ptr<ImplFollowEye> implFollowEye_ = nullptr;
	Earth* earth_ = nullptr;




};

