#include <iostream>
#include <cstring>
using namespace std;

int next[50];

void InitNext(char* p) {
	int i, j = 0, M = strlen(p);

	::next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		::next[i] = (p[i] == p[j]) ? ::next[j] : j;
		while ((j >= 0) && (p[i] != p[j]))
			j = ::next[j];
	}
}

int KMP(char* p, char* t) {
	int i, j, M = strlen(p), N = strlen(t);
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while ((j >= 0) && (t[i] != p[j])) j = ::next[j];
	if (j == M) {
		int k;
		for (k = i; k < N; k++)
			t[k - M] = t[k];
		t[k - M] = 0;
		return 0;
	}
	else return i;
}

int main()
{
	//char text[100] = "1001110100101000101001110";
	//char pattern[50] = "10100111";

	//char text[100] = "ababababcababababcaabbabababcaab";
	//char pattern[50] = "abababca";

	char text[100] = "AAABBB";
	char pattern[50] = "AB";

	//char text[100] = "whatthemomooofun";
	//char pattern[50] = "moo";

	int M, N, pos, i = 0;

	while (1) {
		M = strlen(pattern); N = strlen(text);
		pos = KMP(pattern, text);
		if(pos + M > N) break;
	}

	cout << text;
	return 0;
}