#include <iostream>
using namespace std;

void heapify(int array[], int len, int x) {
    int largest = x;
    int left = 2 * x + 1;
    int right = 2 * x + 2;

    if (left < len && array[left] > array[largest])
        largest = left;

    if (right < len && array[right] > array[largest])
        largest = right;

    if (largest != x) {
        swap(array[x], array[largest]);
        heapify(array, len, largest);
    }
}

void heapSort(int array[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(array, len, i);

    for (int i = len - 1; i >= 0; i--) {
        swap(array[0], array[i]);
        heapify(array, i, 0);
    }
}

void printheap(int array[], int len) {
    for (int i = 0; i < len; i++) {
        cout << array[i] << endl;
        array[i] = 99999999;
    }
}

int main() {
    int array[100];
    int input = 0;
    int len = 0;

    for (;;) {
        cin >> input;
        if (input == 0) break;
        else if (input >= 1 && input <= 20) {
            heapSort(array, len);
            printheap(array, input);
        }
        else if (input >= 20200101) {
            array[len] = input;
            len++;
        }
    }

    return 0;
}