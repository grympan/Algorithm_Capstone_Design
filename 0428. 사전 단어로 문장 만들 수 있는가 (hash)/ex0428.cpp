#include <iostream>
using namespace std;

struct Hash {
	char name[100][20] = { 0, };
	int table[100][20] = { 0, };
	int PN = 100, hashSize = 0;

	unsigned int getKey(char* s) {
		unsigned int key = 0, p = 1;

		for (int i = 0; s[i] != 0; i++) {
			key += s[i] * p;
			p *= PN;
		}
		return key % 100;
	}

	void push(char* s) {
		for (int i = 0; s[i] != 0; i++)
			name[hashSize][i] = s[i];

		unsigned int key = getKey(s);
		int& size = table[key][0];
		table[key][++size] = hashSize;
		hashSize++;
	}

	int load(char* s) {
		unsigned int key = getKey(s);
		int size = table[key][0];

		for (int i = 1; i <= size; i++) {
			int npos = table[key][i];
			if (compare(name[npos], s) == 0)
				return npos;
		}
		return -1;
	}

	int compare(char* a, char* b) {
		int i = 0;

		while (a[i]) {
			if (a[i] != b[i]) break;
			i++;
		}
		return a[i] - b[i];
	}

}map;

struct Store {
	char s[50];

	bool operator < (Store a) const {
		int index = 0;

		while (s[index]) {
			if (s[index] != a.s[index]) break;
			index++;
		}
		return s[index] < a.s[index];
	}
}store[50];

Store buf[50];

int main() {
	int dic_count, user_count;
	cin >> dic_count >> user_count;

	int answer = user_count;

	char str[50];
	while (dic_count--) {
		cin >> str;
		map.push(str);
	}

	int count = 0;

	while (user_count--) {
		cin >> str;

		if (map.load(str) >= 0) {
			int index = 0;

			while (str[index]) {
				store[count].s[index] = str[index];
				index++;
			}
			count++;
		}
	}

	if (count == answer)
		cout << 1;
	else
		cout << 0;

	return 0;
}