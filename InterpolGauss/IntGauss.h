#pragma once
#include <iostream>

using namespace std;


class IntGauss
{
private:
	float x=0; //float myX;
	float y=0;
	float q=0;
	float* arrX = new float[5] {10, 15, 20, 25, 30};
	float* arrY = new float[5] {3, 7, 11, 17, 18};
	int h=0;
public:
	IntGauss();
	~IntGauss();
	int GetSize(float* arr);
	int GetCenter(float* arr);

	float myDelta(float* arr, int p, int i);

	float Interpol(float myX, float h, float* arrX, float* arrY);

	float Q(float x, float* arr, int n, float h);

	int H(float *arr);
};

