#pragma once
#include "Test.h"
#include <math.h> // include standard math library containing sqrt
#define N 64 // Specify a constant value for array lenght

class TestDist_v1 :
	public Test
{
public:
	TestDist_v1();
	virtual ~TestDist_v1();

	// A scaling function to convert integers 0,1,......,N-1
	// to evenly spaced floats ranging from 0 to 1
	float scale(int i, int n);

	// compute the distance between 2 points on a line
	float distance(float x1, float x2);

	void OnUpdate(float deltaTime) override;
	void OnRender() override;
	void OnImGuiRender() override;
};

