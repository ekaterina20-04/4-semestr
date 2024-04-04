#include <iostream>
#include <set>
#include <unordered_set>
using namespace std; 

int main() {
	setlocale(LC_ALL, "Russian");

	unordered_set<int> numbers;
	cout << "Введите числа через enter: ";

	int num;
	while (cin >> num) {
		if (num > 0) {
			numbers.insert(num);
		}
		else if (num < 0) {
			numbers.erase(-num);
		}
		else {
			set<int> sorted_numbers(numbers.begin(), numbers.end());
			for (int n : sorted_numbers) {
				cout << n << " ";
			}
			break;
		}
	}

	return 0;
}