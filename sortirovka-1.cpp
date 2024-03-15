#include <iostream>
#include <ctime>

using namespace std;

void choiceShort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (arr[j] < arr[min_index]) {
				min_index = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[min_index];

		arr[min_index] = temp;
	}
}

int main() {

	setlocale(LC_ALL, "ru");
	srand(time(0));

	const int n = 10;
	int arr[n];

	// Заполнение массива случайными числами
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 102 + 2;
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