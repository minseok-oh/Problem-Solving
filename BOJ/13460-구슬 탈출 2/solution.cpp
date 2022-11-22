#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<string> board;

typedef struct _pos {
    int y, x;
}Pos;

Pos red, blue, hole;
void input() {
    cin >> n >> m;
    board.resize(n);

    for (int i = 0; i < n; i++) cin >> board[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 'R') {
                red.y = i; red.x = j;
                board[i][j] = '.';
            } else if (board[i][j] == 'B') {
                blue.y = i; blue.x = j;
                board[i][j] = '.';
            } else if (board[i][j] == 'O') {
                hole.y = i; hole.x = j;
            }
        }
    }
}

const int y_grad[4] = { -1, 1, 0, 0 };
const int x_grad[4] = { 0, 0, -1, 1 };
void solve() {
    queue<pair<Pos, Pos>> q;
    int visited[11][11][11][11] = { 0, };
    q.push(make_pair(red, blue));
    visited[red.y][red.x][blue.y][blue.x] = 1;

    while(!q.empty()) {
        Pos hereRed = q.front().first;
        Pos hereBlue = q.front().second; q.pop();
        if (visited[hereRed.y][hereRed.x][hereBlue.y][hereBlue.x] > 11) {
            cout << "-1\n";
            return;
        }

        if (hereBlue.y == hole.y && hereBlue.x == hole.x) {
            continue;
        }
        if (hereRed.y == hole.y && hereRed.x == hole.x) {
            cout << visited[hereRed.y][hereRed.x][hereBlue.y][hereBlue.x] - 1 << "\n";
            return;
        }

        Pos nextRed;
        Pos nextBlue;
        for (int dir = 0; dir < 4; dir++) {
            bool ok = true;
            if (dir == 0) {
                if (hereRed.y > hereBlue.y) ok = false;
            } else if (dir == 1) {
                if (hereRed.y < hereBlue.y) ok = false;
            } else if (dir == 2) {
                if (hereRed.x > hereBlue.x) ok = false;
            } else if (dir == 3) {
                if (hereRed.x < hereBlue.x) ok = false;
            }

            if (ok) {
                nextRed = hereRed;
                for (int i = 0; i < 11; i++) {
                    nextRed = {nextRed.y + y_grad[dir], nextRed.x + x_grad[dir]};
                    if (board[nextRed.y][nextRed.x] != '.') break;
                }
                if (board[nextRed.y][nextRed.x] != 'O') {
                    nextRed = {nextRed.y - y_grad[dir], nextRed.x - x_grad[dir]};
                    board[nextRed.y][nextRed.x] = 'X';
                }

                nextBlue = hereBlue;
                for (int i = 0; i < 11; i++) {
                    nextBlue = {nextBlue.y + y_grad[dir], nextBlue.x + x_grad[dir]};
                    if (board[nextBlue.y][nextBlue.x] != '.') break;
                }
                if (board[nextBlue.y][nextBlue.x] != 'O') {
                    nextBlue = {nextBlue.y - y_grad[dir], nextBlue.x - x_grad[dir]};
                }
                if (board[nextRed.y][nextRed.x] != 'O') board[nextRed.y][nextRed.x] = '.';
            } else {
                nextBlue = hereBlue;
                for (int i = 0; i < 11; i++) {
                    nextBlue = {nextBlue.y + y_grad[dir], nextBlue.x + x_grad[dir]};
                    if (board[nextBlue.y][nextBlue.x] != '.') break;
                }
                if (board[nextBlue.y][nextBlue.x] != 'O') {
                    nextBlue = {nextBlue.y - y_grad[dir], nextBlue.x - x_grad[dir]};
                    board[nextBlue.y][nextBlue.x] = 'X';
                }

                nextRed = hereRed;
                for (int i = 0; i < 11; i++) {
                    nextRed = {nextRed.y + y_grad[dir], nextRed.x + x_grad[dir]};
                    if (board[nextRed.y][nextRed.x] != '.') break;
                }
                if (board[nextRed.y][nextRed.x] != 'O') {
                    nextRed = {nextRed.y - y_grad[dir], nextRed.x - x_grad[dir]};
                }
                if (board[nextBlue.y][nextBlue.x] != 'O') board[nextBlue.y][nextBlue.x] = '.';
            }

            if (!visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x]) {
                visited[nextRed.y][nextRed.x][nextBlue.y][nextBlue.x] = visited[hereRed.y][hereRed.x][hereBlue.y][hereBlue.x] + 1;
                q.push(make_pair(nextRed, nextBlue));
            }
        }
    }
    cout << "-1\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}