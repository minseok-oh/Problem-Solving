#include <bits/stdc++.h>
using namespace std;
int w, h;
string board[51];
int visited[51][51] = { 0, };

void input(){
    cin >> w >> h;
    for(int i = 0; i < w; i++) cin >> board[i];
}

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };
int bfs(int y, int x){
    queue<pair<int, int>> q;
    int visited[51][51] = { 0, };
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            visited[i][j] = -1;
        }
    }
    
    q.push(make_pair(y, x));
    visited[y][x] = 0;
    
    int ret = -1;
    while(!q.empty()){
        int here_y = q.front().first;
        int here_x = q.front().second; q.pop();
        if(ret < visited[here_y][here_x]) ret = visited[here_y][here_x];
        
        for(int i = 0; i < 4; i++){
            int next_y = here_y + y_grad[i];
            int next_x = here_x + x_grad[i];
            if(next_y < 0 || next_y >= w || next_x < 0 || next_x >= h) continue;
            if(visited[next_y][next_x] == -1 && board[next_y][next_x] == 'L'){
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = visited[here_y][here_x] + 1;
            }
        }
    }
    return ret;
}

void solve(){
    int ans = -1;
    for(int i = 0; i < 51; i++){
        for(int j = 0; j < 51; j++){
            if(board[i][j] == 'L'){
                int here = bfs(i, j);
                ans = max(here, ans);
            }
        }
    }
    
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}