#include <iostream>
#include <set>
#include <unordered_set>
using namespace std; 

/*Дана последовательность целых чисел. Каждое прочитанное число обрабатывается следующим образом:
если число больше нуля, оно добавляется к текущему множеству чисел;
если число меньше нуля, противоположное ему число удаляется из текущего множества чисел;
если число равно нулю, множество чисел выводится в порядке возрастания и программа завершает работу.

Формат входного файла
Входной файл содержит последовательность чисел.
Формат выходного файла
Выходной файл должен содержать последовательность чисел, отсортированных по возрастанию. */

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