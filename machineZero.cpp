// machineZero.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;


template <class T>
T Zero(T c, int &k) {
    do {
        c = c / 10;
        k++;
    }while (c != 0);
    return c;
}


template <class T>
T machine_eps(T e, int& k)
{
    float e1;
    k = 0;

    do {
        e /= 2.0;
        e1 = e + 1.0;
        k++;
    } while (e1 > 1.0);

    return e;
}

int main()
{
    float c1=1423;
    int k = 1;
    int k1 = 1;
    float res = Zero(c1, k);
    cout << "res = " << res << endl;
    cout << "power = " << k * (-1) << endl;
    
    float f_e = machine_eps(1.0F, k1);
    cout << "res = " << f_e << endl;
    cout << "power = " << k1 * (-1);
}
