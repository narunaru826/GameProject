#include"MyMath.h"
#include<math.h>
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
