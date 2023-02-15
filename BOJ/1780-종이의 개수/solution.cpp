#include <bits/stdc++.h>
using namespace std;
int n, res[3] = { 0, };
short board[2500][2500];

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

    if (isPaper) res[value + 1]++;
    else {
        size /= 3;
        makePaper(y, x, size);
        makePaper(y, x + size, size);
        makePaper(y, x + 2 * size, size);
        
        makePaper(y + size, x, size);
        makePaper(y + size, x + size, size);
        makePaper(y + size, x + 2 * size, size);

        makePaper(y + 2 * size, x, size);
        makePaper(y + 2 * size, x + size, size);
        makePaper(y + 2 * size, x + 2 * size, size);
    }
}

void solve() {
    makePaper(0, 0, n);
    for (int ret: res) cout << ret << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}