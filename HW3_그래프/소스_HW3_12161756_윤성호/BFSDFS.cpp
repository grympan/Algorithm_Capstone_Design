#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

#define SIZE 50				// 수용 가능한 최대 노드 수
bool connect[SIZE][SIZE];	// 두 노드 간 연결 여부 (간선)
bool visited[SIZE];			// 노드 방문 여부
int from[SIZE] = { 0, };	// 이전 노드 (간선 표시에 이용)

// 간선 출력 : (이전 노드)-(현재 노드)
void visit(int j) {
	cout << "(" << from[j] << ")-(" << j << ")" << endl;
}

void BFS(int s, int n) {						// argument : 시작 노드, 노드 수
	int j = 0;									// 탐색 노드
	from[s] = s;								// 시작 노드의 이전 노드는 자기 자신
	for (int i = 0; i < n; i++)
		visited[i] = false;						// 모든 노드를 방문하지 않음으로 초기화

	visited[s] = true;							// 시작 노드는 방문으로 처리
	queue<int> que;								// 방문할 노드를 저장하는 큐
	que.push(s);								// 시작 노드를 enqueue

	while (!que.empty()) {						// 큐가 빌 때까지 반복
		j = que.front();						// 탐색 노드(j)는 이어서 dequeue 될 값
		que.pop();								// j를 dequeue
		visit(j);								// j를 방문(출력)

		for (int k = 0; k < n; k++)				// 모든 노드를 오름차순으로 탐색하여,
			if (connect[k][j] == true)			// j와 인접노드인 노드(k)를 찾는다.
				if (visited[k] == false) {		// 해당 k 노드를 이전에 방문한 적이 없었다면,
					que.push(k);				// k를 enqueue
					visited[k] = true;			// k는 방문 처리
					from[k] = j;				// k의 이전 노드를 j로 저장
				}
	}											// for문 종료 시 ① j와 인접 ② 방문한 적 없는
}												// 모든 노드들 오름차순으로 enqueue된다.

void DFS(int s, int n) {						// argument : 시작 노드, 노드 수
	int j = 0;									// 탐색 노드
	from[s] = s;								// 시작 노드의 이전 노드는 자기 자신
	for (int i = 0; i < n; i++)
		visited[i] = false;						// 모든 노드를 방문하지 않음으로 초기화

	stack<int> stk;								// 방문할 노드를 저장하는 스택
	stk.push(s);								// 시작 노드를 push

	while (!stk.empty()) {						// 스택이 빌 때까지 반복
		j = stk.top();							// 탐색 노드(j)는 이어서 pop될 값
		stk.pop();								// j를 pop

		if (visited[j] == false) {				// j 노드를 방문한 적이 없다면,
			visit(j);							// j를 방문(출력)
			visited[j] = true;					// j를 방문 처리

			for (int k = 0; k < n; k++) {		// 모든 노드를 오름차순으로 탐색하여,
				if (connect[k][j] == true)		// j와 인접노드인 노드(k)를 찾는다.
					if (visited[k] == false) {	// 해당 k 노드를 이전에 방문한 적이 없었다면,
						stk.push(k);			// k를 push
						from[k] = j;			// k의 이전 노드를 j로 저장
					}
			}									// for문이 종료 시 ① j와 인접 ② 방문한 적 없는
		}										// 모든 노드들 오름차순으로 push 된다.
	}
}

int main() {
	int n, a, b;								// 정점 개수(n), 간선 입력에 이용될 두 정점(a, b)
	memset(connect, false, sizeof(connect));	// 모든 정점이 연결되지 않은 상태로 초기화

	cout << "[ 12161756 윤성호 ]" << endl;
	cout << "정점 개수(n) : ";
	cin >> n;									// 정점 개수 입력

	cout << "\n간선을 입력하세요. \t [정점 범위 : 0~" << n - 1 << "]";
	cout << "\nex) 0 2 -> 0과 2 연결 \t [-1 입력 시 종료]" << endl;
	for (;;) {									// 간선 입력
		cin >> a;
		if (a == -1) break;						// -1 입력 시 간선 입력 종료
		cin >> b;

		connect[a][b] = connect[b][a] = true;	// 입력된 간선을 입력 순서에 상관없이 연결된 것으로 기록
	}

	cout << "\nBFS (FROM)-(TO)" << endl;
	BFS(0, n);
	cout << "\nDFS (FROM)-(TO)" << endl;
	DFS(0, n);
}