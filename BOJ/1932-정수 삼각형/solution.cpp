#include <bits/stdc++.h>
using namespace std;
int n, triangle[501][501], memo[501][501];

void init() {
    for (int i = 0; i < 501; i++) {
        for (int j = 0; j < 501; j++) {
            memo[i][j] = -1;
        }
    }
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> triangle[i][j];
        }
    }
}

int operation(int y, int x) {
    if (y == n) return triangle[y][x];
    int& ret = memo[y][x];
    if (ret != -1) return ret;

    ret = max(operation(y + 1, x), operation(y + 1, x + 1)) + triangle[y][x];
    return ret;
}

void solve() {
    cout << operation(1, 1) << "\n";    
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    input();
    solve();
    return 0;
}