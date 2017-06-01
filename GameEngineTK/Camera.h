//
//	�����	2017/05/11
//
//	�쐬��	ToshikiIchioka
//
//	�p�r	�J�����𐧌䂷��N���X
//

#include <d3d11_1.h>
#include <SimpleMath.h>
#pragma once

class Camera
{
protected:
	//�ޗ��͂�����

	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//�ǂ����猩��̂��i���_
	DirectX::SimpleMath::Vector3 m_eyepos;
	//�ǂ�������̂��i�����_
	DirectX::SimpleMath::Vector3 m_refpos;
	//�ǂ��炪��ʏォ�i������x�N�g��
	DirectX::SimpleMath::Vector3 m_upvec;

	//�v���W�F�N�V�����s��
	DirectX::SimpleMath::Matrix m_proj;
	//������������p
	float m_fovY;
	//�A�X�y�N�g��
	float m_aspect;
	//��O�̕\�����E
	float m_nearClip;
	//���̕\�����E
	float m_farClip;

public:
	Camera(int w,int h);
	virtual ~Camera();

	virtual void Update();

	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	const DirectX::SimpleMath::Matrix& GetProjMatrix();

	//���_���Z�b�g
	void Seteyepos(const DirectX::SimpleMath::Vector3& eyepos);

	void Setrefpos(const DirectX::SimpleMath::Vector3& refpos);

	void Setupvec(const DirectX::SimpleMath::Vector3& upvec);

	void SetfovY(float fovY);

	void Setaspect(float aspect);

	void SetnearClip(float nearclip);

	void SetfarClip(float farclip);

};