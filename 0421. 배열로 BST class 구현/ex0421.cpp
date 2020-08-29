#include <iostream>
using namespace std;

class arrayBST {
public:
	int* arr;

	arrayBST(int root = 0) {
		arr = new int[256];
		for (int i = 0; i < 256; i++)
			arr[i] = 0;

		arr[1] = root;
	}

	int search(int val) {
		for (int i = 1; i <= 255; i++)
			if (arr[i] == val)
				return i;
		return 0;
	}

	void insertion(int ind, int val) {
		if (arr[ind] != 0) {
			if (val < arr[ind])
				return insertion(ind * 2, val);

			else if (val > arr[ind])
				return insertion(ind * 2 + 1, val);
		}
		else
			arr[ind] = val;
	}

	void deletion(int val) {
		val = val * (-1);
		if (search(val) == 0)
			cout << 0 << endl;

		else {
			cout << arr[search(val)] << endl;
			arr[search(val)] = 0;
		}
	}

	void printArray() {
		for (int i = 1; i <= 255; i++)
			if (arr[i] != 0)
				cout << arr[i] << " ";
	}

	~arrayBST() {
		delete[] arr;
	}
};

int main() {
	int root = 0;
	int val = 0;

	cin >> root;
	arrayBST exArr(root);

	for (;;) {
		cin >> val;
		if (val > 0)
			exArr.insertion(1, val);
		else if (val < 0)
			exArr.deletion(val);
		else
			break;
	}
	exArr.printArray();
}