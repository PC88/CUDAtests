#include "TestDist_v1.h"



TestDist_v1::TestDist_v1()
{
}


TestDist_v1::~TestDist_v1()
{

}


float TestDist_v1::scale(int i, int n)
{
	return ((float)i) / (n - 1);
}

float TestDist_v1::distance(float x1, float x2)
{
	return sqrt((x2 - x1) * (x2 - x1));
}

void TestDist_v1::OnUpdate(float deltaTime)
{
	// Create an array pf N floats (initialized to 0.0)
	// We will overwrite these values to store our results.
	float out[N] = { 0.0f };

	// Choose a reference value from which distances are measured.
	float ref = 0.5f;

	// for loop to scale the index to obtain coordinate value,
	// compute the distance from the reference point,
	// and store the result in the corresponding entry of out
	for (int i = 0; i < N; ++i)
	{
		float x = scale(i, N);
		out[i] = distance(x, ref);
	}
}

void TestDist_v1::OnRender()
{

}

void TestDist_v1::OnImGuiRender()
{

}
