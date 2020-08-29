#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

// pattern끼리 비교하여 '불일치 발생 시 이동할 다음 위치를 알려주는'
// next 배열을 생성하는 함수
int* makeNext(char* p) {						// argument : pattern 주소
	int M = strlen(p);							// pattern 길이
	int* next = new int[256]{ 0, };				// next 배열 선언 및 초기화

	next[0] = -1;								// next 배열의 0번째 값은 -1로 고정

	for (int i = 1, j = 0; i <= M; i++, j++) {	// next 배열의 1 ~ M번째 key값 채우기
		if (p[i] == p[j])						// 불일치하여 이동한 위치에서도 이전과 같은 값이 있어
			next[i] = next[j];					// 또 불일치하는 경우는 jump한 후 next 배열에 기록

		else									// 위의 경우가 아니면
			next[i] = j;					// 이전까지 일치했던 개수 j를 next 배열에 기록

		while ((j >= 0) && (p[i] != p[j]))		// 불일치 발생 시 지금까지 만들어진 next 배열을 이용하여
			j = next[j];						// 일치할 때까지 j를 이동
	}

	return next;								// next 배열의 주소 리턴
}

// 처음으로 발견된 pattern의 위치를 반환하는 함수
int KMP(char* p, char* t, int* next) {				// argument : pattern, text, next의 주소
	int M = strlen(p), N = strlen(t);				// pattern(M)과 text(N)의 길이
	int i, j;										// 탐색 중인 text(i)와 pattern(j)의 위치

	for (i = 0, j = 0; j < M && i < N; i++, j++)	// text를 끝까지 탐색하거나 그 전에 pattern을 찾으면 종료
		while ((j >= 0) && (t[i] != p[j]))			// 불일치 발생시
			j = next[j];							// 다음 탐색 위치로 이동

	if (j == M)										// pattern을 발견한 경우
		return i - M;								// pattern이 시작된 위치를 반환
	else											// pattern 발견을 실패한 경우
		return i;									// 현재 text의 위치(= text의 끝)를 반환
}

// pattern 발생 횟수 (전역변수)
int result = 0;

// text에서 발생한 모든 pattern의 위치를 출력
// argument : pattern, text, next 배열의 주소, 파일 내에서의 누적 위치
void printLocation(char* p, char* t, int* next, int posInFile) {
	int M = strlen(p), N = strlen(t);		// pattern(M)과 text(N)의 길이
	int pos, previous = 0, i = 0;			// pos : text에서의 위치 // previous : text에서의 누적 위치
											// i : KMP를 이어서 시작할 위치 (패턴 발생 판별에도 이용)
	while (1) {								// 무한 루프
		pos = KMP(p, t + i, next);			// KMP 실행
		pos += previous;					// 누적 위치 반영
		i = pos + M;						// pattern 길이만큼 위치 이동

		if (i <= N) {						// pattern이 발생한 것이 맞다면,
			::result++;						// 발생 횟수 증가		
			cout << ::result << "번째 위치\t: " << pos + posInFile + 1 << endl;
			// pattern 위치 출력(파일 내 위치 반영)
			i -= next[M];					// 패턴 전체 문자열의 prefix와 suffix가 일치하는 경우 중 
		}									// 최장 길이만큼 왼쪽으로 위치 이동

		else break;							// 패턴이 발생한 것이 아니면 루프 탈출

		previous = i;						// 이동한 위치를 누적 위치에 저장
	}
}

int main() {
	ifstream file("RFC2616_modified.txt");			// 파일 열기
	char text[1000], pattern[256];					// text : 파일 내용 중 한 줄 // pattern : 패턴
	char chr;										// 파일 내용 중 한 글자
	int idx;										// 파일 한 줄에서의 인덱스 (= text 배열의 인덱스)
	int locInFile = 0;								// file 내에서의 위치
	int* next;										// next 배열의 주소

	cout << "[ 12161756 윤성호 ]" << endl;
	cout << "검색할 패턴을 입력하세요." << endl;
	cin.getline(pattern, 256);						// 검색할 패턴을 입력 받음
	cout << endl;

	next = makeNext(pattern);						// next 배열 생성

	while (!file.eof()) {							// 파일을 모두 읽을 때까지 반복
		chr = file.get();							// 파일에서 한 글자씩 불러옴
		idx = 0;									// 매 새로운 줄을 시작할 때마다 인덱스 초기화

		while (!file.eof() && chr != '\n') {		// 파일 내용 중 줄바꿈이 발견되면 종료 (한 줄씩 불러오기)
			text[idx] = chr;						// 파일에서 가져온 한 글자씩 text 배열에 입력
			chr = file.get();						// 파일에서 한 글자씩 불러옴
			idx++;									// 인덱스 증가
		}
		text[idx] = 0;								// 끝 널문자 처리

		printLocation(pattern, text, next, locInFile);	// 한 줄에 있는 모든 pattern을 검색하여 그 위치를 출력

		locInFile = locInFile + idx + 1;				// 위치 값 누적
	}

	cout << "\n모두 " << ::result << "번을 찾았습니다." << endl;	// 검색된 횟수 출력
	system("pause");
	return 0;
}