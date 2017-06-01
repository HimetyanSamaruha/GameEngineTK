//
//	制作日	2017/05/11
//
//	作成者	ToshikiIchioka
//
//	用途	カメラを制御するクラス
//

#include <d3d11_1.h>
#include <SimpleMath.h>
#pragma once

class Camera
{
protected:
	//材料はここに

	//ビュー行列
	DirectX::SimpleMath::Matrix m_view;
	//どこから見るのか（視点
	DirectX::SimpleMath::Vector3 m_eyepos;
	//どこを見るのか（注視点
	DirectX::SimpleMath::Vector3 m_refpos;
	//どちらが画面上か（上方向ベクトル
	DirectX::SimpleMath::Vector3 m_upvec;

	//プロジェクション行列
	DirectX::SimpleMath::Matrix m_proj;
	//垂直方向視野角
	float m_fovY;
	//アスペクト比
	float m_aspect;
	//手前の表示限界
	float m_nearClip;
	//奥の表示限界
	float m_farClip;

public:
	Camera(int w,int h);
	virtual ~Camera();

	virtual void Update();

	const DirectX::SimpleMath::Matrix& GetViewMatrix();

	const DirectX::SimpleMath::Matrix& GetProjMatrix();

	//視点をセット
	void Seteyepos(const DirectX::SimpleMath::Vector3& eyepos);

	void Setrefpos(const DirectX::SimpleMath::Vector3& refpos);

	void Setupvec(const DirectX::SimpleMath::Vector3& upvec);

	void SetfovY(float fovY);

	void Setaspect(float aspect);

	void SetnearClip(float nearclip);

	void SetfarClip(float farclip);

};