#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STR_LEN 100

/*
	�μ� : ���� ���ڿ�
	��ȯ : lps �迭
*/
int* getNextArray(char* _pattern_str) {
	int pattern_len;
	int* _lps = 0;		// LPS �迭
	int i, j;

	pattern_len = strlen(_pattern_str);

	// LPS �迭
	_lps = (int *)malloc(sizeof(int) * pattern_len);

	// LPS �迭 �ʱ�ȭ
	memset(_lps, 0, sizeof(int) * pattern_len);

	// LPS �迭 ���
	j = 0;
	for (i = 1; i < pattern_len; i++) {

		if (j > 0 && _pattern_str[i] != _pattern_str[j]) {
			j = _lps[j - 1];
		}

		if (_pattern_str[i] == _pattern_str[j]) {
			j++;
			_lps[i] = j;
		}
	}


	return _lps;
}

int main(void) {
	int i, j;

	// target string
	char target_str[STR_LEN] = "AAAAA";

	// pattern string
	char pattern_str[STR_LEN] = "AA";

	//char target_str[STR_LEN] = "ABABABABBABABABABC";
	//char pattern_str[STR_LEN] = "ABABABABC";

	int target_len;
	int pattern_len;
	int* lps = 0;

	target_len = strlen(target_str);
	pattern_len = strlen(pattern_str);

	// LPS �迭�� ���
	lps = getNextArray(pattern_str);

	// ���� LPS���� ����ϴ� �κ�
	for (i = 0; i < pattern_len; i++) {
		printf("%d ---> %d\n", i, lps[i]);
	}

	//--- string matching
	printf("----- start string matching of %s to %s\n", pattern_str, target_str);

	// i : target str�� ���� ��ġ index
	// j : pattern str�� ���� ��ġ index

	j = 0;
	for (i = 0; i < target_len; i++) {
		while (j > 0 && target_str[i] != pattern_str[j]) {
			j = lps[j - 1];
		}
		
		if (target_str[i] == pattern_str[j]) {
			if (j == (pattern_len - 1)) {
				printf("Found matching at %d\n", (i - pattern_len + 1));
				j = lps[j];
			}
			else
				j++;
		}
	}

	return 0;
}