#include <bits/stdc++.h>
using namespace std;
int n, m, targetY, targetX;
short board[1001][1001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 2) {
                targetX = j; targetY = i;
            }
        }
    }
}

int res[1001][1001];
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = -1;
            if (board[i][j] == 0 || board[i][j] == 2) 
                res[i][j] = 0;
        }
    }
}

void printResult() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}

const short y_grad[4] = { -1, 0, 0, 1 };
const short x_grad[4] = { 0, -1, 1, 0 };
void solve() {
    queue<pair<int, int>> q;
    q.push(make_pair(targetY, targetX));
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = y + y_grad[i];
            if (nextY < 0 || nextY >= n) continue;
        
            int nextX = x + x_grad[i];
            if (nextX < 0 || nextX >= m) continue;

            if (board[nextY][nextX] == 1 && res[nextY][nextX] == -1) {
                res[nextY][nextX] = res[y][x] + 1;
                q.push(make_pair(nextY, nextX));
            }
        } 
    }
    printResult();
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    init();
    solve();
    return 0;
}