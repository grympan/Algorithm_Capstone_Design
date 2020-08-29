#include <iostream>
#include <string>
using namespace std;

struct info {
	int height;
	char name[10];
};

int main() {
	int num = 0;
	cin >> num;

	// 입력부
	info* line = new info[num];
	for (int i = 0; i < num; i++) {
		cin >> line[i].height >> line[i].name;

		if (strlen(line[i].name) > 10 || line[i].height >= 200 || line[i].height <= 140) {
			delete[] line;
			return 0;
		}
	}

	int smallest = 0;
	int tempint = 0;
	char tempchar[11] = { NULL };

	// 선택 정렬
	for (int i = 0; i < num; i++) {
		smallest = i;
		for (int j = i + 1; j < num; j++)
			if (line[j].height < line[smallest].height)
				smallest = j;

		// 키 스왑
		tempint = line[i].height;
		line[i].height = line[smallest].height;
		line[smallest].height = tempint;

		// 이름 스왑 (Domjudge에서는 strcpy로 사용하기)
		strcpy_s(tempchar, line[i].name);
		strcpy_s(line[i].name, line[smallest].name);
		strcpy_s(line[smallest].name, tempchar);
	}

	// 출력
	for (int i = 0; i < num; i++)
		cout << line[i].height << " " << line[i].name << endl;

	delete[] line;
	return 0;
}