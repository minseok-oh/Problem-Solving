#include <bits/stdc++.h>
using namespace std;
int n, k, l;
bool board[102][102] = { false, };
bool apples[101][101] = { false, };
map<int, char> trans;

void input() {
    cin >> n >> k;
    for (int i = 0; i < n + 2; i++) {
        board[i][0] = board[0][i] = true;
        board[n + 1][i] = board[i][n + 1] = true;
    }
    
    int y, x;
    for (int i = 0; i < k; i++) {
        cin >> y >> x;
        apples[y][x] = true;
    }

    cin >> l;
    int t; char dir;
    for (int i = 0; i < l; i++) {
        cin >> t >> dir;
        trans[t] = dir;
    }
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };
const int l_dir[4] = { 2, 0, 3, 1 };
const int d_dir[4] = { 1, 3, 0, 2 };

void solve() {
    deque<pair<int, int>> snake;
    
    int ans = 0, here_dir = 3;
    snake.push_front(make_pair(1, 1));
    board[1][1] = true;
    while(1) {
        if (trans.find(ans) != trans.end()) {
            if (trans[ans] == 'L') here_dir = l_dir[here_dir];
            else if (trans[ans] == 'D') here_dir = d_dir[here_dir];
        }
        
        pair<int, int> head = snake.front();
        pair<int, int> tail = snake.back();
        head.first += y_grad[here_dir];
        head.second += x_grad[here_dir];
        
        snake.push_front(head);
        if (board[head.first][head.second]) break;
        board[head.first][head.second] = true;
        
        if (apples[head.first][head.second]) {
            apples[head.first][head.second] = false;
        } else {
            board[tail.first][tail.second] = false;
            snake.pop_back();
        }
        ans++;
    }
    cout << ans + 1 << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}