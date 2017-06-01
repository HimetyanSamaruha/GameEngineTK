#pragma once

#include "Camera.h"
#include <Keyboard.h>

class FollowCamera :public Camera
{
public:
	static const float CAMERA_DISTANCE;
	static const float CAMERA_DISTANCE_FPS;

	//コンストラクタ
	FollowCamera(int w, int h);
	
	//毎フレーム更新
	void Update() override;

	//視点をセット
	void SetTargetpos(DirectX::SimpleMath::Vector3 taregtpos);

	void SetTagetAngle(float targetangle);

	void SetKeyboard(DirectX::Keyboard *keyborard);

protected:
	//追従対象の座標
	DirectX::SimpleMath::Vector3 m_target_pos;

	//追従対象の回転角
	float m_target_rot;

	DirectX::Keyboard* m_keyboard;

	DirectX::Keyboard::KeyboardStateTracker m_tracker;

	int maincamera;
};