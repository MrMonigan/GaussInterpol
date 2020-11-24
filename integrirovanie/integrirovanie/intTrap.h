#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <cmath>
class intTrap
{
private:
	float N, h;
	float arrX[100];
	float arrY[100];
	float a, b;

	int num1 = NULL, num2 = NULL, numX = NULL, numsin = NULL, numcos = NULL;
public:
	float myH(){ return (h = (b - a) / N); }
	void myX();
	
	void setA(float a) { this->a = a; }
	void setB(float b) { this->b = b; }
	void setN(float N) { this->N = N; }
	void setF(string x);
	void setY();

	void f1(float a1, float b1, float N, string x1);
};

