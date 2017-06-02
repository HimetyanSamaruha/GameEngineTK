/// <summary>
/// 3D�I�u�W�F�N�g�̃N���X
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
	//�ÓI�����o�ϐ��̏�����
	static void InitielizeStatic(
		Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice,
		Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext, 
		Camera* camera);
protected:

	//�f�o�C�X
	static Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
	//�f�o�C�X�e�L�X�g
	static Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;

	//�J����
	static Camera* m_camera;

	//�ėp�X�e�[�g
	static std::unique_ptr<DirectX::CommonStates> m_states;
	
	static std::unique_ptr<DirectX::EffectFactory> m_factory;

	//���f��
	std::unique_ptr<DirectX::Model> m_model;

	//�X�P�[�����O(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_scale;
	//��]�p(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_rotation;
	//���s�ړ�(X,Y,Z)
	DirectX::SimpleMath::Vector3 m_translation;
	//���[���h�s��
	DirectX::SimpleMath::Matrix m_world;

	//�e��3D�I�u�W�F�N�g�̃|�C���^
	Obj3d* m_worldparent;
public:
	//�R���X�g���N�^
	Obj3d();

	//���f�������[�h
	void LoadModel(const wchar_t* fileName);

	//�X�V
	void Update();

	//�`��
	void Draw();

	//�Z�b�g�֐�
	//�X�P�[�����O(X,Y,Z)
	void SetScale(DirectX::SimpleMath::Vector3& scale) { m_scale = scale; }
	//��]�p(X,Y,Z)
	void SetRotation(DirectX::SimpleMath::Vector3& rotation) { m_rotation = rotation; }
	//���s�ړ�(X,Y,Z)
	void SetTranslation(DirectX::SimpleMath::Vector3& translation) { m_translation = translation; }
	void Setparent(Obj3d* parent){	m_worldparent = parent;	}
	void SetWorld(DirectX::SimpleMath::Matrix world) { m_world = world; }

	//�Q�b�g�֐�
	const DirectX::SimpleMath::Vector3& GetSetscale() { return m_scale; }
	const DirectX::SimpleMath::Vector3& GetRotation() { return m_rotation; }
	const DirectX::SimpleMath::Vector3& GetTranslation() { return m_translation; }
	const DirectX::SimpleMath::Matrix& GetWorld() { return m_world; }
	Obj3d* GetParent() { return m_worldparent; }

};