#include <bits/stdc++.h>
using namespace std;
int n, board[17][17];

typedef struct _house {
    int y, x;
    int dir;
}House;

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> board[i][j];
        }
    }
}

const int y_grad[3][3] = {
    { 0, -1, 1 },
    { -1, 1, 1 },
    { 0, 1, 1 },
};
const int x_grad[3][3] = {
    { 1, -1, 1 },
    { -1, 0, 1 },
    { 1, 0, 1 },
};

void solve() {
    int res = 0;
    
    queue<House> q;
    q.push({ 1, 2, 0 });
    while (!q.empty()) {
        House here = q.front(); q.pop();
        if (here.y == n && here.x == n) {
            res++;
            continue;
        }
        
        for (int i = 0; i < 3; i++) {
            if (y_grad[here.dir][i] == -1 || x_grad[here.dir][i] == -1) continue;
            House there = { 
                here.y + y_grad[here.dir][i], here.x + x_grad[here.dir][i], i 
            };
            
            if (!(1 <= there.y && there.y <= n && 1 <= there.x && there.x <= n)) continue;
            if (board[there.y][there.x] == 1) continue;
            if (there.dir == 2 && (board[there.y - 1][there.x] == 1 || board[there.y][there.x - 1] == 1)) continue;
            q.push(there);
        }
    }
    cout << res << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}