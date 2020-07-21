#include "TestDist_v2.h"



TestDist_v2::TestDist_v2()
{
	float* in = (float*)calloc(N, sizeof(float));
	float* out = (float*)calloc(N, sizeof(float));
	const float ref = 0.5f;

	for (int i = 0; i < N; ++i)
	{
		in[i] = scale(i, N);
	}

	distanceArray(out, in, ref, N);

	// release the heap memory after we are done using it
	free(in);
	free(out);
}

TestDist_v2::~TestDist_v2()
{

}

float TestDist_v2::scale(int i, int n)
{
	return ((float)i) / (n - 1);
}

float TestDist_v2::distance(float x1, float x2)
{
	return sqrt((x2 - x1) * (x2 - x1));
}

void TestDist_v2::distanceArray(float* out, float* in, float ref, int n)
{
	for (int i = 0; i < n; ++i)
	{
		out[i] = distance(in[i], ref);
	}
}

void TestDist_v2::OnUpdate(float deltaTime)
{
}

void TestDist_v2::OnRender()
{

}

void TestDist_v2::OnImGuiRender()
{

}
