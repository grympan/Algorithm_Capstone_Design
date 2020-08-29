#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
#define SIZE 50			// ���� ������ �ִ� ��� ��
#define INF 99999		// ���Ѵ� ��ü ��

int main() {
	int Dist[SIZE];								// �ִ� ���
	int beforeChk[SIZE];						// ����Ŭ �˻� ���� �ִ� ���
	int indegree[SIZE] = { 0, };				// ���� ����
	vector <tuple<int, int, int>> weight;		// ������ �׿� ���� ����ġ

// 1) �Էº�
	int n, src, dst, cost;						// ��� ��(n), ���� ������(src)
	cout << "[ 12161756 ����ȣ ]" << endl;		// ���� ����(dst), ����ġ(cost)
	cout << "���� ����(n) : ";
	cin >> n;									// ��� �� �Է�

	cout << "\n������ ����ġ�� �Է��ϼ���. [-1 �Է� �� ����]";
	cout << "\nex) 0 1 5 ==> 0->1 (cost : 5)" << endl;

	for (;;) {
		cin >> src;										// ���� ������ �Է�
		if (src == -1) break;							// -1 �Է� �� ���� �Է� ����
		cin >> dst >> cost;								// ���� ������ ����ġ �Է�
		weight.push_back(make_tuple(src, dst, cost));	// �ش� ���� ������ tuple�� ����
	}
	int path = weight.size();							// ���� ��

// 2) �ʱ� ����
	// �ִ� ����� �ʱ갪�� ���Ѵ�� ����
	for (int i = 1; i < SIZE; i++)
		Dist[i] = beforeChk[i] = INF;

	// ���� ���� ���
	for (int i = 0; i < n; i++)							// ��� �� ��ŭ loop
		for (int j = 0; j < path; j++)					// ���� �� ��ŭ loop
			if (i == get<1>(weight[j]))					// �ش� ��尡 ������ ���������� ���Ǹ�
				indegree[i]++;							// ���� ���� +1

// 3) �ִ� ��� ���

	// Dist^1 ����
	for (int i = 0; i < path; i++)						// ���� �� ��ŭ loop
		if (get<0>(weight[i]) == 0)						// �������� 0�� ������ ����
			Dist[get<1>(weight[i])] = get<2>(weight[i]);// Dist[dst]�� �ش� ������ ����ġ�� �ʱ�ȭ
	Dist[0] = 0;										// ������ 0������ �ִ� ��δ� 0

	// Dist^2 ~ Dist^n ����
	for (int k = 2; k <= n; k++) {
		if (k == n)										// ����Ŭ �˻縦 ���� ������ loop����
			for (int i = 0; i < SIZE; i++)
				beforeChk[i] = Dist[i];					// ����(Dist^n-1)���� ��ϵ� �ִ� ��θ� ����

		for (int i = 0; i < path; i++) {				// ���� �� ��ŭ loop
			src = get<0>(weight[i]);					// �������� 0��° argument,
			dst = get<1>(weight[i]);					// ������ 1��° argument,
			cost = get<2>(weight[i]);					// ����ġ�� 2��° argument�� �̿�

			if (indegree[dst] > 0)						// dst�� ���� ������ 0���� ū �� �߿�
				if (Dist[dst] > Dist[src] + cost)		// src���� �ִ� �Ÿ� + (src->dst ������ ����ġ)��
					Dist[dst] = Dist[src] + cost;		// ������� ���� dst������ �ִ� ��κ��� �� �۴ٸ�
		}												// �� ���� dst������ �ִ� ��η� ����
	}

	// 4) ���� ����Ŭ �˻�
	for (int i = 0; i < n; i++)							// ��� ��忡 ���� �˻�
		if (beforeChk[i] != Dist[i]) {					// �ִ� ��� ����� n-1�� ������ ���� n�� ������ ���� �ٸ���
			cout << "\n���� ����Ŭ�� �����Ǿ����ϴ�. �����մϴ�.\n";
			return 0;									// ���� ����Ŭ�� �����ϴ� ������ �����ϰ�
		}												// ���α׷� ����

// 5) ��º� (���� ����Ŭ�� ���� ���)
	// Dist^(n-1) ���
	cout << "\n[Bellman-Ford Algorithm ���]";
	cout << "\nDist^" << n - 1 << " : ";
	for (int i = 0; i < n; i++)
		cout << beforeChk[i] << " ";
	cout << endl;

	// �� �ִ� ��� �� ���
	for (int i = 1; i < n; i++)
		cout << "0 -> " << i << " �ִ� ��� : " << beforeChk[i] << endl;

	return 0;
}