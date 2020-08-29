#ifndef SORT_H	// header�� �ߺ� include ����
#define SORT_H

// bitonic�� main �Լ����� ���� ���� ����
const bool up = true;
const bool down = false;

// main���� ������ swap �Լ��� extern���� ����
extern void swap(int* a, int* b);

// ���� �Լ� ����
void selection(int arr[], int len);
void medianOfThreeQuick(int arr[], int start, int end);
void shell(int arr[], int len);
void bitonic(int arr[], int top, int len, bool updown);
void oddEven(int arr[], int top, int len);

#endif