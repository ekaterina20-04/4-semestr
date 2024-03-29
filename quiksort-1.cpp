#include <iostream>
#include <algorithm>
using namespace std;

/*Задана последовательность из 1000 целых чисел.
Переставить элементы последовательности таким образом, 
чтобы они располагались в порядке возрастания.*/

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;

	while (i <= j) {
		while (arr[i] < arr[(left + right) / 2]) i++;
		while (arr[j] > arr[(left + right) / 2]) j--;

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

	int arr[1000];

	for (int i = 0; i < 1000; i++) {
		arr[i] = rand() % 1000;
	}

	quickSort(arr, 0, 999);
\
	for (int i = 0; i < 1000; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}