#include <bits/stdc++.h>
using namespace std;
int n, m;
bool board[101][101];

struct robots{
    int y, x;
    int dir;
};

robots start, finish;
void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> board[i][j];
        }
    }
    cin >> start.y >> start.x >> start.dir;
    cin >> finish.y >> finish.x >> finish.dir;
    start.y--; start.x--;
    finish.y--; finish.x--;
}

const int dir_grad[5][2] = {{0, 0}, {4, 3}, {3, 4}, {1, 2}, {2, 1}};
const int y_grad[5][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {1, 2, 3}, {-1, -2, -3}};
const int x_grad[5][3] = {{0, 0, 0}, {1, 2, 3}, {-1, -2, -3}, {0, 0, 0}, {0, 0, 0}};

int bfs(){
    queue<robots> q;
    int op_count[101][101][5] = { 0, };
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            op_count[i][j][1] = -1;
            op_count[i][j][2] = -1;
            op_count[i][j][3] = -1;
            op_count[i][j][4] = -1;
        }
    }
    
    q.push(start); op_count[start.y][start.x][start.dir] = 0;
    while(!q.empty()){
        robots here = q.front(); q.pop();
        if(here.y == finish.y && here.x == finish.x && here.dir == finish.dir){
            return op_count[here.y][here.x][here.dir];
        }
        
        for(int i = 0; i < 3; i++){
            robots next = 
                { here.y + y_grad[here.dir][i], here.x + x_grad[here.dir][i], here.dir};
            if(next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
            if(op_count[next.y][next.x][next.dir] != -1) continue;
            if(board[next.y][next.x]) break;
                
            q.push(next);
            op_count[next.y][next.x][next.dir] = op_count[here.y][here.x][here.dir] + 1;
        }
        
        for(int i = 0; i < 2; i++){
            robots next = { here.y, here.x, dir_grad[here.dir][i] };
            if(op_count[next.y][next.x][next.dir] != -1) continue;
            op_count[next.y][next.x][next.dir] = op_count[here.y][here.x][here.dir] + 1;
            q.push(next);
        }
    }
    return -1;
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    cout << bfs() << "\n";
    return 0;
}