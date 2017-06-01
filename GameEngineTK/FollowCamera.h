#pragma once

#include "Camera.h"
#include <Keyboard.h>

class FollowCamera :public Camera
{
public:
	static const float CAMERA_DISTANCE;
	static const float CAMERA_DISTANCE_FPS;

	//�R���X�g���N�^
	FollowCamera(int w, int h);
	
	//���t���[���X�V
	void Update() override;

	//���_���Z�b�g
	void SetTargetpos(DirectX::SimpleMath::Vector3 taregtpos);

	void SetTagetAngle(float targetangle);

	void SetKeyboard(DirectX::Keyboard *keyborard);

protected:
	//�Ǐ]�Ώۂ̍��W
	DirectX::SimpleMath::Vector3 m_target_pos;

	//�Ǐ]�Ώۂ̉�]�p
	float m_target_rot;

	DirectX::Keyboard* m_keyboard;

	DirectX::Keyboard::KeyboardStateTracker m_tracker;

	int maincamera;
};