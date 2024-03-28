#include<iostream>
using namespace std;

/*Дано натуральное число N. Вычислите сумму его цифр. 
При решении этой задачи нельзя использовать строки, списки,
массивы (ну и циклы, разумеется).*/

int Sum(int n) {
	if (n < 10) {
		return n;
	}
	else {
		return n % 10 + Sum(n / 10);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число: ";
	cin >> n;

	cout << "Сумма цифр числа " << n << " равна: " << Sum(n) << endl;

	return 0;
}

