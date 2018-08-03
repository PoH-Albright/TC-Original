//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  ゲーム関連のソースファイル
//!
//! @date   0218/08/03 ～
//!
//! @author 久保田 諄
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ヘッダファイルの読み込み ================================================
#include "GameMain.h"

#include <assert.h>

#include "SceneLogo.h"
#include "ScenePlay.h"
#include "SceneResult.h"
#include "SceneTitle.h"




// グローバル変数の定義 ====================================================
int g_input_state;

// シーン遷移の状態
SceneID g_active_scene;		// 現在のシーン
SceneID g_next_scene;		// 次に来るシーン



							// 関数の宣言 ==============================================================
void InitializeGame(void);  // ゲームの初期化処理
void UpdateGame(void);      // ゲームの更新処理
void RenderGame(void);      // ゲームの描画処理
void FinalizeGame(void);    // ゲームの終了処理


void InitializeScene(SceneID sceneID);		// シーンごとの初期化処理
void UpdateScene(SceneID sceneID);			// シーンごとの更新処理
void RenderScene(SceneID sceneID);			// シーンごとの描画処理
void FinalizeScene(SceneID sceneID);		// シーンごとの終了処理

void RequestScene(SceneID sceneID);			// 次のシーンを要求



											// 関数の定義 ==============================================================
											//----------------------------------------------------------------------
											//! @brief ゲームの初期化処理
											//!
											//! @param[in] なし
											//!
											//! @return なし
											//----------------------------------------------------------------------
void InitializeGame(void)
{

	g_active_scene = SCENE_NONE;
	g_next_scene = SCENE_LOGO;

}



//----------------------------------------------------------------------
//! @brief ゲームの更新処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateGame(void)
{
	// キー入力
	g_input_state = GetJoypadInputState(DX_INPUT_KEY_PAD1);

	if (g_next_scene != SCENE_NONE)
	{
		FinalizeScene(g_active_scene);
		InitializeScene(g_next_scene);

		g_active_scene = g_next_scene;
		g_next_scene = SCENE_NONE;
	}

	UpdateScene(g_active_scene);
}



//----------------------------------------------------------------------
//! @brief ゲームの描画処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderGame(void)
{
	RenderScene(g_active_scene);
}



//----------------------------------------------------------------------
//! @brief ゲームの終了処理
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	FinalizeScene(g_active_scene);
}






//----------------------------------------------------------------------
//! @brief 初期化処理 シーンごと
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void InitializeScene(SceneID scene_ID)
{
	switch (scene_ID)
	{
	case SCENE_NONE:
		break;

	case SCENE_LOGO:
		InitializeLogo();
		break;

	case SCENE_TITLE:
		InitializeTitle();
		break;

	case SCENE_PLAY:
		InitializePlay();
		break;

	case SCENE_RESULT:
		InitializeResult();
		break;

	default:
		assert(FALSE);
	}
}



//----------------------------------------------------------------------
//! @brief 更新処理 シーンごと
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void UpdateScene(SceneID scene_ID)
{
	switch (scene_ID)
	{
	case SCENE_NONE:
		break;

	case SCENE_LOGO:
		UpdateLogo();
		break;

	case SCENE_TITLE:
		UpdateTitle();
		break;

	case SCENE_PLAY:
		UpdatePlay();
		break;

	case SCENE_RESULT:
		UpdateResult();
		break;

	default:
		assert(FALSE);
	}
}



//----------------------------------------------------------------------
//! @brief 描画処理 シーンごと
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RenderScene(SceneID scene_ID)
{
	switch (scene_ID)
	{
	case SCENE_NONE:
		break;

	case SCENE_LOGO:
		RenderLogo();
		break;

	case SCENE_TITLE:
		RenderTitle();
		break;

	case SCENE_PLAY:
		RenderPlay();
		break;

	case SCENE_RESULT:
		RenderResult();
		break;

	default:
		assert(FALSE);
	}
}



//----------------------------------------------------------------------
//! @brief 終了処理 シーンごと
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void FinalizeScene(SceneID scene_ID)
{
	switch (scene_ID)
	{
	case SCENE_NONE:
		break;

	case SCENE_LOGO:
		FinalizeLogo();
		break;

	case SCENE_TITLE:
		FinalizeTitle();
		break;

	case SCENE_PLAY:
		FinalizePlay();
		break;

	case SCENE_RESULT:
		FinalizeResult();
		break;

	default:
		assert(FALSE);
	}
}



//----------------------------------------------------------------------
//! @brief 次のシーンを要求
//!
//! @param[in] なし
//!
//! @return なし
//----------------------------------------------------------------------
void RequestScene(SceneID scene_ID)
{
	g_next_scene = scene_ID;
}