/// <summary>
/// 3Dオブジェクトのクラス
/// </summary>
#pragma once

#include <Windows.h>
#include <wrl/client.h>
#include <d3d10_1.h>

#include "Camera.h"
#include <Effects.h>
#include <CommonStates.h>
#include <SimpleMath.h>
#include <Model.h>

class Obj3d
{
public:
	//静的メンバ変数の初期化
	static void InitielizeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext, 
		Camera* camera);
protected:

	//デバイス
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	//デバイステキスト
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;

	//カメラ
	static Camera* m_camera;

	//汎用ステート
	static std::unique_ptr<DirectX::CommonStates> m_states;
	
	static std::unique_ptr<DirectX::EffectFactory> m_factory;

	//モデル
	std::unique_ptr<DirectX::Model> m_model;

	//スケーリング(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_scale;
	//回転角(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_rotation;
	//平行移動(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_translation;
	//ワールド行列
	DirectX::SimpleMath::Matrix m_world;

	//親の3Dオブジェクトのポインタ
	Obj3d* m_worldparent;
public:
	//コンストラクタ
	Obj3d();

	//モデルをロード
	void LoadModel(const wchar_t* fileName);

	//更新
	void Update();

	//描画
	void Draw();

	//セット関数
	//スケーリング(X,Y,Z)
	void SetScale(DirectX::SimpleMath::Vector3& scale) { m_scale = scale; }
	//回転角(X,Y,Z)
	void SetRotation(DirectX::SimpleMath::Vector3& rotation) { m_rotation = rotation; }
	//平行移動(X,Y,Z)
	void SetTranslation(DirectX::SimpleMath::Vector3& translation) { m_translation = translation; }
	void Setparent(Obj3d* parent){	m_worldparent = parent;	}
	void SetWorld(DirectX::SimpleMath::Matrix world) { m_world = world; }

	//ゲット関数
	const DirectX::SimpleMath::Vector3& GetSetscale() { return m_scale; }
	const DirectX::SimpleMath::Vector3& GetRotation() { return m_rotation; }
	const DirectX::SimpleMath::Vector3& GetTranslation() { return m_translation; }
	const DirectX::SimpleMath::Matrix& GetWorld() { return m_world; }
	Obj3d* GetParent() { return m_worldparent; }

};