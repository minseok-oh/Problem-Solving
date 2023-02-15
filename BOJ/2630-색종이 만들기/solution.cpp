#include <bits/stdc++.h>
using namespace std;
int n, white = 0, blue = 0;
short board[129][129];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
}

void makePaper(int y, int x, int size) {
    short value = board[y][x];

    bool isPaper = true;
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (board[i][j] != value) isPaper = false;
        }
    }

    if (isPaper) {
        if (value == 0) white++;
        else blue++;
    } else {
        size /= 2;
        makePaper(y, x, size);
        makePaper(y + size, x, size);
        makePaper(y, x + size, size);
        makePaper(y + size, x + size, size);
    }
}

void solve() {
    makePaper(0, 0, n);
    cout << white << "\n";
    cout << blue << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}