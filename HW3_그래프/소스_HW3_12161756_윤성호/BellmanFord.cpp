#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define SIZE 50			// 수용 가능한 최대 노드 수
#define INF 99999		// 무한대 대체 값

int main() {
	int Dist[SIZE];								// 최단 경로
	int beforeChk[SIZE];						// 사이클 검사 전의 최단 경로
	int indegree[SIZE] = { 0, };				// 진입 차수
	vector <tuple<int, int, int>> weight;		// 간선과 그에 따른 가중치

// 1) 입력부
	int n, src, dst, cost;						// 노드 수(n), 간선 시작점(src)
	cout << "[ 12161756 윤성호 ]" << endl;		// 간선 끝점(dst), 가중치(cost)
	cout << "정점 개수(n) : ";
	cin >> n;									// 노드 수 입력

	cout << "\n간선과 가중치를 입력하세요. [-1 입력 시 종료]";
	cout << "\nex) 0 1 5 ==> 0->1 (cost : 5)" << endl;

	for (;;) {
		cin >> src;										// 간선 시작점 입력
		if (src == -1) break;							// -1 입력 시 간선 입력 종료
		cin >> dst >> cost;								// 간선 끝점과 가중치 입력
		weight.push_back(make_tuple(src, dst, cost));	// 해당 간선 정보를 tuple로 저장
	}
	int path = weight.size();							// 간선 수

// 2) 초기 설정
	// 최단 경로의 초깃값은 무한대로 설정
	for (int i = 1; i < SIZE; i++)
		Dist[i] = beforeChk[i] = INF;

	// 진입 차수 계산
	for (int i = 0; i < n; i++)							// 노드 수 만큼 loop
		for (int j = 0; j < path; j++)					// 간선 수 만큼 loop
			if (i == get<1>(weight[j]))					// 해당 노드가 간선의 도착점으로 사용되면
				indegree[i]++;							// 진입 차수 +1

// 3) 최단 경로 계산

	// Dist^1 수행
	for (int i = 0; i < path; i++)						// 간선 수 만큼 loop
		if (get<0>(weight[i]) == 0)						// 시작점이 0인 간선에 대해
			Dist[get<1>(weight[i])] = get<2>(weight[i]);// Dist[dst]를 해당 간선의 가중치로 초기화
	Dist[0] = 0;										// 시작점 0에서의 최단 경로는 0

	// Dist^2 ~ Dist^n 수행
	for (int k = 2; k <= n; k++) {
		if (k == n)										// 사이클 검사를 위해 마지막 loop에서
			for (int i = 0; i < SIZE; i++)
				beforeChk[i] = Dist[i];					// 이전(Dist^n-1)까지 기록된 최단 경로를 복사

		for (int i = 0; i < path; i++) {				// 간선 수 만큼 loop
			src = get<0>(weight[i]);					// 시작점은 0번째 argument,
			dst = get<1>(weight[i]);					// 끝점은 1번째 argument,
			cost = get<2>(weight[i]);					// 가중치는 2번째 argument를 이용

			if (indegree[dst] > 0)						// dst의 진입 차수가 0보다 큰 것 중에
				if (Dist[dst] > Dist[src] + cost)		// src까지 최단 거리 + (src->dst 간선의 가중치)가
					Dist[dst] = Dist[src] + cost;		// 현재까지 계산된 dst까지의 최단 경로보다 더 작다면
		}												// 그 값을 dst까지의 최단 경로로 갱신
	}

	// 4) 음의 사이클 검사
	for (int i = 0; i < n; i++)							// 모든 노드에 대해 검사
		if (beforeChk[i] != Dist[i]) {					// 최단 경로 계산을 n-1번 수행한 값과 n번 수행한 값이 다르면
			cout << "\n음의 사이클이 감지되었습니다. 종료합니다.\n";
			return 0;									// 음의 사이클이 존재하는 것으로 간주하고
		}												// 프로그램 종료

// 5) 출력부 (음의 사이클이 없는 경우)
	// Dist^(n-1) 출력
	cout << "\n[Bellman-Ford Algorithm 결과]";
	cout << "\nDist^" << n - 1 << " : ";
	for (int i = 0; i < n; i++)
		cout << beforeChk[i] << " ";
	cout << endl;

	// 각 최단 경로 값 출력
	for (int i = 1; i < n; i++)
		cout << "0 -> " << i << " 최단 경로 : " << beforeChk[i] << endl;

	return 0;
}