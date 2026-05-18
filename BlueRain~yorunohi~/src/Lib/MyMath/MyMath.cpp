#include"MyMath.h"
#include<math.h>
#include"../Common.h"
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

int ConvertX(float x)
{
	return WINDOW_SENTER_X - 300 + (int)(x * 50);
}
int ConvertY(float y)
{
	return WINDOW_SENTER_Y - 300 - (int)(y * 50);
}