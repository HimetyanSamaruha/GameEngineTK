#pragma once

#include "Camera.h"

class FollowCamera :public Camera
{
public:
	static const float CAMERA_DISTANCE;

	//�R���X�g���N�^
	FollowCamera(int w, int h);
	
	//���t���[���X�V
	void Update() override;

	//���_���Z�b�g
	void SetTargetpos(DirectX::SimpleMath::Vector3 eyepos);

	void SetTagetAngle(float targetangle);

protected:
	//�Ǐ]�Ώۂ̍��W
	DirectX::SimpleMath::Vector3 m_target_pos;

	//�Ǐ]�Ώۂ̉�]�p
	float m_target_rot;
};