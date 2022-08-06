#include <bits/stdc++.h>
using namespace std;
int n, m, r, c, s, k;

void input(){
    cin >> n >> m;
    cin >> r >> c;
    cin >> s >> k;
}

const int y_grad[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int x_grad[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int bfs(){
    queue<pair<int, int>> q;
    int board[1001][1001] = { 0, };

    board[r][c] = 1; q.push(make_pair(r, c));
    while(!q.empty()){
        int here_y = q.front().first, here_x = q.front().second;
        if(here_y == s && here_x == k){
            return board[s][k] - 1;
        }
        q.pop();

        for(int i = 0; i < 8; i++){
            int next_y = here_y + y_grad[i];
            int next_x = here_x + x_grad[i];
            if(next_y <= 0 || next_y > n || next_x <= 0 || next_x > m) continue;
            if(board[next_y][next_x] == 0){
                q.push(make_pair(next_y, next_x));
                board[next_y][next_x] = board[here_y][here_x] + 1;
            }
        }
    }
    return -1;
}

void solve(){
    cout << bfs() << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}