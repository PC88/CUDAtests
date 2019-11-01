#pragma once
#include "Test.h"
#include <math.h>
#include <stdlib.h>
#define N 20000000

class TestDist_v2 :
	public Test
{
public:
	TestDist_v2();
	virtual ~TestDist_v2();

	// A scaling function to convert integers 0,1,......,N-1
	// to evenly spaced floats ranging from 0 to 1
	float scale(int i, int n);

	// compute the distance between 2 points on a line
	float distance(float x1, float x2);

	void distanceArray(float* out, float* in, float ref, int n);

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
};

