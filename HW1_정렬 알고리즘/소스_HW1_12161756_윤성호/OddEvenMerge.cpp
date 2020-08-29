#include "Sort.h"											// 함수 선언을 포함한 header

// 배열을 다시 합치는 함수
// argument : 정렬할 배열, top 인덱스, data 수, 비교할 두 숫자간 거리
void OEmerge(int arr[], int top, int len, int d) {			
	int dd = d * 2;											// 거리의 두 배
	if (len > dd) {											// 배열 길이가 2d보다 클 때
		OEmerge(arr, top, len, dd);							// 짝수 index에 대해 OEmerge 재귀적 실행
		OEmerge(arr, top + d, len, dd);						// 홀수 index에 대해 OEmerge 재귀적 실행 
		for (int i = top + d; d + i < top + len; i += dd)	// 마지막 인덱스에 도달할 때까지 i를 2d만큼 증가
			if (arr[i] > arr[d + i])						// arr[i] < arr[i + d]가 되도록 계속 swap
				swap(&arr[i], &arr[d + i]);
	}

	else													// 배열 길이가 2d보다 작거나 같을 때
		if (arr[top] > arr[top + d])						// arr[top] < arr[top + d]가 되도록 swap
			swap(&arr[top], &arr[top + d]);
}

void oddEven(int arr[], int top, int len) {					// argument : 정렬할 배열, top 인덱스, data 수
	if (len >= 2) {											// 정렬할 수는 최소 2개 이상
		int mid = len / 2;									// 중간 인덱스
		oddEven(arr, top, mid);								// 배열 앞쪽을 oddEven 재귀적 실행
		oddEven(arr, top + mid, mid);						// 배열 뒷쪽을 oddEven 재귀적 실행
		OEmerge(arr, top, len, 1);							// 배열 합치기
	}
}