#include <iostream>
using namespace std;

/*Даны два целых числа A и В (каждое в отдельной строке). Выведите все числа от A до B включительно,
в порядке возрастания, если A < B, или в порядке убывания в противном случае*/

void printNumbers(int a, int b) {
	if (a == b) {
		cout << a << endl;
		return;
	}
	if (a < b) {
		cout << a << endl;
		printNumbers(a + 1, b);
	}
	else {
		cout << a << endl;
		printNumbers(a - 1, b);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int a, b;
	cout << "Введите два числа: ";
	cin >> a >> b;

	printNumbers(a, b);

	return 0;
}