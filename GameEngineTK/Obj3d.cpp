#include "Obj3d.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//
 Microsoft::WRL::ComPtr<ID3D11Device>            Obj3d::m_d3dDevice;
 Microsoft::WRL::ComPtr<ID3D11DeviceContext>    Obj3d::m_d3dContext;

//カメラ
 Camera* Obj3d::m_camera;

 std::unique_ptr<DirectX::CommonStates> Obj3d::m_states;

 //?
 std::unique_ptr<DirectX::EffectFactory> Obj3d::m_factory;

 void Obj3d::InitielizeStatic(Microsoft::WRL::ComPtr<ID3D11Device> d3dDevice, Microsoft::WRL::ComPtr<ID3D11DeviceContext> d3dContext, Camera *camera)
 {
	 m_d3dDevice = d3dDevice;
	 m_d3dContext = d3dContext;
	 m_camera = camera;

	 m_states = std::make_unique<CommonStates>(m_d3dDevice.Get());

	 m_factory = std::make_unique<EffectFactory>(m_d3dDevice.Get());

	 m_factory->SetDirectory(L"Resources");
 }

 Obj3d::Obj3d()
{
	 //デフォルトは1倍
	 m_scale = Vector3(1, 1, 1);

	 m_worldparent = nullptr;
}

 void Obj3d::LoadModel(const wchar_t * fileName)
 {
	 m_model = Model::CreateFromCMO(m_d3dDevice.Get(), fileName, *m_factory);
 }

void Obj3d::Update()
{
	Matrix scalemat = Matrix::CreateScale(m_scale);

	Matrix rotmatZ = Matrix::CreateRotationZ(m_rotation.z);
	Matrix rotmatX = Matrix::CreateRotationX(m_rotation.x);
	Matrix rotmatY = Matrix::CreateRotationY(m_rotation.y);
	Matrix rotmat = rotmatZ * rotmatX * rotmatY;

	Matrix transmat = Matrix::CreateTranslation(m_translation);

	//ワールド行列を合成
	m_world = scalemat * rotmat * transmat;
	if (m_worldparent)
	{
		m_world *= m_worldparent->m_world;
	}
}

void Obj3d::Draw()
{
	assert(m_camera);
	//モデルの描画
	if (m_model != nullptr)
	{
		m_model->Draw(m_d3dContext.Get(), 
			*m_states,
			m_world, 
			m_camera->GetViewMatrix(),
			m_camera->GetProjMatrix());
	}
}
