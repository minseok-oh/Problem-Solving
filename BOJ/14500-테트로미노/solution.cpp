#include <bits/stdc++.h>
using namespace std;
int n, m;
int board[510][510];
const int padding = 3;

const int poly[19][2][4] = {
    {
        { 0, 0, 0, 0 }, { 0, 1, 2, 3 },
    },
    {
        { 0, 1, 2, 3 }, { 0, 0, 0, 0 },
    },
    {
        { 0, 0, 1, 1 }, { 0, 1, 0, 1 },
    },
    {
        { 0, 1, 2, 2 }, { 0, 0, 0, 1 },
    },
    {
        { 0, 1, 0, 0 }, { 0, 0, 1, 2 },
    },
    {
        { 0, 0, 1, 2 }, { 0, 1, 1, 1 },
    },
    {
        { 0, 0, 0, -1 }, { 0, 1, 2, 2 },
    },
    {
        { 0, 1, 1, 2 }, { 0, 0, 1, 1 },
    },
    {
        { 0, 0, -1, -1 }, { 0, 1, 1, 2 },
    },
    {
        { 0, 0, 0, 1 }, { 0, 1, 2, 1 },
    },
    {
        { 0, 0, -1, 1 }, { 0, 1, 1, 1 },
    },
    {
        { 0, 0, 0, -1 }, { 0, 1, 2, 1 },
    },
    {
        { 0, 1, 2, 1 }, { 0, 0, 0, 1 },
    },
    {
        { 0, 0, -1, -2 }, { 0, 1, 1, 1 },
    },
    {
        { 0, 1, 1, 1 }, { 0, 0, 1, 2 },
    },
    {
        { 0, 0, 1, 2 }, { 0, 1, 0, 0 },
    },
    {
        { 0, 0, 0, 1 }, { 0, 1, 2, 2 },
    },
    {
        { 0, -1, -1, -2 }, { 0, 0, 1, 1 },
    },
    {
        { 0, 0, 1, 1 }, { 0, 1, 1, 2 },
    },
};

void init() {
    for (int i = 0; i < 510; i++) {
        for (int j = 0; j < 510; j++) {
            board[i][j] = 0;
        }
    }    
}

void input() {
    cin >> n >> m;
    
    for (int i = padding; i < n + padding; i++) {
        for (int j = padding; j < m + padding; j++) {
            cin >> board[i][j];
        }
    }
}

int sumPoly(int func, int y, int x) {
    int res = 0, here_y, here_x;
    for (int i = 0; i < 4; i++) {
        here_y = y + poly[func][0][i];
        here_x = x + poly[func][1][i];
        res += board[here_y][here_x];
    }
    return res;
}

void solve() {
    int ret = 0;
    for (int i = padding; i < n + padding; i++) {
        for (int j = padding; j < m + padding; j++) {
            for (int k = 0; k < 19; k++) {
                ret = max(ret, sumPoly(k, i, j));
            }
        }
    }
    cout << ret << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    input();
    solve();
    return 0;
}