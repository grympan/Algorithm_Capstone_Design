#include <iostream>
using namespace std;

int main() {
	int stu_num = 0; int word_num = 0;
	char box[1000];

	cin >> stu_num >> word_num;
	int size = stu_num * word_num;

	for (int i = 0; i < size; i++)
		cin >> box[i];

	int test = 0;
	int temp = 0;
	int res1 = 0;
	int res2 = 0;	//최대 영어 단어수를 알 수 있는 팀

	for (int j = 0; j <= stu_num - 3; j++) {
		temp = j * word_num;
		for (int i = word_num; i < size; i++) {
			if ((box[temp] == '1' || box[i] == '1') && temp != i)  test++;
			temp++;
			if (temp >= (word_num * j) + word_num) {
				if (test > res1) res1 = test;
				test = 0;
				temp = j * word_num;
			}
		}
	}

	for (int j = 0; j <= stu_num - 3; j++) {
		temp = j * word_num;
		for (int i = word_num; i < size; i++) {
			if ((box[temp] == '1' || box[i] == '1') && temp != i)  test++;
			temp++;
			if (temp >= (word_num * j) + word_num) {
				if (test == res1) res2++;
				test = 0;
				temp = j * word_num;
			}
		}
	}

	temp = size - word_num - word_num;
	for (int i = size - word_num; i < size; i++) {
		if ((box[temp] == '1' || box[i] == '1') && temp != i)  test++;
		if (test == res1) res2++;
		temp++;
	}

	cout << res1 << endl;
	cout << res2 << endl;
	return 0;
}
