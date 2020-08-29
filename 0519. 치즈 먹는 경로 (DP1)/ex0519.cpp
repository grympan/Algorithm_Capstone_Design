#include <iostream>
#include <algorithm>
using namespace std;
#define col 20
#define row 20

int main() {
    int p[col][row];

    int n, m;
    cin >> n >> m;

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            cin >> p[c][r];

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
          if (p[c][r] == 2)
               p[c][r] = -100;
    
    for (int r = n - 1; r > 0; r--)
        p[0][r-1] = p[0][r];

    for (int c = 0; c - 1 < m; c++)
        p[c + 1][n - 1] = p[c][n - 1];

    for (int r = n - 2; r >= 0; r--)
        for (int c = 1; c < m; c++) {
            if (r == n - 1 && c == 0) continue;
            if (p[c][r] == 1)
                p[c][r] = max(p[c - 1][r], p[c][r + 1]) + 1;
            else
                p[c][r] += max(p[c - 1][r], p[c][r + 1]);
        }

    //for (int r = 0; r < n; r++) {
    //    for (int c = 0; c < m; c++)
    //        cout << p[c][r] << " ";
    //    cout << endl;
    //}


    cout << p[m-1][0];
}