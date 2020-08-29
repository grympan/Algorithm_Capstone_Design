#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define SIZE 100
bool map[SIZE][SIZE][SIZE];


void seek(int z, int y, int x, int R, int N) {
	int xmin, xmax, ymin, ymax, zmin, zmax;

	if (z + R >= N - 1) zmax = N - 1;
	else zmax = z + R;
	if (z - R < 0) zmin = 0;
	else zmin = z - R;

	if (y + R >= N - 1) ymax = N - 1;
	else ymax = y + R;
	if (y - R < 0) ymin = 0;
	else ymin = y - R;

	if (x + R >= N - 1) xmax = N - 1;
	else xmax = x + R;
	if (x - R < 0) xmin = 0;
	else xmin = x - R;


	for (; zmax > zmin; zmax--)
		for (; ymax > ymin; ymax--)
			for (; xmax > xmin; xmax--)
				if (map[zmax][ymax][xmax] == 1){
					seek(zmax, ymax, xmax, R, N);
					map[zmax][ymax][xmax] = 0;
				}
}

int main() {
	int R, N, group =0;

	cin >> R >> N;

	for(int z = 0; z < N; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++)
				cin >> map[z][y][x];

	for (int z = 0; z < N; z++)
		for (int y = 0; y < N; y++)
			for (int x = 0; x < N; x++) {
				if (map[z][y][x] == 1) {
					group++;
					seek(z, y, x, R, N);
				}
			}

	cout << group;
}