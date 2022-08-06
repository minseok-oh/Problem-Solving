#include <bits/stdc++.h>
using namespace std;
int w, h;
bool board[101][101] = { false, };
short visited[101][101];

void input(){
    cin >> w >> h;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            cin >> board[i][j];
        }
    }
}


const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };
void one_node(int y, int x){
    queue<pair<int, int>> q;
    short temp_board[101][101];
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            temp_board[i][j] = board[i][j];
        }
    }

    q.push(make_pair(y, x)); visited[y][x] = true;
    while(!q.empty()){
        int here_y = q.front().first;
        int here_x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int next_y = here_y + y_grad[i];
            int next_x = here_x + x_grad[i];

            if(next_y <= 0 || next_y > w || next_x <= 0 || next_x > h) continue;
            if(!board[next_y][next_x] && !visited[next_y][next_x]){
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true; 
            }
            else if(board[next_y][next_x] && !visited[next_y][next_x]){
                board[next_y][next_x] = 0;
                visited[next_y][next_x] = true;
            }
        }
    }
}

void one_hour(){
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            visited[i][j] = false;
        }
    }

    one_node(1, 1);
}

int count_cheese(){
    int cheese = 0;
    for(int i = 1; i <= w; i++){
        for(int j = 1; j <= h; j++){
            cheese += board[i][j];
        }
    }
    return cheese;
}

void solve(){
    int hours = 0, before_hour;
    while(1){
        int here = count_cheese();
        if(here == 0) break;

        one_hour();
        hours++;
        before_hour = here;
    }
    cout << hours << "\n";
    cout << before_hour << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}