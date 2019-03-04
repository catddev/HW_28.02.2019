#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 1.	***Напишите 2 функции, каждая из которых принимает вещественный параметр и возвращает вещественное значение.
// Пусть первая функция вычисляет y = x^2, а вторая – y = x * 2 + 4, где x – входной параметр y – возвращаемое значение.
// Затем напишите функцию, которая принимает указатель на одну из этих функций,
// а также диапазон значений(от a до b) и выводит на экран 10 точек(координаты x и y) для этого диапазона.
// Напишите меню, которое иллюстрирует работу этих функций

double func1(double x) {
	double y = x * x;
	return y;
}
double func2(double x) {
	double y = x * 2 + 4;
	return y;
}
void coordinates(double a, double b, double(*f)(double)) {
	if (a > b) swap(a, b);
	double otrezok = (b-a) / (10-1);
	for (double i = a; i <= b; i += otrezok)
	{
		cout << "(" << i << "; " << f(i) << ")" << endl;
	}
}

// 2.	**Написать программу «телефонный справочник».
// Создайте массив целых чисел, каждое число – это номер телефона.
// Напишите функции для добавления нового телефона в массив,
// для удаления указанного телефона из справочника,
// поиск телефона по номеру.
// Создайте меню для пользователя.

void createArray(int *&a, int n) {
	a = new int[n];
}
void fillArray(int * const a, int n) {
	for (int i = 0; i < n; i++)
		a[i] = rand() % 999999 + 100000;
}
void printArray(const int *const a, int n) {
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void deleteArray(int *&a) {
	delete[] a;
}
void addNum(int *&a, int&n, int NN) {
	int *tmp = new int[n + 1];
	for (int i = 0; i < n; i++)
		tmp[i] = a[i];

	tmp[n] = NN;
	delete[] a;
	a = tmp;
	n++;
}
int* searchNum(int *a, int n, int NN) {
	int *tmp = a;
	for (int *p = a; p < a + n; p++)
	{
		if (*p == NN)
		{
		tmp = p;
			// cout << "This number is under the index: " << p - a << endl;
			break;
		}
		else if (p == (a + n - 1))
		{
			cout << "There is no such a number" << endl;
			tmp = nullptr;
		}
	}
	return tmp;
}
void eraseNum(int*&a, int &n, int NN) {
	int *find_p = searchNum(a, n, NN);
	if (find_p == 0) return;
	
	int *tmp = new int[n - 1];
	int *tmp_p = tmp;
	
	for (int *p = a; p < a + n; p++)
	{
		if (*p != NN)
		{
			//*tmp++ = *p; ////this way is an error
			*tmp_p = *p; // but this one works. Why?
			tmp_p++;
		}
	}

	delete[] a;
	a = tmp;
	tmp_p = 0;
	find_p = 0;
	n--;
}


int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			double(*fs[2])(double) = { func1, func2 };
			double a = 0;
			double b = 17.5;

			coordinates(a, b, fs[0]);
			cout << endl;
			coordinates(a, b, fs[1]);
		}
		break;
		case 2: // test
		{
			int *a;
			int n = 5;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			addNum(a, n, 335577);
			printArray(a, n);
			addNum(a, n, 888888);
			printArray(a, n);

			int *b = searchNum(a, n, 335577);
			cout << b << "	" << "This number is under the index: " << b - a << endl;
			b = searchNum(a, n, 123456);
			cout << b << endl << endl;

			eraseNum(a, n, 123456);
			printArray(a, n);

			addNum(a, n, 123456);
			printArray(a, n);

			eraseNum(a, n, 335577);
			printArray(a, n);

			//deleteArray(a); //тоже ошибку выдает
			a = nullptr;
		}
		break;
		case 3: // меню для телефонного справочника
		{

			int *a;
			int n = 0;

			createArray(a, n);
			fillArray(a, n);
			printArray(a, n);

			int choice;
			bool f = true;
			while (f)
			{
				cout << "Выберите действие:" << endl;
				cout << "1 - добавление номера в справочник" << endl;
				cout << "2 - поиск телефона по номеру" << endl;
				cout << "3 - удаление указанного телефона из справочника" << endl;
				cout << "0 - выход" << endl << endl;

				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					addNum(a, n, 335577);
					printArray(a, n);
					addNum(a, n, 888888);
					printArray(a, n);
				}
				break;
				case 2: //error
				{
					int *b = searchNum(a, n, 335577);
					cout << b << "	" << "This number is under the index: " << b - a << endl;
					b = searchNum(a, n, 123456);
					cout << b << endl << endl;
				}
				break;
				case 3://error
				{
					eraseNum(a, n, 123456);
					printArray(a, n);
					eraseNum(a, n, 335577);
					printArray(a, n);
				}
				break;
				case 0:
				{
					f = false;
				}
				break;
				}
				a = nullptr;
			}
		}
			break;
			default:
			cout << "нет такой задачи" << endl << endl;
		}
		}
		system("pause");
		return 0;
	}