#include "col.h"

//----------------------
//点と四角の当たり判定
//----------------------
bool Collision::CheckHitDotToBox(VECTOR dotPos, VECTOR squarePos, int width, int height) {

	//四角形の上下左右それぞれの座標を計算する
	float up = squarePos.y - height * 0.5f;
	float down = squarePos.y + height * 0.5f;
	float left = squarePos.x - width * 0.5f;
	float right = squarePos.x + width * 0.5f;

	//4つの幅えおそれぞれチェックして、すべての条件を満たしたらヒット
	if (dotPos.x >= left && dotPos.x <= right && dotPos.y >= up && dotPos.y <= down)
	{
		return true;
	}
	else return false;
}
bool Collision::CheckHitBoxToBox(VECTOR pos1, VECTOR size1, VECTOR pos2, VECTOR size2) {

	float up1 = pos1.y - size1.y * 0.5f;
	float down1 = pos1.y + size1.y * 0.5f;
	float left1 = pos1.x - size1.x * 0.5f;
	float right1 = pos1.x + size1.x * 0.5f;
	
	float up2 = pos2.y - size2.y * 0.5f;
	float down2 = pos2.y + size2.y * 0.5f;
	float left2 = pos2.x - size2.x * 0.5f;
	float right2 = pos2.x + size2.x * 0.5f;
	
	if (up1 <= down2 && down1 >= up2 && left1 <= right2 && right1 >= left2) {
		
			return true;
		
		
	}
	else
		return false;
}

bool Collision::CheckHitSphereToSphere(VECTOR SpherePos1, float redius1, VECTOR SpherePos2, float redius2) {

	float lenX = SpherePos1.x - SpherePos2.x;
	lenX *= lenX;

	float lenY = SpherePos1.y - SpherePos2.y;
	lenY *= lenY;

	

	float len = lenX + lenY;

	float totalRadius = redius1 + redius2;
	totalRadius *= totalRadius;

	if (len <= totalRadius) {
		return true;
	}
	else
		return false;
}

