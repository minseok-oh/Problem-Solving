#include <bits/stdc++.h>
using namespace std;
int r, c;
char board[21][21];
bool visited[21][21] = { false, };
bool alphabet_visited[26] = { false, };

void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        string line;
        cin >> line;
        
        for (int j = 0; j < c; j++) {
            board[i][j] = line[j];
        }
    }
}

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };
int moveBoard(int y, int x) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int next_y = y + y_grad[i];
        int next_x = x + x_grad[i];
        if (!(0 <= next_y && next_y < r) || !(0 <= next_x && next_x < c)) {
            continue;
        }
        
        if (visited[next_y][next_x]) {
            continue;
        }
        
        char next = board[next_y][next_x];
        if (next < 'A' || 'Z' < next) {
            continue;
        }
        if (alphabet_visited[next - 'A']) {
            continue;
        }
        
        visited[next_y][next_x] = true;
        alphabet_visited[next - 'A'] = true;
        ret = max(ret, moveBoard(next_y, next_x));
        visited[next_y][next_x] = false;
        alphabet_visited[next - 'A'] = false;
    }
    return ret + 1;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    
    visited[0][0] = true;
    alphabet_visited[board[0][0] - 'A'] = true;
    cout << moveBoard(0, 0) << "\n";
    return 0;
}