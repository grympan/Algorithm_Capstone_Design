#include <iostream>
#include <cstring>
using namespace std;

int next[50];

void InitNext(char* p)
{
	int i, j = 0, M = strlen(p);

	::next[0] = -1;
	for (i = 0, j = -1; i < M; i++, j++) {
		if (p[i] == p[j])
			::next[i] = ::next[j];
		else ::next[i] = j;
		
		while ((j >= 0) && (p[i] != p[j]))
			j = ::next[j];
	}

}

int KMP(char* p, char* t) // KMP 구현
{
	int i, j, M = strlen(p), N = strlen(t);
	InitNext(p);
	for (i = 0, j = 0; j < M && i < N; i++, j++)
		while ((j >= 0) && (t[i] != p[j])) j = ::next[j];
	if (j == M) return i - M;
	else return i;
}

struct info {
	int index;
	char text[250];
};

int main()
{
	char pattern[8];
	cin >> pattern;

	int count = 0;
	info* line = new info[100];
	for (int i = 0; i < 100; i++){
		cin >> line[i].text;
		if (strcmp(line[i].text, "0")==0)
			break;

	
		int M, N, pos, previous = 0, j = 0;	// KMP 시작

		M = strlen(pattern); N = strlen(line[i].text);
		while (1) {
			pos = KMP(pattern, line[i].text + j);
			pos += previous;
			j = pos + M;
			if (j <= N)
				line[i].index = pos;
			else  break;
			previous = j;
		}
		count++;
	}

	for (int i = 0; i < count; i++)
		if (line[i].index < 0)
			line[i].index = -1;


	int right = count - 1;
	int temp = 0;
	while (right > 0) {
		int k = 0;
		for (int i = 0; i < right; i++)
			if(line[i+1].index < line[i].index){
				
				temp = line[i + 1].index;
				line[i + 1].index = line[i].index;
				line[i].index = temp;
				swap(line[i + 1].text, line[i].text);
				k = i;
			}
		right = k;
	}
	

	for (int i = 0; i < count; i++)
		cout  <<line[i].text << endl;
	
	delete[] line;
	return 0;
}