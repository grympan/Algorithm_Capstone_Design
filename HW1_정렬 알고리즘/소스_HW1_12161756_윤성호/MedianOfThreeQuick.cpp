#include "Sort.h"											// 함수 선언을 포함한 header

// 3개의 값을 오름차순으로 정렬하는 함수
void threeSort(int arr[], int start, int mid, int end) {	// arugment : 정렬할 배열, 처음, 중간, 마지막 인덱스 
	if (arr[start] > arr[end])
		swap(&arr[start], &arr[end]);						// arr[start] < arr[end] 정렬
	if (arr[start] > arr[mid])
		swap(&arr[start], &arr[mid]);						// arr[start] < arr[mid] 정렬
	if (arr[mid] > arr[end])
		swap(&arr[mid], &arr[end]);							// arr[mid]   < arr[end] 정렬
}																// arr[start] < arr[mid] < arr[end] 순으로 정렬 완료

void medianOfThreeQuick(int arr[], int start, int end) {	// argument : 정렬할 배열, 처음, 마지막 인덱스
	int l, r, pivot;
	int mid = (start + end) / 2;							// 중간 인덱스 계산
	threeSort(arr, start, mid, end);						// 3개(처음, 중간, 마지막) 값을 오름차순 정렬
																// (3개 이하면 threeSort만으로 정렬 완료)
	if (end - start >= 3) {									// 정렬 대상이 4개 이상일 때만 quick sort 시작
		pivot = arr[mid];									// 중간 값을 pivot으로 지정
		swap(&arr[mid], &arr[end - 1]);						// 중간 값과 <-> [뒤에서 두 번째 값] swap
		l = start + 1;										// 좌 -> 우 cursor (threeSort로 정렬된 start값은 건너뛰고 시작) 
		r = end - 2;										// 좌 <- 우 cursor (end와 pivot을 건너뛰고 시작)

		while (l <= r) {									// 두 cursor가 교차하면 stop
			while (arr[l] <= pivot && l <= r) l++;			// 우로 이동하며 pivot 보다 큰 수가 있거나 교차하면 stop
			while (arr[r] >= pivot && l <= r) r--;			// 좌로 이동하며 pivot 보다 작은 수가 있거나 교차하면 stop
			if (l < r) swap(&arr[l], &arr[r]);				// [커서가 교차하지 않음 = '좌 > 우' 발견]이므로, 두 값을 swap
		}														// < while문 종료 후 배열 상태와 커서 위치 >
																//  [ pivot 이하 그룹 | pivot 이상 그룹 | pivot | end ]
																//  [				 r l							  ]
		swap(&arr[l], &arr[end - 1]);						// [ 이하 그룹 | pivot | 이상 그룹 ] 완성
		medianOfThreeQuick(arr, start, l - 1);				// 이하 그룹에서 medianThreeQuick 재귀적 실행
		medianOfThreeQuick(arr, l + 1, end);				// 이상 그룹에서 medianThreeQuick 재귀적 실행
	}
}