//
//	制作日	2017/05/11
//
//	作成者	ToshikiIchioka
//
//	用途	カメラを制御するクラス
//

#include <d3d11.h>
#include <SimpleMath.h>
#pragma once

class Camera
{
protected:
	//材料はここに

	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//どこから見るのか（視点
	DirectX::SimpleMath::Vector3 eyepos;
	//どこを見るのか（注視点
	DirectX::SimpleMath::Vector3 refpos;
	//どちらが画面上か（上方向ベクトル
	DirectX::SimpleMath::Vector3 upvec;

	//プロジェクション行列
	DirectX::SimpleMath::Matrix m_proj;
	//垂直方向視野角
	float fovY;
	//アスペクト比
	float aspect;
	//手前の表示限界
	float nearClip;
	//奥の表示限界
	float farClip;

public:
	Camera(int w,int h);
	virtual ~Camera();

	virtual void Update();

	DirectX::SimpleMath::Matrix GetViewMatrix();

	DirectX::SimpleMath::Matrix GetProjMatrix();

	//視点をセット
	void Seteyepos(DirectX::SimpleMath::Vector3& eyepos);

	void Setrefpos(DirectX::SimpleMath::Vector3& refpos);

	void Setupvec(DirectX::SimpleMath::Vector3& upvec);

	void SetfovY(float fovY);

	void Setaspect(float aspect);

	void SetnearClip(float nearclip);

	void SetfarClip(float farclip);

};