#include "Sort.h"							// �Լ� ������ ������ header

void selection(int arr[], int len) {		// argument : ������ �迭, ������ data ��(n)
	int min = 0;							// �ּڰ��� index
	for (int i = 0; i < len; i++) {			// �迭 ĭ ����ŭ looping
		min = i;							// ���� �ε���(i)�� �ּڰ����� ����

		for (int j = i + 1; j < len; j++)	// i ������ ��� �ε��� scan (j ~ len-1)
			if (arr[j] < arr[min])			// ������ �ִ� �ε���(j)�� �ִ� ���� i�� �ִ� ������ ���� ���,
				min = j;					// �ش� �ε���(j)�� �ּڰ�����
												// for���� ���� �� min : i �������� ���� ���� ��
		swap(&arr[i], &arr[min]);			// ���� �ε����� ���� ������ ���� ���� ���� swap
	}											// cycle �� �迭 ��Ȳ
}												// 1cycle : [ min | ..........				       ]
												// 2cycle : [ min | 2nd min | ..........		   ]
												// 3cycle : [ min | 2nd min | 3rd min | .......... ]
												// (�ݺ�)
												// for���� ���� �� �������� ���� �ϼ�