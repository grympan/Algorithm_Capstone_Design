#include "Sort.h"
#include <iostream>
#include <chrono>		// 시간 측정을 위한 라이브러리
using namespace std;
using namespace chrono;

void swap(int* a, int* b) {		// swap 함수
	int temp = *a;
	*a = *b;
	*b = temp;
};

// 5개의 배열에 난수를 채우는 함수
// argument : 원본 배열, 복사할 4개 배열, 배열 길이(n)
void getDataSet(int src[], int cp1[], int cp2[], int cp3[], int cp4[], int len) {
	for (int i = 0; i < len; i++)
		src[i] = rand() % (len * 10);					// 0 ~ (n * 10) 사이 난수를 원본 배열에 채운다.

	for (int i = 0; i < len; i++)
		cp1[i] = cp2[i] = cp3[i] = cp4[i] = src[i];		// 원본 배열을 나머지 4개의 배열에 복사한다.
};

int main() {
	high_resolution_clock::time_point start1, start2, start3, start4, start5;		// 시간 측정 시작점
	high_resolution_clock::time_point end1, end2, end3, end4, end5;					// 시간 측정 종점
	milliseconds gap1, gap2, gap3, gap4, gap5;										// 소요 시간이 저장될 gap 변수
	int a = 0, n = 0, menu = 0;

	cout << "[ 12161756 윤성호 ]" << endl;
	cout << "데이터 셋의 크기를 [n = 2^a]으로 설정합니다" << endl;
	cout << "a값을 입력합니다 : ";
	cin >> a;																		// a값 입력
	n = (int)pow(2, a);																// n = 2^a
	cout << "\n데이터 셋의 크기(n) = " << n;

	int* set1 = new int[n];		int* set2 = new int[n];		int* set3 = new int[n];
	int* set4 = new int[n];		int* set5 = new int[n];								// 5개 배열 동적 할당
	getDataSet(set1, set2, set3, set4, set5, n);									// 동일한 5개의 데이터 셋 생성

	// 각 정렬 함수 앞뒤로 시작과 종료 시각을 기록
	start1 = high_resolution_clock::now();	selection(set1, n);					end1 = high_resolution_clock::now();
	start2 = high_resolution_clock::now();	medianOfThreeQuick(set2, 0, n - 1);	end2 = high_resolution_clock::now();
	start3 = high_resolution_clock::now();	shell(set3, n);						end3 = high_resolution_clock::now();
	start4 = high_resolution_clock::now();	bitonic(set4, 0, n, up);			end4 = high_resolution_clock::now();
	start5 = high_resolution_clock::now();	oddEven(set5, 0, n);				end5 = high_resolution_clock::now();

	// 정렬 소요 시간 계산 (종료 - 시작 시각)
	gap1 = duration_cast<milliseconds>(end1 - start1);	gap2 = duration_cast<milliseconds>(end2 - start2);
	gap3 = duration_cast<milliseconds>(end3 - start3);	gap4 = duration_cast<milliseconds>(end4 - start4);
	gap5 = duration_cast<milliseconds>(end5 - start5);

	// 각 정렬 알고리즘 별 시간 출력
	cout << "\nSelection \t\t= " << gap1.count() << " ms" << endl;
	cout << "Median-of-three Quick \t= " << gap2.count() << " ms" << endl;
	cout << "Shell \t\t\t= " << gap3.count() << " ms" << endl;
	cout << "Bitonic \t\t= " << gap4.count() << " ms" << endl;
	cout << "Odd-Even Merge \t\t= " << gap5.count() << " ms" << endl;

	delete[] set1, set2, set3, set4, set5;									// 메모리 해제
	return 0;
}