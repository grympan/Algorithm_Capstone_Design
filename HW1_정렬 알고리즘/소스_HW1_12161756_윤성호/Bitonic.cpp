#include "Sort.h"												// 함수 선언을 포함한 header

// 배열을 다시 합치는 함수
void BTmerge(int arr[], int top, int len, bool updown) {		// argument : 배열, top 인덱스, data 수, 정렬 방식
	if (len >= 2) {												// 배열의 data가 두 개 이상일 때만 실행
		int half = len / 2;										// 배열의 절반 길이
		for (int i = top; i < top + half; i++) {				// 배열의 절반 길이 만큼 시행
			if (updown == up && arr[i] > arr[i + half])			// 오름차순일 경우, for루프 종료시
				swap(&arr[i], &arr[i + half]);					// 예시에서 a와 A, B와 b.. 가 비교되며 대문자 > 소문자이면
																	// ex [ a B C d | A b c D ] -> [ a b c d | A B C D ]
			else if (updown == down && arr[i] < arr[i + half])	
				swap(&arr[i], &arr[i + half]);					// 내림차순일 경우, for루프 종료시
		}															// ex [ A b C d | a B c D ] -> [ A B C D | a b c d ]

		BTmerge(arr, top, half, updown);						// 배열을 반으로 나눠 앞뒤 각각 BTmerge 재귀적 실행 //
		BTmerge(arr, top + half, half, updown);					//													//
	}
}

void bitonic(int arr[], int top, int len, bool updown) {		// argument : 배열, top 인덱스, data 수, 정렬 방식
	if (len >= 2) {												// 배열의 data가 두 개 이상일 때만 실행
		int half = len / 2;										// 배열의 절반 길이

		bitonic(arr, top, half, up);							// 배열을 반으로 나눴을 때 앞쪽은 오름차순 정렬
		bitonic(arr, top + half, half, down);					// 뒤쪽은 내림차순 정렬
		BTmerge(arr, top, len, updown);							// 배열 합치기
	}
}