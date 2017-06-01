#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


const float FollowCamera::CAMERA_DISTANCE = 5.0f;
const float FollowCamera::CAMERA_DISTANCE_FPS = 0.01f;

FollowCamera::FollowCamera(int w, int h) 
	:Camera(w, h)
{
	m_target_pos = Vector3::Zero;
	m_target_rot = 0.0f;
	maincamera = 1;
	m_keyboard = nullptr;
}

void FollowCamera::Update()
{
	Keyboard::State keyboardstate = m_keyboard->GetState();
	m_tracker.Update(keyboardstate);

	Vector3 Refpos, Eyepos;

	if (m_tracker.IsKeyReleased(Keyboard::Keys::C))
	{
		maincamera = maincamera*-1;
	}

	if(maincamera==1)
	{
	//TPSカメラ
		Refpos = m_target_pos + Vector3(0, 2, 0);

		Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);

		Matrix rot = Matrix::CreateRotationY(m_target_rot);
		cameraV = Vector3::TransformNormal(cameraV, rot);

		Eyepos = Refpos + cameraV;

		//ゴム紐カメラ
		Eyepos = m_eyepos + (Eyepos - m_eyepos)*0.03f;
		Refpos = m_refpos + (Refpos - m_refpos)*0.15f;
	}
	else if(maincamera==-1)
	{
		//FPSカメラ
		Eyepos = m_target_pos + Vector3(0, 1.0f, 0);

		Vector3 cameraV(0, 0, -CAMERA_DISTANCE);
		Matrix rotmat = Matrix::CreateRotationY(m_target_rot);
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		Refpos = m_eyepos + cameraV;
	}


	Seteyepos(Eyepos);
	Setrefpos(Refpos);

	//基底クラスの更新
	Camera::Update();

}

void FollowCamera::SetTargetpos(DirectX::SimpleMath::Vector3 taregtpos)
{
	this->m_target_pos = taregtpos;
}

void FollowCamera::SetTagetAngle(float targetangle)
{
	this->m_target_rot = targetangle;
}

void FollowCamera::SetKeyboard(DirectX::Keyboard * keyborard)
{
	m_keyboard = keyborard;
}
