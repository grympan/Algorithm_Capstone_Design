#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

// pattern���� ���Ͽ� '����ġ �߻� �� �̵��� ���� ��ġ�� �˷��ִ�'
// next �迭�� �����ϴ� �Լ�
int* makeNext(char* p) {						// argument : pattern �ּ�
	int M = strlen(p);							// pattern ����
	int* next = new int[256]{ 0, };				// next �迭 ���� �� �ʱ�ȭ

	next[0] = -1;								// next �迭�� 0��° ���� -1�� ����

	for (int i = 1, j = 0; i <= M; i++, j++) {	// next �迭�� 1 ~ M��° key�� ä���
		if (p[i] == p[j])						// ����ġ�Ͽ� �̵��� ��ġ������ ������ ���� ���� �־�
			next[i] = next[j];					// �� ����ġ�ϴ� ���� jump�� �� next �迭�� ���

		else									// ���� ��찡 �ƴϸ�
			next[i] = j;					// �������� ��ġ�ߴ� ���� j�� next �迭�� ���

		while ((j >= 0) && (p[i] != p[j]))		// ����ġ �߻� �� ���ݱ��� ������� next �迭�� �̿��Ͽ�
			j = next[j];						// ��ġ�� ������ j�� �̵�
	}

	return next;								// next �迭�� �ּ� ����
}

// ó������ �߰ߵ� pattern�� ��ġ�� ��ȯ�ϴ� �Լ�
int KMP(char* p, char* t, int* next) {				// argument : pattern, text, next�� �ּ�
	int M = strlen(p), N = strlen(t);				// pattern(M)�� text(N)�� ����
	int i, j;										// Ž�� ���� text(i)�� pattern(j)�� ��ġ

	for (i = 0, j = 0; j < M && i < N; i++, j++)	// text�� ������ Ž���ϰų� �� ���� pattern�� ã���� ����
		while ((j >= 0) && (t[i] != p[j]))			// ����ġ �߻���
			j = next[j];							// ���� Ž�� ��ġ�� �̵�

	if (j == M)										// pattern�� �߰��� ���
		return i - M;								// pattern�� ���۵� ��ġ�� ��ȯ
	else											// pattern �߰��� ������ ���
		return i;									// ���� text�� ��ġ(= text�� ��)�� ��ȯ
}

// pattern �߻� Ƚ�� (��������)
int result = 0;

// text���� �߻��� ��� pattern�� ��ġ�� ���
// argument : pattern, text, next �迭�� �ּ�, ���� �������� ���� ��ġ
void printLocation(char* p, char* t, int* next, int posInFile) {
	int M = strlen(p), N = strlen(t);		// pattern(M)�� text(N)�� ����
	int pos, previous = 0, i = 0;			// pos : text������ ��ġ // previous : text������ ���� ��ġ
											// i : KMP�� �̾ ������ ��ġ (���� �߻� �Ǻ����� �̿�)
	while (1) {								// ���� ����
		pos = KMP(p, t + i, next);			// KMP ����
		pos += previous;					// ���� ��ġ �ݿ�
		i = pos + M;						// pattern ���̸�ŭ ��ġ �̵�

		if (i <= N) {						// pattern�� �߻��� ���� �´ٸ�,
			::result++;						// �߻� Ƚ�� ����		
			cout << ::result << "��° ��ġ\t: " << pos + posInFile + 1 << endl;
			// pattern ��ġ ���(���� �� ��ġ �ݿ�)
			i -= next[M];					// ���� ��ü ���ڿ��� prefix�� suffix�� ��ġ�ϴ� ��� �� 
		}									// ���� ���̸�ŭ �������� ��ġ �̵�

		else break;							// ������ �߻��� ���� �ƴϸ� ���� Ż��

		previous = i;						// �̵��� ��ġ�� ���� ��ġ�� ����
	}
}

int main() {
	ifstream file("RFC2616_modified.txt");			// ���� ����
	char text[1000], pattern[256];					// text : ���� ���� �� �� �� // pattern : ����
	char chr;										// ���� ���� �� �� ����
	int idx;										// ���� �� �ٿ����� �ε��� (= text �迭�� �ε���)
	int locInFile = 0;								// file �������� ��ġ
	int* next;										// next �迭�� �ּ�

	cout << "[ 12161756 ����ȣ ]" << endl;
	cout << "�˻��� ������ �Է��ϼ���." << endl;
	cin.getline(pattern, 256);						// �˻��� ������ �Է� ����
	cout << endl;

	next = makeNext(pattern);						// next �迭 ����

	while (!file.eof()) {							// ������ ��� ���� ������ �ݺ�
		chr = file.get();							// ���Ͽ��� �� ���ھ� �ҷ���
		idx = 0;									// �� ���ο� ���� ������ ������ �ε��� �ʱ�ȭ

		while (!file.eof() && chr != '\n') {		// ���� ���� �� �ٹٲ��� �߰ߵǸ� ���� (�� �پ� �ҷ�����)
			text[idx] = chr;						// ���Ͽ��� ������ �� ���ھ� text �迭�� �Է�
			chr = file.get();						// ���Ͽ��� �� ���ھ� �ҷ���
			idx++;									// �ε��� ����
		}
		text[idx] = 0;								// �� �ι��� ó��

		printLocation(pattern, text, next, locInFile);	// �� �ٿ� �ִ� ��� pattern�� �˻��Ͽ� �� ��ġ�� ���

		locInFile = locInFile + idx + 1;				// ��ġ �� ����
	}

	cout << "\n��� " << ::result << "���� ã�ҽ��ϴ�." << endl;	// �˻��� Ƚ�� ���
	system("pause");
	return 0;
}