//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibMath.h
//!
//! @brief  DxLib�̐��w�֘A�ւ̒ǉ��@�\�̃w�b�_�t�@�C��
//!
//! @date   2018/7/1
//!
//! @author ���� �W
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// ���d�C���N���[�h�̖h�~ ==================================================
#pragma once




// �w�b�_�t�@�C���̓ǂݍ��� ================================================
#include <minwindef.h>




// �^�̒�` ================================================================

// <2D�̃x�N�g��> ------------------------------------------------------
struct tag_Vector2D
{
	float x;    // X����
	float y;    // Y����
};
typedef struct tag_Vector2D Vector2D;


// <2D�͈̔�> ----------------------------------------------------------
struct tag_Bounds2D
{
	float left;
	float top;
	float right;
	float bottom;
};
typedef struct tag_Bounds2D Bounds2D;


// <��{�`��> ----------------------------------------------------------
// <�_>
typedef Vector2D Point2D;


// <����>
struct tag_Line2D
{
	Point2D  p;    // �����̒ʂ�_
	Vector2D v;    // �����x�N�g��
};
typedef struct tag_Line2D Line2D;


// <����>
struct tag_Segment2D
{
	Point2D  start;    // �n�_
	Point2D  end;      // �I�_
};
typedef struct tag_Segment2D Segment2D;


// <��`>
struct tag_Rect2D
{
	Point2D origin;    // ���㒸�_�̍��W
	float   width;     // ��
	float   height;    // ����
};
typedef struct tag_Rect2D Rect2D;


// <�~�`>
struct tag_Circle2D
{
	Point2D center;    // ���S���W
	float   radius;    // ���a
};
typedef struct tag_Circle2D Circle2D;


// <�O�p�`>
struct tag_Triangle2D
{
	Point2D vertices[3];    // ���_
};
typedef struct tag_Triangle2D Triangle2D;


// <�J�v�Z��>
struct tag_Capsule2D
{
	Segment2D segment;    // ����
	float     radius;     // ���a
};
typedef struct tag_Capsule2D Capsule2D;




// �֐��̐錾 ==============================================================

// <�p�x�̒P�ʕϊ�> ----------------------------------------------------

// [�x]����[���W�A��]�ւ̒P�ʕϊ�
float ToRadians(float degree);

// [���W�A��]����[�x]�ւ̒P�ʕϊ�
float ToDegrees(float radian);



// <���l> --------------------------------------------------------------

// �w�肵���l�������`����͈͓̔��Ɏ��߂�
int   ClampI(int   x, int   min, int   max);
float ClampF(float x, float min, float max);

// ���������_���^�̌덷���l���ɓ��ꂽ��r
BOOL FloatEquals(float a, float b);