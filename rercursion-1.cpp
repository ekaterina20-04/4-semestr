#include <iostream>
using namespace std;

void printNumbers(int n) {
	if (n > 0) {
		printNumbers(n - 1);
		cout << n << " ";
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите число: ";
	cin >> n;

	printNumbers(n);

	return 0;
}