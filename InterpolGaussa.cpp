// InterpolGaussa.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//



#include <iostream>
#include "IntGauss.h"

using namespace std;

int main()
{
    IntGauss func, func2;
    float arrX[6]  = {10, 15, 20, 25, 30};
    float arrY[6] = { 3, 7, 11, 17, 18 };
    
    float arrX3[6] = { 0.25, 0.30, 0.35, 0.40, 0.45 };
    float arrY3[6];
    for (int i = 0; i < 5; i++) {
        arrY3[i] = arrX3[i]*arrX3[i]*arrX3[i];
    }
    cout << "1.Resultat is " << func.Interpol(19, 5, arrX, arrY);
    cout << endl << "2.Resultat is " << func2.Interpol(0.34, 0.05, arrX3, arrY3);
    return 0;
}
