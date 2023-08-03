#include <bits/stdc++.h>
using namespace std;
int n, m, board[1025][1025] = { 0, };
int prefixSum[1025][1025] = { 0, };

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
}

void makePrefixSum() {
    for (int i = 1; i <= n; i++) {
        prefixSum[1][i] = board[1][i] + prefixSum[1][i-1];
        prefixSum[i][1] = board[i][1] + prefixSum[i-1][1];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            prefixSum[i][j] = board[i][j] + prefixSum[i-1][j] + 
                prefixSum[i][j-1] - prefixSum[i-1][j-1];
        }
    }
}

void solve() {
    makePrefixSum();

    int x1, y1, x2, y2;
    for (int i = 0; i < m; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cout << prefixSum[x2][y2] - prefixSum[x2][y1-1] - prefixSum[x1-1][y2] + prefixSum[x1-1][y1-1] << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}