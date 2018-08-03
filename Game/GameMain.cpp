//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameMain.cpp
//!
//! @brief  �Q�[���֘A�̃\�[�X�t�@�C��
//!
//! @date   0218/08/03 �`
//!
//! @author �v�ۓc �x
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include "GameMain.h"

#include <assert.h>

#include "SceneLogo.h"
#include "ScenePlay.h"
#include "SceneResult.h"
#include "SceneTitle.h"




// �O���[�o���ϐ��̒�` ====================================================
int g_input_state;

// �V�[���J�ڂ̏��
SceneID g_active_scene;		// ���݂̃V�[��
SceneID g_next_scene;		// ���ɗ���V�[��



							// �֐��̐錾 ==============================================================
void InitializeGame(void);  // �Q�[���̏���������
void UpdateGame(void);      // �Q�[���̍X�V����
void RenderGame(void);      // �Q�[���̕`�揈��
void FinalizeGame(void);    // �Q�[���̏I������


void InitializeScene(SceneID sceneID);		// �V�[�����Ƃ̏���������
void UpdateScene(SceneID sceneID);			// �V�[�����Ƃ̍X�V����
void RenderScene(SceneID sceneID);			// �V�[�����Ƃ̕`�揈��
void FinalizeScene(SceneID sceneID);		// �V�[�����Ƃ̏I������

void RequestScene(SceneID sceneID);			// ���̃V�[����v��



											// �֐��̒�` ==============================================================
											//----------------------------------------------------------------------
											//! @brief �Q�[���̏���������
											//!
											//! @param[in] �Ȃ�
											//!
											//! @return �Ȃ�
											//----------------------------------------------------------------------
void InitializeGame(void)
{

	g_active_scene = SCENE_NONE;
	g_next_scene = SCENE_LOGO;

}



//----------------------------------------------------------------------
//! @brief �Q�[���̍X�V����
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void UpdateGame(void)
{
	// �L�[����
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
//! @brief �Q�[���̕`�揈��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RenderGame(void)
{
	RenderScene(g_active_scene);
}



//----------------------------------------------------------------------
//! @brief �Q�[���̏I������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void FinalizeGame(void)
{
	FinalizeScene(g_active_scene);
}






//----------------------------------------------------------------------
//! @brief ���������� �V�[������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief �X�V���� �V�[������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief �`�揈�� �V�[������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief �I������ �V�[������
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
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
//! @brief ���̃V�[����v��
//!
//! @param[in] �Ȃ�
//!
//! @return �Ȃ�
//----------------------------------------------------------------------
void RequestScene(SceneID scene_ID)
{
	g_next_scene = scene_ID;
}