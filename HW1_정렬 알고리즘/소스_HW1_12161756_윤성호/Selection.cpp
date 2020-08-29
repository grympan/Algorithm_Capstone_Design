#include "Sort.h"							// 함수 선언을 포함한 header

void selection(int arr[], int len) {		// argument : 정렬할 배열, 정렬할 data 수(n)
	int min = 0;							// 최솟값의 index
	for (int i = 0; i < len; i++) {			// 배열 칸 수만큼 looping
		min = i;							// 현재 인덱스(i)를 최솟값으로 가정

		for (int j = i + 1; j < len; j++)	// i 우측의 모든 인덱스 scan (j ~ len-1)
			if (arr[j] < arr[min])			// 우측에 있는 인덱스(j)에 있는 값이 i에 있는 값보다 작은 경우,
				min = j;					// 해당 인덱스(j)를 최솟값으로
												// for루프 종료 후 min : i 우측에서 가장 작은 값
		swap(&arr[i], &arr[min]);			// 현재 인덱스의 값과 우측의 가장 작은 값을 swap
	}											// cycle 별 배열 상황
}												// 1cycle : [ min | ..........				       ]
												// 2cycle : [ min | 2nd min | ..........		   ]
												// 3cycle : [ min | 2nd min | 3rd min | .......... ]
												// (반복)
												// for루프 종료 시 오름차순 정렬 완성