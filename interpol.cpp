// interpol.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

using namespace std;
#include <iostream>

//Булевая глобальная переменная, которая показывает выходит ли x за границу данных значений
bool error = false;
///////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int arraySize(T* arr)
{
	int n=0;
	for (int i=0; arr[i] != '\0'; i++) n++;
	return n;
}
///////////////////////////////////////////////////////////////////////////////////////////

void line()
{
	cout << endl << "##############################################################" << endl;
}

template <class T>
float interpol(T xt, T *arrX, T *arrY)
{
	float x, y, res;
	int i = 0;
	if (xt < arrX[0]) { error = true; return 0; }
	if (xt > arrX[arraySize(arrX) - 1]) { error = true; return 0; }
	while (arrX[i] <= xt)
	{
		i++;
		if (xt == arrX[i])
		{
			i++;
			break;
		}
	}
	i--;
	res = arrY[i] + (((arrY[i + 1] - arrY[i]) / (arrX[i + 1] - arrX[i])) * (xt - arrX[i]));
	return res;
}


//////////////////////////////////////////////////////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "Russian");
	float x, res, arrX[100] = { -2, 4, 6, 8, 12, 18 }, arrY[100] = { 1, 2, 3, -4, 6, 9 }, n = arraySize(arrX);
	int ain;
	while (true) {
		line();
		cout << "1 - Рассчитать значение функции для введённой x;" << endl;
		cout << "2 - Заменить значения таблички по X и Y;" << endl;
		cout << "3 - Проверить значения табличек;" << endl;
		cout << "4 - Выйти." << endl;
		cout << "Введите номер действия (1-4):";
		cin >> ain;
		line();
		switch (ain)
		{
		case 1:
			line();
			cout << "Введите x: ";
			cin >> x;
			res = interpol(x, arrX, arrY);
			if (error == true) cout << "Значение отсутствует на отрезке.";
			else cout << "Результат = " << res;
			line();
			break;
		case 2:
			line();
			cout << "Введите кол-во значений в табличках: ";
			cin >> n;
			cout << "Введите значения для таблички X (в порядке возрастания):";
			for (int i = 0; i < n; i++) cin >> arrX[i];
			cout << "Введите значения для таблички Y (в порядке возрастания):";
			for (int i = 0; i < n; i++) cin >> arrY[i];
			line();
			break;
		case 3:
			line();
			cout << "X: ";
			for (int i = 0; i < n; i++) cout << arrX[i] << "\t";
			cout << endl;
			cout << "Y: ";
			for (int i = 0; i < n; i++) cout << arrY[i] << "\t";
			line();
			break;
		case 4:
			return 0;
		default:
			;
		}
	}
	return 0;
}