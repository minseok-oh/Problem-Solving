#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, dir, res = 0;
vector<vector<int>> room;

void input() {
    cin >> n >> m;
    vector<int> cell(m, 0);
    for (int i = 0; i < n; i++) room.push_back(cell);

    cin >> r >> c >> dir;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
        }
    }
}

typedef struct _robot {
    int x, y;
    int dir;
}Robot;

const int r_left[4] = { 3, 0, 1, 2 };
const int r_back[4] = { 2, 3, 0, 1 };
const int y_grad[4] = { -1, 0, 1, 0 };
const int x_grad[4] = { 0, 1, 0, -1 };

void dfs(int y, int x, int dir, int count) {
    room[y][x] = -1;

    int nextY = y + y_grad[r_back[dir]];
    int nextX = x + x_grad[r_back[dir]];
    if (count == 4) {
        if (room[nextY][nextX] != 1) {
            dfs(nextY, nextX, dir, 0);
        } else {
            int clean = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (room[i][j] == -1) {
                        clean++;
                    }
                }
            }
            cout << clean << "\n";
        }
        return;
    }
    
    nextY = y + y_grad[r_left[dir]];
    nextX = x + x_grad[r_left[dir]];
    if (room[nextY][nextX] == 0) {
        dfs(nextY, nextX, r_left[dir], 0);
    } else {
        dfs(y, x, r_left[dir], count + 1);
    }
}

void solve() {
    dfs(r, c, dir, 0);
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}