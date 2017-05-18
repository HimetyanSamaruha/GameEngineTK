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
		Refpos = m_target_pos + Vector3(0, 1.0f, 0.0f);

		Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);

		Matrix rotcamera = Matrix::CreateRotationY(m_target_rot);
		cameraV = Vector3::TransformNormal(cameraV, rotcamera);

		Eyepos = Refpos + cameraV;

		//ゴム紐カメラ
		Eyepos = eyepos + (Eyepos - eyepos)*0.03f;
		Refpos = refpos + (Refpos - refpos)*0.15f;
	}
	else if(maincamera==-1)
	{
		//FPSカメラ
		Eyepos = m_target_pos + Vector3(0, 1.0f, 0);

		Vector3 cameraV(0, 0, -CAMERA_DISTANCE);
		Matrix rotmat = Matrix::CreateRotationY(m_target_rot);
		cameraV = Vector3::TransformNormal(cameraV, rotmat);
		Refpos = eyepos + cameraV;
	}


	this->Seteyepos(Eyepos);
	this->Setrefpos(Refpos);

	//基底クラスの更新
	Camera::Update();

}

void FollowCamera::SetTargetpos(DirectX::SimpleMath::Vector3 eyepos)
{
	this->m_target_pos = eyepos;
}

void FollowCamera::SetTagetAngle(float targetangle)
{
	this->m_target_rot = targetangle;
}

void FollowCamera::SetKeyboard(DirectX::Keyboard * keyborard)
{
	m_keyboard = keyborard;
}
