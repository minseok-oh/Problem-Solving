#include <bits/stdc++.h>
using namespace std;
int board[9][9];
bool isEnd = false;

void input() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
        }
    }
}

bool isChecked(int y, int x, int value) {
    bool ret = true;
    for (int i = 0; i < 9; i++) {
        if (board[y][i] == value) ret = false;
        if (board[i][x] == value) ret = false;
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[(y / 3) * 3 + i][(x / 3) * 3 + j] == value) ret = false;
        }
    }
    return ret;
}

void solve() {
    if (isEnd) return ;
    int y = -1, x = -1;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                y = i; x = j;
                break;
            }
        }
        if (y != -1 && x != -1) break;
    }

    if (y == -1 && x == -1) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                cout << board[i][j] << " ";
            }
            cout << "\n";
        }

        isEnd = true;
        return;
    } else {
        for (int i = 1; i <= 9; i++) {
            if (isChecked(y, x, i)) {
                board[y][x] = i;
                solve();
                board[y][x] = 0;
            }
        }
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}