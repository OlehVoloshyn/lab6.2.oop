#include "Array.h"
#include <iostream>
#include <time.h>
#include <stdexcept>
#include <exception>
#include <cmath>
using namespace std;

typedef Array::value_type* TArray;
int main()
{
	int n,x;
	cout << "n= "; cin >> n;
	Array c = Array(2 * n);
	srand((unsigned)time(NULL));
	Array::value_type A = -50;
	Array::value_type B = 50;
	Array::TArray a = new Array::value_type[n + 1];
	for (int i = 0; i < 2 * n; i++)
		c[i] = A + rand() % (B - A + 1);

	/*for (int j = 0; j < 2 * n; j++)
		cout << c[j] << " ";
	c = c + 2;*/
	cout << "\n";
	for (int j = 0; j < 2 * n; j++)
		cout << c[j] << " ";
	cout << endl;
	Array d(c);
	

	cout << "x ="; cin >> x; cout << endl;
	for (int j = 0; j < 2 * n; j++)
		cout << c[j] + x << " ";

	cout << endl;
	for (int j = 0; j < 2 * n; j++)
		cout << c[j] - x << " ";

	cout << endl;
	for (int j = 0; j < 2 * n; j++)
		cout << c[j] * x << " ";

	cout << endl;
	for (int j = 0; j < 2 * n; j++)
		cout << c[j] / x << " ";

	cin.get();
	cin.get();
	return 0;
}