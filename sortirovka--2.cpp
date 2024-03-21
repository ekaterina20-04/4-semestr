#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

void choiceShort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int max_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] > arr[max_index]) {
				max_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[max_index];

		arr[max_index] = temp;
	}
}

int main() {
	const int n = 10;
	int arr[n];

	setlocale(LC_ALL, "ru");
	srand(time(0));
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 101;
	}

	cout << "Исходный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	choiceShort(arr, n);

	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}

	return 0;
}