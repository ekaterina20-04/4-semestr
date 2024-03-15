#include <iostream>
#include <string>
using namespace std;

void choiceShort(string phones[], int n) {
	for (int i = 0; i < n - 1; i++) {
		int min_index = i;
		for (int j = i + 1; j < n; j++) {
			if (phones[j] < phones[min_index]) {
				min_index = j;
			}
		}

		string temp = phones[i];
		phones[i] = phones[min_index];
		phones[min_index] = temp;
	}
}

int main() {
	setlocale(LC_ALL, "ru");
	int n = 5;
	string phones[] = { "99-00-00", "10-77-77", "10-66-66", "01-22-22", "38-44-55" };

	cout << "Исходный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << phones[i] << " ";
	}
	cout << endl;

	choiceShort(phones, n);

	cout << "\nОтсортированный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << phones[i] << " ";
	}
	cout << endl;

	return 0;
}