#pragma once
#include <DxLib.h>

class Collision {
public:
	//点と四角の当たり判定
	//dotPos		:	点の座標
	//squarePos		:	四角の中心座標
	//width			:	四角形の横幅
	//height		:	四角形の縦幅
	//@return		:	true=当たった　false=当たってない
	static bool CheckHitDotToBox(VECTOR dotPos, VECTOR squarePos, int width, int height);

	static bool CheckHitBoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2);

	static bool CheckHitSphereToSphere(VECTOR cirelePos1, float redius1, VECTOR cirelePos2, float redius2);
};
