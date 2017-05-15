//
//	�����	2017/05/11
//
//	�쐬��	ToshikiIchioka
//
//	�p�r	�J�����𐧌䂷��֐�
//
#include "Camera.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

Camera::Camera(int w, int h)
	:eyepos(0, 0, 5.0f)
	, refpos(0, 0, 0.1f)
	, upvec(0, -1.0f, 0)
{
	aspect = (float)w / h;
	nearClip = 0.1f;
	farClip = 1000.0f;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��𐶐�
	m_view = Matrix::CreateLookAt(eyepos, refpos, upvec);
		//�ˉe�s��̐���
	m_proj = Matrix::CreatePerspectiveFieldOfView(fovY, aspect, nearClip, farClip);
}

Matrix Camera::GetViewMatrix()
{
	return m_view;
}

Matrix Camera::GetProjMatrix()
{
	return m_proj;
}

void Camera::Seteyepos(Vector3& eyepos)
{
	this->eyepos = eyepos;
}

void Camera::Setrefpos(Vector3& refpos)
{
	this->refpos = refpos;
}

void Camera::Setupvec(Vector3& upvec)
{
	this->upvec = upvec;
}

void Camera::SetfovY(float fovY)
{
	this->fovY = fovY;
}

void Camera::Setaspect(float aspect)
{
	this->aspect = aspect;
}

void Camera::SetnearClip(float nearclip)
{
	this->nearClip = nearclip;
}

void Camera::SetfarClip(float farclip)
{
	this->farClip = farclip;
}
