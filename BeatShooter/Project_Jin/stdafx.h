// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.

#define WIN_WIDTH 1920
#define WIN_HEIGHT 1080
#define CENTER_X WIN_WIDTH * 0.5f
#define CENTER_Y WIN_HEIGHT * 0.5f
#define WIN_START_X 0
#define WIN_START_Y 0
#define PI 3.141592f
#define COLLSIONSIZE 900.0f * 1.5f


#define TIME TimeManager::GetInstance()
#define DELTATIME TimeManager::GetInstance()->GetElapsedTime()
#define DEVICE Device::GetInstance()->GetDevice()
#define KEY_DOWN(k) InputManager::GetInstance()->KeyDown(k)
#define KEY_UP(k) InputManager::GetInstance()->KeyUp(k)
#define KEY_PRESS(k) InputManager::GetInstance()->KeyPress(k)
#define SOUND SoundManager::Get()
#define XML XmlLoad::GetInstance()
#define EFFECT EffectManager::GetInstance()
#define SCENE SceneManager::GetInstance()
#define GAME_MANAGER GameManager::GetInstance()
#define LERP(s, e, t) {s + (e - s)*t}

#define SAFE_DELETE(p) {if(p){delete (p); (p)=NULL;}}
#define SAFE_DELETE_ARRAY(p) {if(p){delete[] (p); (p)=NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->Release(); (p)=NULL;}}

// Windows 헤더 파일
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>
#include <crtdbg.h>

#ifdef _DEBUG
#define NEW new( _NORMAL_BLOCK, __FILE__, __LINE__)
#else
#define NEW new
#endif

#ifdef _DEBUG

#ifdef UNICODE
#pragma comment(linker, "/entry:wWinMainCRTStartup /subsystem:console")
#else
#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#endif

#define DEBUG_LOG(fmt, ...)\
fprintf(stderr, "[%s:%d]\n%[s()]\n" fmt "\n\n",\
    strrchr("\\" __FILE__, '\\') + 1, __LINE__, __func__, __VA_ARGS__)

#define DEBUG_LOG_I(fmt, ...)\
fprintf(stderr, "[%s:%d]\n[%s:%p]\n[%s()]\n" fmt "\n\n",\
    strrchr("\\" __FILE__, '\\') + 1, __LINE__, typeid(*this).name(), this, __func__, __VA_ARGS__)

#else
#define DEBUG_LOG(fmt, ...)
#define DEBUG_LOG_I(fmt, ...)
#endif

#include <windows.h>

#pragma warning(push, 1)
#pragma warning(disable: 26495)
#include <d3dx9.h>
#pragma warning(pop)

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "winmm.lib")

#include "inc/fmod.hpp"
#pragma comment(lib, "lib/fmodex_vc.lib")

// C 런타임 헤더 파일입니다.
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <vector>
#include <map>
#include <string>
#include <math.h>
#include <mmsystem.h>
#include <functional>
#include <assert.h>

using namespace std;


typedef D3DXVECTOR4 Vector4;
typedef D3DXVECTOR3 Vector3;
typedef D3DXVECTOR2 Vector2;
typedef D3DXMATRIX Matrix;
typedef D3DXCOLOR Color;

#pragma warning(push, 1)
#pragma warning(disable: 26495)
#include "Xml.h"
#pragma warning(pop)

//FrameWork Header File
#include "TimeManager.h"
#include "Math.h"
#include "Device.h"
#include "Vertex.h"
#include "InputManager.h"
#include "SoundManager.h"
#include "Timer.h"
#include "Camera.h"
#include "World.h"
#include "FRect.h"
#include "Shader.h"
#include "RenderTarget.h"
#include "Texture.h"
#include "Animator.h"
#include "Effect.h"
#include "EffectManager.h"
#include "XmlLoad.h"
#include "Scene.h"
#include "SceneManager.h"
#include "MotionTrailer.h"

#include "Utility.h"

//UI
#include "Button.h"

//Scene


//GameObject
#include "GameObject.h"
#include "Enemy.h"
#include "Bullet.h"
#include "BulletManager.h"
#include "Player.h"


//ObjectManager
#include "EnemyManager.h"
#include "GameManager.h"

//Scene
#include "TitleScene.h"
#include "PlayScene.h"
#include "EndScene.h"

//MainGame
#include "MainGame.h"

extern HWND hWnd;
extern D3DXVECTOR2 mousePos;