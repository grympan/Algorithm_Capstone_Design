#include "Sort.h"												// �Լ� ������ ������ header

// �迭�� �ٽ� ��ġ�� �Լ�
void BTmerge(int arr[], int top, int len, bool updown) {		// argument : �迭, top �ε���, data ��, ���� ���
	if (len >= 2) {												// �迭�� data�� �� �� �̻��� ���� ����
		int half = len / 2;										// �迭�� ���� ����
		for (int i = top; i < top + half; i++) {				// �迭�� ���� ���� ��ŭ ����
			if (updown == up && arr[i] > arr[i + half])			// ���������� ���, for���� �����
				swap(&arr[i], &arr[i + half]);					// ���ÿ��� a�� A, B�� b.. �� �񱳵Ǹ� �빮�� > �ҹ����̸�
																	// ex [ a B C d | A b c D ] -> [ a b c d | A B C D ]
			else if (updown == down && arr[i] < arr[i + half])	
				swap(&arr[i], &arr[i + half]);					// ���������� ���, for���� �����
		}															// ex [ A b C d | a B c D ] -> [ A B C D | a b c d ]

		BTmerge(arr, top, half, updown);						// �迭�� ������ ���� �յ� ���� BTmerge ����� ���� //
		BTmerge(arr, top + half, half, updown);					//													//
	}
}

void bitonic(int arr[], int top, int len, bool updown) {		// argument : �迭, top �ε���, data ��, ���� ���
	if (len >= 2) {												// �迭�� data�� �� �� �̻��� ���� ����
		int half = len / 2;										// �迭�� ���� ����

		bitonic(arr, top, half, up);							// �迭�� ������ ������ �� ������ �������� ����
		bitonic(arr, top + half, half, down);					// ������ �������� ����
		BTmerge(arr, top, len, updown);							// �迭 ��ġ��
	}
}