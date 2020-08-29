#include <iostream>
using namespace std;

void path(int q, int r);

int P[6][6] = { 0, };

int main() {
	int n, m, w, a, b;
	int W[6][6];
	int D[6][6] = { 0, };

	for (int i = 0; i <= 5; i++)
		for (int j = 0; j <= 5; j++)
			W[i][j] = 100;

	for (int i = 1; i <= 5; i++)
		W[i][i] = 0;

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b >> w;
		W[a][b] = w;
	}

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			P[i][j] = 0;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			D[i][j] = W[i][j];

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (D[i][k] + D[k][j] < D[i][j]) {
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}

	int src[11] = { 0, }, dst[11] = { 0, };

	int t = 0;
	for (;;) {
		cin >> a;
		if (a == 0) break;
		cin >> b;
		src[t] = a;
		dst[t] = b;
		t++;
	}

	for (int i = 0; i < t; i++) {
		if (D[src[i]][dst[i]] != 100) {
			cout << D[src[i]][dst[i]] << " ";
			cout << src[i];
			path(src[i], dst[i]);
			cout << " " << dst[i] << endl;
		}

		else
			cout << 0 << endl;
	}

	return 0;
}

void path(int q, int r) {
	if (P[q][r] != 0) {
		path(q, P[q][r]);
		cout << " " << P[q][r];
		path(P[q][r], r);
	}
}