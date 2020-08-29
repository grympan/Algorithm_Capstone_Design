#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

#define SIZE 50				// ���� ������ �ִ� ��� ��
bool connect[SIZE][SIZE];	// �� ��� �� ���� ���� (����)
bool visited[SIZE];			// ��� �湮 ����
int from[SIZE] = { 0, };	// ���� ��� (���� ǥ�ÿ� �̿�)

// ���� ��� : (���� ���)-(���� ���)
void visit(int j) {
	cout << "(" << from[j] << ")-(" << j << ")" << endl;
}

void BFS(int s, int n) {						// argument : ���� ���, ��� ��
	int j = 0;									// Ž�� ���
	from[s] = s;								// ���� ����� ���� ���� �ڱ� �ڽ�
	for (int i = 0; i < n; i++)
		visited[i] = false;						// ��� ��带 �湮���� �������� �ʱ�ȭ

	visited[s] = true;							// ���� ���� �湮���� ó��
	queue<int> que;								// �湮�� ��带 �����ϴ� ť
	que.push(s);								// ���� ��带 enqueue

	while (!que.empty()) {						// ť�� �� ������ �ݺ�
		j = que.front();						// Ž�� ���(j)�� �̾ dequeue �� ��
		que.pop();								// j�� dequeue
		visit(j);								// j�� �湮(���)

		for (int k = 0; k < n; k++)				// ��� ��带 ������������ Ž���Ͽ�,
			if (connect[k][j] == true)			// j�� ��������� ���(k)�� ã�´�.
				if (visited[k] == false) {		// �ش� k ��带 ������ �湮�� ���� �����ٸ�,
					que.push(k);				// k�� enqueue
					visited[k] = true;			// k�� �湮 ó��
					from[k] = j;				// k�� ���� ��带 j�� ����
				}
	}											// for�� ���� �� �� j�� ���� �� �湮�� �� ����
}												// ��� ���� ������������ enqueue�ȴ�.

void DFS(int s, int n) {						// argument : ���� ���, ��� ��
	int j = 0;									// Ž�� ���
	from[s] = s;								// ���� ����� ���� ���� �ڱ� �ڽ�
	for (int i = 0; i < n; i++)
		visited[i] = false;						// ��� ��带 �湮���� �������� �ʱ�ȭ

	stack<int> stk;								// �湮�� ��带 �����ϴ� ����
	stk.push(s);								// ���� ��带 push

	while (!stk.empty()) {						// ������ �� ������ �ݺ�
		j = stk.top();							// Ž�� ���(j)�� �̾ pop�� ��
		stk.pop();								// j�� pop

		if (visited[j] == false) {				// j ��带 �湮�� ���� ���ٸ�,
			visit(j);							// j�� �湮(���)
			visited[j] = true;					// j�� �湮 ó��

			for (int k = 0; k < n; k++) {		// ��� ��带 ������������ Ž���Ͽ�,
				if (connect[k][j] == true)		// j�� ��������� ���(k)�� ã�´�.
					if (visited[k] == false) {	// �ش� k ��带 ������ �湮�� ���� �����ٸ�,
						stk.push(k);			// k�� push
						from[k] = j;			// k�� ���� ��带 j�� ����
					}
			}									// for���� ���� �� �� j�� ���� �� �湮�� �� ����
		}										// ��� ���� ������������ push �ȴ�.
	}
}

int main() {
	int n, a, b;								// ���� ����(n), ���� �Է¿� �̿�� �� ����(a, b)
	memset(connect, false, sizeof(connect));	// ��� ������ ������� ���� ���·� �ʱ�ȭ

	cout << "[ 12161756 ����ȣ ]" << endl;
	cout << "���� ����(n) : ";
	cin >> n;									// ���� ���� �Է�

	cout << "\n������ �Է��ϼ���. \t [���� ���� : 0~" << n - 1 << "]";
	cout << "\nex) 0 2 -> 0�� 2 ���� \t [-1 �Է� �� ����]" << endl;
	for (;;) {									// ���� �Է�
		cin >> a;
		if (a == -1) break;						// -1 �Է� �� ���� �Է� ����
		cin >> b;

		connect[a][b] = connect[b][a] = true;	// �Էµ� ������ �Է� ������ ������� ����� ������ ���
	}

	cout << "\nBFS (FROM)-(TO)" << endl;
	BFS(0, n);
	cout << "\nDFS (FROM)-(TO)" << endl;
	DFS(0, n);
}