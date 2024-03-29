#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib> // для функции rand
#include <ctime>   // для функции time
using namespace std;

//Написать программу, сортирующую список студентов группы по алфавиту и использующую стандартную сортировку qsort

void quickSort(string arr[], int left, int right) {
	int i = left, j = right;

	while (i <= j) {
		while (arr[i].compare(arr[(left + right) / 2]) < 0) i++;
		while (arr[j].compare(arr[(left + right) / 2]) > 0) j--;

		if (i <= j) {
			swap(arr[i], arr[j]);
			i++;
			j--;
		}
	}

	if (left < j) quickSort(arr, left, j);
	if (i < right) quickSort(arr, i, right);
}

int main() {
	setlocale(LC_ALL, "ru");
	srand(time(0));

	string arr[1000];

	// Заполнение массива случайными строками
	for (int i = 0; i < 1000; i++) {
		// Создаем случайную строку длиной от 1 до 10 символов
		int length = rand() % 10 + 5;
		string randomString;
		for (int j = 0; j < length; j++) {
			randomString += 'a' + rand() % 26; // случайная маленькая буква английского алфавита
		}
		arr[i] = randomString;
	}

	quickSort(arr, 0, 999);

	// Вывод отсортированных имен
	for (int i = 0; i < 1000; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}