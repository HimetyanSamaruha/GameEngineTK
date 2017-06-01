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
	: m_eyepos(0, 0, 3.0f)
	, m_refpos(0, 0, 0)
	, m_upvec(0, 1.0f, 0)
{
	m_fovY = XMConvertToRadians(60.0f);
	m_aspect = (float)w / h;
	m_nearClip = 0.1f;
	m_farClip = 1000.0f;
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//�r���[�s��𐶐�
	m_view = Matrix::CreateLookAt(m_eyepos, m_refpos, m_upvec);
		//�ˉe�s��̐���
	m_proj = Matrix::CreatePerspectiveFieldOfView(m_fovY, m_aspect, m_nearClip, m_farClip);
}

const Matrix& Camera::GetViewMatrix()
{
	return m_view;
}

const Matrix& Camera::GetProjMatrix()
{
	return m_proj;
}

void Camera::Seteyepos(const Vector3& eyepos)
{
	m_eyepos = eyepos;
}

void Camera::Setrefpos(const Vector3& refpos)
{
	m_refpos = refpos;
}

void Camera::Setupvec(const Vector3& upvec)
{
	m_upvec = upvec;
}

void Camera::SetfovY(float fovY)
{
	m_fovY = fovY;
}

void Camera::Setaspect(float aspect)
{
	m_aspect = aspect;
}

void Camera::SetnearClip(float nearclip)
{
	m_nearClip = nearclip;
}

void Camera::SetfarClip(float farclip)
{
	m_farClip = farclip;
}
