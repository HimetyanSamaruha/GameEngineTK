#include "FollowCamera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;


const float FollowCamera::CAMERA_DISTANCE = 5.0f;

FollowCamera::FollowCamera(int w, int h) 
	:Camera(w, h)
{
	m_target_pos = Vector3::Zero;
	m_target_rot = 0.0f;
}

void FollowCamera::Update()
{
	Vector3 Refpos, Eyepos;

	Refpos = m_target_pos + Vector3(0, 2.0f, 0);

	Vector3 cameraV(0.0f, 0.0f, CAMERA_DISTANCE);

	Matrix rotcamera = Matrix::CreateRotationY(m_target_rot);
	cameraV = Vector3::TransformNormal(cameraV, rotcamera);

	Eyepos = Refpos + cameraV;

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
