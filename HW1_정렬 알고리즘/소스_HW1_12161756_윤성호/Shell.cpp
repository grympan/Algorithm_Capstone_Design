#include "Sort.h"									// 함수 선언을 포함한 header

void shell(int arr[], int len) {					// argument : 정렬할 배열, 정렬할 data 수(n)
	int i, j, h, key;								// h(gap) : 서브리스트를 만들 기준, data 간의 거리
	i = j = key = 0;								// h = 1, 4, 13, 40 ...
	for (h = 1; h < len; h = 3 * h + 1);			// 배열 길이보다 작은 h값들 중 가장 큰 값으로 지정

	for (; h > 0; h /= 3) {							// 최대 h값부터 시작하여 (... 13, 4), 1까지 감소시키며 시행
		for (i = h; i < len; i++) {					// h로 만들어진 서브리스트들을 insertion sort
			key = arr[i];							// 삽입할 key값 지정
			j = i;									// key값 인덱스를 j로 넘김

			while (j >= h && arr[j - h] > key) {	// 서브리스트 안에서 key 이전 값이 key보다 크면
				arr[j] = arr[j - h];				// 해당 값을 h간격 뒤의 수에 덮어 씌움 (서브리스트 상에서 바로 다음 수에)
				j -= h;								// key의 왼쪽 값들 중 또 key보다 큰 값이 있는지 탐색하기 위해 j를 h만큼 줄임
			}											// while문 종료시 : j는 key값이 들어갈 위치를 가리킴
			arr[j] = key;							// 해당 공간에 key값 삽입
		}												// inner for문 종료시 : h 간격으로 분리된 각각의 서브리스트들 오름차순 정렬됨
	}													// outer for문 종료시 : h를 낮춰가며 cycle이 반복 될수록 점차 정렬된 모습을 갖춰감 
}														//						마지막 h = 1인 cycle을 거치면 배열 전체가 오름차순으로 정렬됨