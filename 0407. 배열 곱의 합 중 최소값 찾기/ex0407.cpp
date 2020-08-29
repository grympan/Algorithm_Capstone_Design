#include <iostream>
using namespace std;

int main() {
	int size = 0;
	cin >> size;

	int* a = new int[size];
	int* b = new int[size];
	
	for (int i = 0; i < size; i++)
		cin >> a[i];

	for (int i = 0; i < size; i++)
		cin >> b[i];

	int smallest = 0;
	int temp = 0;

	for (int i = 0; i < size; i++) {
		smallest = i;
		for (int j = i + 1; j < size; j++)
			if (a[j] < a[smallest])
				smallest = j;

		temp = a[i];
		a[i] = a[smallest];
		a[smallest] = temp;
	}

	for (int i = 0; i < size; i++)
		cout << a[i] << " ";

	cout << endl;
	for (int i = 0; i < size; i++) {
		smallest = i;
		for (int j = i + 1; j < size; j++)
			if (b[j] < b[smallest])
				smallest = j;

		temp = b[i];
		b[i] = b[smallest];
		b[smallest] = temp;
	}

	for (int i = 0; i < size; i++)
		cout << b[i] << " ";
	cout << endl;

	int result = 0;
	for (int i = 0; i < size; i++)
		result += a[i] * b[size - 1 - i];
	cout << result;
	
	return 0;

}