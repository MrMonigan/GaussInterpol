#include <iostream>
#include "IntGauss.h"
using namespace std;

IntGauss::IntGauss()
{
}
IntGauss::~IntGauss()
{
}

int IntGauss::GetCenter(float* arr){
	int n = 0;
	if (GetSize(arr) % 2 == 0) return n = (GetSize(arr) / 2);
	else return n = (GetSize(arr) / 2);
}

float IntGauss::myDelta(float* arr, int p, int i)
{
	int i1 = i, p2 = p;
	float arrTMP[100];
	int count = 1;
	int n = GetSize(arr);
	for (int c = 0; c < n; c++){
		arrTMP[c] = arr[c];
	}
	do{
		for (int c = 0; c < n - 1; c++){
			arrTMP[c] = arrTMP[c + 1] - arrTMP[c];
		}
		if (count == p) {
			return arrTMP[i1];
		}
		count++;
		p2--; n--;
	} while (p2 > 0);
}

float IntGauss::Interpol(float myX, float* arrX, float* arrY)
{
	int n = GetCenter(arrX);
	float p;
	float h = H(arrX);
	q = Q(myX, arrX, n, h);
	p = arrY[n]+ (q * myDelta(arrY, 1, n - 1)) + ((q * ((q + 1) / 2)) * myDelta(arrY, 2, n - 2));
	return p;
}

inline int IntGauss::GetSize(float* arr)
{
	int size = 0;
	for (int i = 0; arr[i] != '\0'; i++) 
		size++;
	return size;
}

float IntGauss::Q(float x, float* arr, int n, int h)
{
	float q = (x - arr[n]) / h;
	return q;
}

int IntGauss::H(float* arr)
{
	int i = 0;
	while (arr[i + 1])
	{
		h = arr[i+1] - arr[i];
		i++;
	}
	return h;
}
