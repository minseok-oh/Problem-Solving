#include <bits/stdc++.h>
using namespace std;
int n;
string board[101];
bool visited[101][101];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> board[i];
}

void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }
}

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };
void dfs(int y, int x) {
    const char here = board[y][x];

    for (int i = 0; i < 4; i++) {
        int nextY = y + y_grad[i];
        int nextX = x + x_grad[i];
        if (nextY < 0 || nextY >= n || nextX < 0 || nextX >= n) continue;

        if (!visited[nextY][nextX] && board[nextY][nextX] == here) {
            visited[nextY][nextX] = true;
            dfs(nextY, nextX);
        }
    }
}

void dfs_all() {
    init();

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                dfs(i, j); res++;
            }
        }
    }
    cout << res << " ";
}

void convertR2G() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R') board[i][j] = 'G';
        }
    }
}

void solve() {
    dfs_all();
    convertR2G();
    dfs_all();
    cout << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}