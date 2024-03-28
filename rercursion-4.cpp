#include <iostream>
using namespace std;

/*Дано натуральное число n > 1. Выведите все простые делители этого 
числа в порядке возрастания.*/

void PrimeDivisors(int n, int divisor) {
	if (n % divisor == 0) {
		cout << divisor << " ";
		while (n % divisor == 0) {
			n /= divisor;
		}
	}

	PrimeDivisors(n, divisor + 1);
}

int main() {
	setlocale(LC_ALL, "Russian");

	int n;
	cout << "Введите число: ";
	cin >> n;

	cout << "простые делители числа " << n << " это: ";
	PrimeDivisors(n, 2);

	return 0;
}