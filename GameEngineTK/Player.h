#pragma once

#include "Obj3d.h"
#include <vector>

#include <Keyboard.h>

class Player :public Obj3d
{
public:
	enum PLAYER_PARTS
	{
		PLAYER_PARTS_LEG,
		PLAYER_PARTS_BODY,
		PLAYER_PARTS_GUN1,
		PLAYER_PARTS_GUN2,
		PLAYER_PARTS_GUN3,
		PLAYER_PARTS_GUN4,
		PLAYER_PARTS_GIA,

		PLAYER_PARTS_NUM,
	};

private:

	std::vector<Obj3d> m_Obj3d;

	DirectX::Keyboard::State m_keyboard;

public:

	Player();

	~Player();

	void SetKeyboard(DirectX::Keyboard::State key);

	void Update();

	void Drow();

	void Initialize();

	void SetParentRotation(DirectX::SimpleMath::Vector3& rotation);
	void SetParentTranslation(DirectX::SimpleMath::Vector3& translation);

	const DirectX::SimpleMath::Vector3& GetParentRotation();
	const DirectX::SimpleMath::Vector3& GetParentTranslation();
};