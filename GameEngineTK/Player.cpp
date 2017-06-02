#include "Player.h"

#include <SimpleMath.h>

using namespace DirectX;
using namespace DirectX::SimpleMath;
using namespace std;

Player::Player()
{
}

Player::~Player()
{
}

void Player::SetKeyboard(Keyboard::State key)
{
	m_keyboard = key;
}

void Player::Update()
{
	//Wキーが押されたなら
	if (m_keyboard.W)
	{
		//移動ベクトル
		Vector3 moveV(0, 0, -0.1f);
		float angle = this->GetParentRotation().y;
		Matrix rotmat = Matrix::CreateRotationY(angle);
		//移動量ベクトルを自機の角度分回転させる
		moveV = Vector3::TransformNormal(moveV, rotmat);
		Vector3 pos = this->GetParentTranslation();
		this->SetParentTranslation(pos + moveV);
	}

	//Sキーが押されたなら
	if (m_keyboard.S)
	{
		Vector3 moveV(0, 0, -0.1f);
		float angle = this->GetParentRotation().y;//
		Matrix rotmat = Matrix::CreateRotationY(angle);
		//移動量ベクトルを自機の角度分回転させる
		moveV = Vector3::TransformNormal(moveV, rotmat);
		Vector3 pos = this->GetParentTranslation();
		this->SetParentTranslation(pos - moveV);
	}

	//Aキーが押されたなら
	if (m_keyboard.A)
	{
		//移動ベクトル
		float angle = this->GetParentRotation().y;
		this->SetParentRotation(Vector3(0, angle + 0.03f, 0));
	}

	//Dキーが押されたなら
	if (m_keyboard.D)
	{
		//移動ベクトル
		float angle = this->GetParentRotation().y;
		this->SetParentRotation(Vector3(0, angle - 0.03f, 0));
	}

	for (std::vector<Obj3d>::iterator it = m_Obj3d.begin(); it != m_Obj3d.end(); it++)
	{
		it->Update();
	}
}

void Player::Drow()
{
	for (std::vector<Obj3d>::iterator it = m_Obj3d.begin(); it != m_Obj3d.end(); it++)
	{
		it->Draw();
	}
}

void Player::Initialize()
{
	m_Obj3d.resize(PLAYER_PARTS_NUM);
	m_Obj3d[PLAYER_PARTS_LEG].LoadModel(L"Resources/tank.cmo");
	m_Obj3d[PLAYER_PARTS_BODY].LoadModel(L"Resources/body.cmo");
	m_Obj3d[PLAYER_PARTS_GUN1].LoadModel(L"Resources/gan.cmo");
	m_Obj3d[PLAYER_PARTS_GUN2].LoadModel(L"Resources/gan.cmo");
	m_Obj3d[PLAYER_PARTS_GUN3].LoadModel(L"Resources/gan.cmo");
	m_Obj3d[PLAYER_PARTS_GUN4].LoadModel(L"Resources/gan.cmo");
	m_Obj3d[PLAYER_PARTS_GIA].LoadModel(L"Resources/gia.cmo");

	m_Obj3d[PLAYER_PARTS_BODY].Setparent(&m_Obj3d[PLAYER_PARTS_LEG]);
	m_Obj3d[PLAYER_PARTS_GUN1].Setparent(&m_Obj3d[PLAYER_PARTS_BODY]);
	m_Obj3d[PLAYER_PARTS_GUN2].Setparent(&m_Obj3d[PLAYER_PARTS_BODY]);
	m_Obj3d[PLAYER_PARTS_GUN3].Setparent(&m_Obj3d[PLAYER_PARTS_LEG]);
	m_Obj3d[PLAYER_PARTS_GUN4].Setparent(&m_Obj3d[PLAYER_PARTS_LEG]);
	m_Obj3d[PLAYER_PARTS_GIA].Setparent(&m_Obj3d[PLAYER_PARTS_BODY]);

	//親からのオフセット
	m_Obj3d[PLAYER_PARTS_BODY].SetTranslation(Vector3(0, 0.5, 0.35));
	m_Obj3d[PLAYER_PARTS_GUN1].SetTranslation(Vector3(0, 0, -0.6));
	m_Obj3d[PLAYER_PARTS_GUN2].SetTranslation(Vector3(0, 0.25, 0));
	m_Obj3d[PLAYER_PARTS_GUN3].SetTranslation(Vector3(0.25, 0.5, 0));
	m_Obj3d[PLAYER_PARTS_GUN4].SetTranslation(Vector3(-0.25, 0.5, 0));
	m_Obj3d[PLAYER_PARTS_GIA].SetTranslation(Vector3(0, 0, 0.35));
	m_Obj3d[PLAYER_PARTS_GIA].SetRotation(Vector3(20, 0, 0));
}

void Player::SetParentTranslation(DirectX::SimpleMath::Vector3& translation)
{
	m_Obj3d[PLAYER_PARTS_LEG].SetTranslation(translation);
}

void Player::SetParentRotation(DirectX::SimpleMath::Vector3& rotation )
{
	m_Obj3d[PLAYER_PARTS_LEG].SetRotation(rotation);
}


const DirectX::SimpleMath::Vector3& Player::GetParentRotation()
{
	return m_Obj3d[PLAYER_PARTS_LEG].GetRotation();
}

const DirectX::SimpleMath::Vector3& Player::GetParentTranslation()
{
	return m_Obj3d[PLAYER_PARTS_LEG].GetTranslation();
}