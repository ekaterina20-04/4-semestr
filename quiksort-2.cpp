#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

/*Написать программу, сортирующую по возрастанию
одномерный массив случайных целых чисел, находящихся 
в интервале {50,100}. Использовать быструю сортировку*/

void quickSort(int arr[], int left, int right) {
	int i = left, j = right;
	int tmp;

	while (i <= j) {
		while (arr[i] < arr[(left + right) / 2])
			i++;
		while (arr[j] > arr[(left + right) / 2])
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main() {
	const int size = 10;
	int arr[size];

	setlocale(LC_ALL, "ru");
	srand(time(0));
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 51 + 50; 
	}

	cout << "Исходный массив:\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	quickSort(arr, 0, size - 1);

	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}