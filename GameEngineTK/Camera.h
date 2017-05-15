//
//	�����	2017/05/11
//
//	�쐬��	ToshikiIchioka
//
//	�p�r	�J�����𐧌䂷��N���X
//

#include <d3d11.h>
#include <SimpleMath.h>
#pragma once

class Camera
{
protected:
	//�ޗ��͂�����

	//�r���[�s��
	DirectX::SimpleMath::Matrix m_view;
	//�ǂ����猩��̂��i���_
	DirectX::SimpleMath::Vector3 eyepos;
	//�ǂ�������̂��i�����_
	DirectX::SimpleMath::Vector3 refpos;
	//�ǂ��炪��ʏォ�i������x�N�g��
	DirectX::SimpleMath::Vector3 upvec;

	//�v���W�F�N�V�����s��
	DirectX::SimpleMath::Matrix m_proj;
	//������������p
	float fovY;
	//�A�X�y�N�g��
	float aspect;
	//��O�̕\�����E
	float nearClip;
	//���̕\�����E
	float farClip;

public:
	Camera(int w,int h);
	virtual ~Camera();

	virtual void Update();

	DirectX::SimpleMath::Matrix GetViewMatrix();

	DirectX::SimpleMath::Matrix GetProjMatrix();

	//���_���Z�b�g
	void Seteyepos(DirectX::SimpleMath::Vector3& eyepos);

	void Setrefpos(DirectX::SimpleMath::Vector3& refpos);

	void Setupvec(DirectX::SimpleMath::Vector3& upvec);

	void SetfovY(float fovY);

	void Setaspect(float aspect);

	void SetnearClip(float nearclip);

	void SetfarClip(float farclip);

};