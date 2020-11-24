#include "intTrap.h"
using namespace std;
void intTrap::myX()
{
	//cout << "arrX:" << endl;
	for (int i = 0; i < N+1; i++) {
		arrX[i] = a + i * myH();
		//cout << arrX[i] << endl;
	}
}

void intTrap::setF(string x)
{
	int k = 0;
	bool plus = true;
	for (int i = 0; i < x.size(); ) {
		if (x[i] == '-') { plus = false; i++; }
		else if (x[i] == '+') { plus = true; i++; }
		while (x[i] != '+' && x[i] != '-' && x[i] != '*' && x[i] != '/' && x[i] != 'x' && i < x.size() && x[i] != 's' && x[i] != 'c') {
			num1 *= 10;
			num1 += int(x[i]) - 48;
			i++;
		}
		if (x[i] == 's') {
			if (x[i + 1] == 'i')
				if (x[i + 2] == 'n')
					if (x[i + 3] == '(') {
						i += 4;
						while (x[i] != 'x' && x[i] != ')') {
							num1 *= 10;
							num1 += int(x[i]) - 48;
							i++;
						}
						if (x[i] == 'x') {
							if (plus == false) num1 *= -1;
							numsin += num1;
							i++;
						}
						else {
							if (plus == false) num1 *= -1;
							num2 += sin(num1);
						}
					}
			continue;
		}
		if (x[i] == 'c') {
			if (x[i + 1] == 'o')
				if (x[i + 2] == 's')
					if (x[i + 3] == '(') {
						i += 4;
						while (x[i] != 'x' && x[i] != ')') {
							num1 *= 10;
							num1 += int(x[i]) - 48;
							i++;
						}
						if (x[i] == 'x') {
							if (plus == false) num1 *= -1;
							numcos += num1;
							i++;
						}
						else {
							if (plus == false) num1 *= -1;
							num2 += cos(num1);
						}
					}
			continue;
		}
			if (x[i] == 'x') {
				if (plus == false) num1 *= -1;
				numX += num1;
				i++;
			}
			else {
				if (plus == false) num1 *= -1;
				num2 += num1;
			}
			num1 = NULL;
			plus = true;
		}
		//cout << "X: " << numX << " another volume: " << num2;
	}

void intTrap::setY()
{
	//cout << "arrY:" << endl;
	for (int i = 0; i < N + 1; i++) {
		arrY[i] = numX * arrX[i] + num2;
		//cout << arrY[i] << endl;
	}
}

void intTrap::f1(float a1, float b1, float N, string x1)
{
	float rez=0;
	
	setA(a1);
	setB(b1);
	setN(N);
	float h = myH();
	setF(x1);
	myX();
	setY();
	int newN = (int)N;
	float y_last = (arrY[0]+arrY[newN])/2;
	for (int i = 1; i < N; i++) {
		y_last += arrY[i];
	}
	y_last *= h;
	rez = y_last;
	cout << "rez= " << rez;
}