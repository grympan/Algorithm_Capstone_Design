#include <iostream>
#include <algorithm>
using namespace std;
#define col 16
#define row 12

int main() {
    int charge[row][col];
    int consume[row][col];
    int remain[row][col];
    int cap, garo, sero;

    cin >> cap >> garo >> sero;

    for (int c = 0; c < sero; c++)          // 충전량 지도
        for (int r = 0; r < garo; r++)
            cin >> charge[c][r];

    for (int c = 0; c < sero; c++)          // 소모량 지도
        for (int r = 0; r < garo; r++)
            cin >> consume[c][r];

    remain[0][0] = cap;                     
    for (int r = 1; r < garo; r++) {        // 가로 첫줄 잔량 계산
        if (remain[0][r - 1] < 0)
            remain[0][r] = remain[0][r - 1];

        else if (remain[0][r - 1] < consume[0][r])
                 remain[0][r] = -100;
        else
            remain[0][r] = min(cap, remain[0][r - 1] - consume[0][r] + charge[0][r]);
    }

    for (int c = 1; c < sero; c++) {        // 세로 첫줄 잔량 계산
        if (remain[c-1][0] < 0)           
            remain[c][0] = remain[c-1][0];

        else if (remain[c-1][0] < consume[c][0])
            remain[c][0] = -100;

        else
            remain[c][0] = min(cap, remain[c-1][0] - consume[c][0] + charge[c][0]);
    }

    int dia, left, down;
    int temp;

    for (int c = 1; c < sero; c++) {
        for (int r = 1; r < garo; r++) {
            if (remain[c - 1][r - 1] < 0)
                dia = -100;
            else if (remain[c - 1][r - 1] < 1.4 * consume[c][r])
                dia = -100;
            else
                dia = min(cap, int(remain[c - 1][r - 1] - 1.4 * consume[c][r] + charge[c][r]));

            if (remain[c][r-1] < 0)
                left = -100;
            else if (remain[c][r-1] < consume[c][r])
                left = -100;
            else
                left = min(cap, int(remain[c][r-1] - consume[c][r] + charge[c][r]));

            if (remain[c-1][r] < 0)
                down = -100;
            else if (remain[c-1][r] < consume[c][r])
                down = -100;
            else
                down = min(cap, int(remain[c-1][r] - consume[c][r] + charge[c][r]));

            temp = max(dia, left);
            remain[c][r] = max(temp, down);
        }
    }

    cout << remain[sero - 1][garo - 1];
}