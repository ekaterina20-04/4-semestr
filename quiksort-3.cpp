#include <iostream>
#include <algorithm>
using namespace std;

/*Написать программу, сортирующую по возрастанию первый 
столбец двумерного массива целых чисел. Использовать быструю 
сортировку Массив создать из случайных чисел, расположенных 
в интервале {5,61}*/

void quickSort(int arr[][2], int left, int right) {
	if (left < right) {
		int i = left, j = right;

		while (i <= j) {
			while (arr[i][0] < arr[(left + right) / 2][0]) i++;
			while (arr[j][0] > arr[(left + right) / 2][0]) j--;

			if (i <= j) {
				swap(arr[i][0], arr[j][0]);
				swap(arr[i][1], arr[j][1]);
				i++;
				j--;
			}
		}

		quickSort(arr, left, j);
		quickSort(arr, i, right);
	}
}

int main() {
	int arr[10][2];

	for (int i = 0; i < 10; i++) {
		arr[i][0] = rand() % 57 + 5;
		arr[i][1] = i;
	}

	quickSort(arr, 0, 9);

	for (int i = 0; i < 10; i++) {
		cout << arr[i][0] << " ";
	}

	return 0;
}