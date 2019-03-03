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
	double otrezok = (b-a) / 10;
	for (double i = a; i < b; i += otrezok)
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
void addNum(int *&a, int&n, int NN) {

}





void deleteArray(int *&a) {
	delete[] a;
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
			double b = 10;

			coordinates(a, b, fs[0]);
			cout << endl;
			coordinates(a, b, fs[1]);
		}
		break;
		case 2:
		{

		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}