#include <bits/stdc++.h>
using namespace std;
int n, m, b;
int board[501][501];

void input() {
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
}

int limit_search(int limit) {
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int here = limit - board[i][j];
            if (here < 0) res += -2 * here;
            else res += here;
        }
    }
    return res;
}

void solve() {
    int inventory = b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            inventory += board[i][j];
        }
    }

    int t = 256 * 500 * 500 * 2, h;
    int len = min(inventory / (n * m), 256);
    for (int i = 0; i <= len; i++) {
        int here = limit_search(i);
        if (here <= t) {
            h = i;
            t = here;
        }
    }
    cout << t << " " << h << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}