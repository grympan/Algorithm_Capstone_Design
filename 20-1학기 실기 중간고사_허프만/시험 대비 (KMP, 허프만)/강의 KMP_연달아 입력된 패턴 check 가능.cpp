#include <iostream>
#include <cstring>
using namespace std;

int next[50];

void InitNext(char* p){
	int i, j = 0, M = strlen(p);

	::next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		::next[i] = (p[i] == p[j]) ? ::next[j] : j;
		while ((j >= 0) && (p[i] != p[j]))
			j = ::next[j];
	}
}

int KMP(char *p, char *t){
	int i, j, M = strlen(p), N = strlen(t);
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while ((j >= 0) && (t[i] != p[j])) j = ::next[j];
	if (j == M) return i - M;
	else return i;
}

void main()
{
	//char text[100] = "1001110100101000101001110";
	//char pattern[50] = "10100111";

	//char text[100] = "ababababcababababcaabbabababcaab";
	//char pattern[50] = "abababca";

	char text[100] = "ABCDE";
	char pattern[50] = 	"E";

	cin.getline(text, 100);
	cin.getline(pattern, 50);

	int M, N, pos, previous = 0, i = 0;

	M = strlen(pattern); N = strlen(text);
	while (1) {
		pos = KMP(pattern, text + i);
		pos += previous;
		i = pos + M;
		if (i <= N) {
			cout << "패턴이 발생한 위치 : " << pos << endl;
			i = pos + 1;
		}
		else break;
		previous = i;
	}
	cout << "스트링 탐색 종료." << endl;
}