#include <bits/stdc++.h>
using namespace std;
int n, m, x, y, k;
int board[21][21];
vector<int> op;

void input() {
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
        }
    }
    
    op.resize(k);
    for (int i = 0; i < k; i++) cin >> op[i];
}

const int grad[4][6] = {
    { 5, 3, 2, 0, 4, 1 },
    { 3, 5, 2, 1, 4, 0 },
    { 2, 4, 1, 3, 0, 5 },
    { 4, 2, 0, 3, 1, 5 },
};
const int y_grad[4] = { 0, 0, -1, 1 };
const int x_grad[4] = { 1, -1, 0, 0 };

void solve() {
    pair<int, int> here = { y, x };
    int here_state[6] = { 0, 1, 2, 3, 4, 5 };
    int here_dice[6] = { 0, 0, 0, 0, 0, 0 };

    for (int i = 0; i < k; i++) {
        int op_code = op[i] - 1;
        pair<int, int> next = { here.first + y_grad[op_code], here.second + x_grad[op_code] };
        if (next.first < 0 || next.first >= n || next.second < 0 || next.second >= m) continue;
        
        here = next;
        int temp_state[6];
        for (int j = 0; j < 6; j++) temp_state[j] = here_state[grad[op_code][j]];
        for (int j = 0; j < 6; j++) here_state[j] = temp_state[j];

        if (board[here.first][here.second] != 0) {
            here_dice[here_state[1]] = board[here.first][here.second];
            board[here.first][here.second] = 0;
        } else {
            board[here.first][here.second] = here_dice[here_state[1]];
        }
        cout << here_dice[here_state[0]] << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}