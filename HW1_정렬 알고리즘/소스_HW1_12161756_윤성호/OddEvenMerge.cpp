#include "Sort.h"											// �Լ� ������ ������ header

// �迭�� �ٽ� ��ġ�� �Լ�
// argument : ������ �迭, top �ε���, data ��, ���� �� ���ڰ� �Ÿ�
void OEmerge(int arr[], int top, int len, int d) {			
	int dd = d * 2;											// �Ÿ��� �� ��
	if (len > dd) {											// �迭 ���̰� 2d���� Ŭ ��
		OEmerge(arr, top, len, dd);							// ¦�� index�� ���� OEmerge ����� ����
		OEmerge(arr, top + d, len, dd);						// Ȧ�� index�� ���� OEmerge ����� ���� 
		for (int i = top + d; d + i < top + len; i += dd)	// ������ �ε����� ������ ������ i�� 2d��ŭ ����
			if (arr[i] > arr[d + i])						// arr[i] < arr[i + d]�� �ǵ��� ��� swap
				swap(&arr[i], &arr[d + i]);
	}

	else													// �迭 ���̰� 2d���� �۰ų� ���� ��
		if (arr[top] > arr[top + d])						// arr[top] < arr[top + d]�� �ǵ��� swap
			swap(&arr[top], &arr[top + d]);
}

void oddEven(int arr[], int top, int len) {					// argument : ������ �迭, top �ε���, data ��
	if (len >= 2) {											// ������ ���� �ּ� 2�� �̻�
		int mid = len / 2;									// �߰� �ε���
		oddEven(arr, top, mid);								// �迭 ������ oddEven ����� ����
		oddEven(arr, top + mid, mid);						// �迭 ������ oddEven ����� ����
		OEmerge(arr, top, len, 1);							// �迭 ��ġ��
	}
}