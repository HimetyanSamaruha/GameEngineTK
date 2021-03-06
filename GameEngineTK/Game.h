//
// Game.h
//

#pragma once

#include "StepTimer.h"

#include <PrimitiveBatch.h>
#include <VertexTypes.h>
#include <Effects.h>

#include <CommonStates.h>

#include <SimpleMath.h>

#include "DebugCamera.h"

#include <Model.h>

#include <Keyboard.h>

#include "Camera.h"
#include "FollowCamera.h"
#include "Obj3d.h"

#include "Player.h"

#include <vector>

// A basic game implementation that creates a D3D11 device and
// provides a game loop.
class Game
{
public:

	/*enum PLAYER_PARTS
	{
		PLAYER_PARTS_LEG,
		PLAYER_PARTS_BODY,
		PLAYER_PARTS_GUN1,
		PLAYER_PARTS_GUN2,
		PLAYER_PARTS_GUN3,
		PLAYER_PARTS_GUN4,
		PLAYER_PARTS_GIA,
		PLAYER_PARTS_NUM,
	};*/


    Game();

    // Initialization and management
    void Initialize(HWND window, int width, int height);

    // Basic game loop
    void Tick();

    // Messages
    void OnActivated();
    void OnDeactivated();
    void OnSuspending();
    void OnResuming();
    void OnWindowSizeChanged(int width, int height);

    // Properties
    void GetDefaultSize( int& width, int& height ) const;

private:

    void Update(DX::StepTimer const& timer);
    void Render();

    void Clear();
    void Present();

    void CreateDevice();
    void CreateResources();

    void OnDeviceLost();

    // Device resources.
    HWND                                            m_window;
    int                                             m_outputWidth;
    int                                             m_outputHeight;

    D3D_FEATURE_LEVEL                               m_featureLevel;
    Microsoft::WRL::ComPtr<ID3D11Device>            m_d3dDevice;
    Microsoft::WRL::ComPtr<ID3D11Device1>           m_d3dDevice1;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext>     m_d3dContext;
    Microsoft::WRL::ComPtr<ID3D11DeviceContext1>    m_d3dContext1;

    Microsoft::WRL::ComPtr<IDXGISwapChain>          m_swapChain;
    Microsoft::WRL::ComPtr<IDXGISwapChain1>         m_swapChain1;
    Microsoft::WRL::ComPtr<ID3D11RenderTargetView>  m_renderTargetView;
    Microsoft::WRL::ComPtr<ID3D11DepthStencilView>  m_depthStencilView;

    // Rendering loop timer.
    DX::StepTimer                                   m_timer;

	std::unique_ptr<DirectX::BasicEffect> m_effect;
	//VertexPositionColor
	std::unique_ptr<DirectX::PrimitiveBatch<DirectX::VertexPositionNormal>> m_batch;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> m_inputLayout;

	DirectX::SimpleMath::Matrix m_world;
	DirectX::SimpleMath::Matrix m_view;
	DirectX::SimpleMath::Matrix m_proj;
	//デバッグカメラ
	std::unique_ptr<DebugCamera> m_debugcamera;
	//エフェクトファクトリ
	std::unique_ptr<DirectX::EffectFactory> m_factory;
	//モデル
	std::unique_ptr<DirectX::Model> m_modelground;
	//モデル
	Obj3d m_obj3SkyDome;
	//ボール
	std::unique_ptr<DirectX::Model> m_ball;

	//タンクモデル
	std::unique_ptr<DirectX::Model> m_tank;

	//球ワールド行列
	DirectX::SimpleMath::Matrix m_worlball;

	//ワールド行列配列
	DirectX::SimpleMath::Matrix m_world2;
	//キーボード
	std::unique_ptr<DirectX::Keyboard> keyboard;

	//タンク
	DirectX::SimpleMath::Vector3 tank_pos;

	//自機のワールド行列
	DirectX::SimpleMath::Matrix m_tank_wrold;
	//自機のワールド行列
	DirectX::SimpleMath::Matrix m_tank_wrold2;

	std::unique_ptr<Player> m_Player;
	
	float tank_rot;

	float rot;
	float scl;

	//カメラクラスの定義
	std::unique_ptr<FollowCamera> m_camera;

	DirectX::SimpleMath::Vector3 Eyepos;
	DirectX::SimpleMath::Vector3 Refpos;
};