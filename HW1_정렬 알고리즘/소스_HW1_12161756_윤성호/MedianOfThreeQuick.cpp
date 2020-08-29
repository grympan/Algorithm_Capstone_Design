#include "Sort.h"											// �Լ� ������ ������ header

// 3���� ���� ������������ �����ϴ� �Լ�
void threeSort(int arr[], int start, int mid, int end) {	// arugment : ������ �迭, ó��, �߰�, ������ �ε��� 
	if (arr[start] > arr[end])
		swap(&arr[start], &arr[end]);						// arr[start] < arr[end] ����
	if (arr[start] > arr[mid])
		swap(&arr[start], &arr[mid]);						// arr[start] < arr[mid] ����
	if (arr[mid] > arr[end])
		swap(&arr[mid], &arr[end]);							// arr[mid]   < arr[end] ����
}																// arr[start] < arr[mid] < arr[end] ������ ���� �Ϸ�

void medianOfThreeQuick(int arr[], int start, int end) {	// argument : ������ �迭, ó��, ������ �ε���
	int l, r, pivot;
	int mid = (start + end) / 2;							// �߰� �ε��� ���
	threeSort(arr, start, mid, end);						// 3��(ó��, �߰�, ������) ���� �������� ����
																// (3�� ���ϸ� threeSort������ ���� �Ϸ�)
	if (end - start >= 3) {									// ���� ����� 4�� �̻��� ���� quick sort ����
		pivot = arr[mid];									// �߰� ���� pivot���� ����
		swap(&arr[mid], &arr[end - 1]);						// �߰� ���� <-> [�ڿ��� �� ��° ��] swap
		l = start + 1;										// �� -> �� cursor (threeSort�� ���ĵ� start���� �ǳʶٰ� ����) 
		r = end - 2;										// �� <- �� cursor (end�� pivot�� �ǳʶٰ� ����)

		while (l <= r) {									// �� cursor�� �����ϸ� stop
			while (arr[l] <= pivot && l <= r) l++;			// ��� �̵��ϸ� pivot ���� ū ���� �ְų� �����ϸ� stop
			while (arr[r] >= pivot && l <= r) r--;			// �·� �̵��ϸ� pivot ���� ���� ���� �ְų� �����ϸ� stop
			if (l < r) swap(&arr[l], &arr[r]);				// [Ŀ���� �������� ���� = '�� > ��' �߰�]�̹Ƿ�, �� ���� swap
		}														// < while�� ���� �� �迭 ���¿� Ŀ�� ��ġ >
																//  [ pivot ���� �׷� | pivot �̻� �׷� | pivot | end ]
																//  [				 r l							  ]
		swap(&arr[l], &arr[end - 1]);						// [ ���� �׷� | pivot | �̻� �׷� ] �ϼ�
		medianOfThreeQuick(arr, start, l - 1);				// ���� �׷쿡�� medianThreeQuick ����� ����
		medianOfThreeQuick(arr, l + 1, end);				// �̻� �׷쿡�� medianThreeQuick ����� ����
	}
}