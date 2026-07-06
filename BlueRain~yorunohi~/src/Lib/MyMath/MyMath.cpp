#include"MyMath.h"
#include<math.h>
#include"../Common.h"

//ŠÖ”ˆê——
float WaveMove(float x)
{
	float y = (5 * cosf(x) - cosf(5 * x));

	return y;
}

int Gcd(int a, int b)
{
	if (b == 0)return a;
	return Gcd(b, a % b);
}
float HeartFunc(float x)
{
	return pow(fabs(x), 2.0f / 3.0f) + sqrtf(3.0f - (x * x)) * sinf(16 * DX_PI_F * x);
}

float QuadraticFunc(float x)
{
	float y = x * x;
	return y;
}
int ConvertX(float x,float size)
{
	return WINDOW_SENTER_X - 300 + (int)(x * size);
}
int ConvertY(float y,float size)
{
	return WINDOW_SENTER_Y  - (int)(y * size);
}



