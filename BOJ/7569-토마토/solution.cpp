#include <bits/stdc++.h>
using namespace std;
int m, n, h;
short boxes[101][101][101];

struct tomato{
    int f, y, x, day;
};

void input(){
    cin >> m >> n >> h;

    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin >> boxes[k][i][j];
            }
        }
    }
}

const int h_grad[6] = { -1, 1, 0, 0, 0, 0 };
const int y_grad[6] = { 0, 0, -1, 1, 0, 0 };
const int x_grad[6] = { 0, 0, 0, 0, -1, 1 };

void bfs(){
    queue<tomato> q;
    bool visited[101][101][101] = { false, };

    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(boxes[k][i][j] == 1){
                    q.push({ k, i, j, 0 });
                    visited[k][i][j] = true;
                }
                else if(boxes[k][i][j] == -1){
                    visited[k][i][j] = true;
                }
            }
        }
    }

    int ans = -1;
    while(!q.empty()){
        tomato here = q.front(); q.pop();
        ans = max(ans, here.day);

        for(int i = 0; i < 6; i++){
            tomato next = 
                { here.f + h_grad[i], here.y + y_grad[i], here.x + x_grad[i], here.day + 1 };
            if(next.f < 0 || next.f >= h) continue;
            if(next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
            
            if(!boxes[next.f][next.y][next.x] && !visited[next.f][next.y][next.x]){
                visited[next.f][next.y][next.x] = true;
                q.push(next);
            }
        }
    }
    
    for(int k = 0; k < h; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(visited[k][i][j] == 0){
                    cout << "-1\n";
                    return ;
                }
            }
        }
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    bfs();
    return 0;
}