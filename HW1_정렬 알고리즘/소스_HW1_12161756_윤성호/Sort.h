#ifndef SORT_H	// header의 중복 include 방지
#define SORT_H

// bitonic과 main 함수에서 사용될 변수 선언
const bool up = true;
const bool down = false;

// main에서 구현할 swap 함수를 extern으로 선언
extern void swap(int* a, int* b);

// 정렬 함수 선언
void selection(int arr[], int len);
void medianOfThreeQuick(int arr[], int start, int end);
void shell(int arr[], int len);
void bitonic(int arr[], int top, int len, bool updown);
void oddEven(int arr[], int top, int len);

#endif