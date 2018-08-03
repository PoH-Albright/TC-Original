//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/
//! @file   GameLibMath.h
//!
//! @brief  DxLibの数学関連への追加機能のヘッダファイル
//!
//! @date   2018/7/1
//!
//! @author 高木 晋
//__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/__/

// 多重インクルードの防止 ==================================================
#pragma once




// ヘッダファイルの読み込み ================================================
#include <minwindef.h>




// 型の定義 ================================================================

// <2Dのベクトル> ------------------------------------------------------
struct tag_Vector2D
{
	float x;    // X成分
	float y;    // Y成分
};
typedef struct tag_Vector2D Vector2D;


// <2Dの範囲> ----------------------------------------------------------
struct tag_Bounds2D
{
	float left;
	float top;
	float right;
	float bottom;
};
typedef struct tag_Bounds2D Bounds2D;


// <基本形状> ----------------------------------------------------------
// <点>
typedef Vector2D Point2D;


// <直線>
struct tag_Line2D
{
	Point2D  p;    // 直線の通る点
	Vector2D v;    // 方向ベクトル
};
typedef struct tag_Line2D Line2D;


// <線分>
struct tag_Segment2D
{
	Point2D  start;    // 始点
	Point2D  end;      // 終点
};
typedef struct tag_Segment2D Segment2D;


// <矩形>
struct tag_Rect2D
{
	Point2D origin;    // 左上頂点の座標
	float   width;     // 幅
	float   height;    // 高さ
};
typedef struct tag_Rect2D Rect2D;


// <円形>
struct tag_Circle2D
{
	Point2D center;    // 中心座標
	float   radius;    // 半径
};
typedef struct tag_Circle2D Circle2D;


// <三角形>
struct tag_Triangle2D
{
	Point2D vertices[3];    // 頂点
};
typedef struct tag_Triangle2D Triangle2D;


// <カプセル>
struct tag_Capsule2D
{
	Segment2D segment;    // 線分
	float     radius;     // 半径
};
typedef struct tag_Capsule2D Capsule2D;




// 関数の宣言 ==============================================================

// <角度の単位変換> ----------------------------------------------------

// [度]から[ラジアン]への単位変換
float ToRadians(float degree);

// [ラジアン]から[度]への単位変換
float ToDegrees(float radian);



// <数値> --------------------------------------------------------------

// 指定した値を下限～上限の範囲内に収める
int   ClampI(int   x, int   min, int   max);
float ClampF(float x, float min, float max);

// 浮動小数点数型の誤差を考慮に入れた比較
BOOL FloatEquals(float a, float b);