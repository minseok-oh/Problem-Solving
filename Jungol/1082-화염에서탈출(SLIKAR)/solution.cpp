#include <bits/stdc++.h>
using namespace std;
int w, h;
string board[51];

void input(){
    cin >> w >> h;
    for(int i = 0; i < w; i++) cin >> board[i];
}

struct node{
    int y, x;
    char c;
};

const int y_grad[4] = { -1, 0, 0, 1 };
const int x_grad[4] = { 0, -1, 1, 0 };
int count_hour(){
    deque<node> dq;
    int hours[51][51];
    
    node house;
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            hours[i][j] = -1;
            if(board[i][j] == '*'){
                dq.push_front({ i, j, '*' });
            }
            else if(board[i][j] == 'S'){
                dq.push_back({ i, j, 'S' });
                hours[i][j] = 0;
                board[i][j] = '.';
            }
            else if(board[i][j] == 'D'){
                house.y = i;
                house.x = j;
                house.c = 'D';
            }
        }
    }
    
    while(!dq.empty()){
        node here = dq.front(); dq.pop_front();
        if(here.c == 'S' && here.y == house.y && here.x == house.x){
            return hours[here.y][here.x];
        }
        
        for(int i = 0; i < 4; i++){
            node next = { here.y + y_grad[i], here.x + x_grad[i], here.c };
            if(next.y < 0 || next.y >= w || next.x < 0 || next.x >= h) continue;
            
            if(next.c == '*'){
                if(board[next.y][next.x] == '.'){
                    dq.push_back(next);
                    board[next.y][next.x] = '*';
                }
            }
            if(next.c == 'S' && hours[next.y][next.x] == -1){
                if(board[next.y][next.x] == '.' || board[next.y][next.x] == 'D'){
                    dq.push_back(next);
                    hours[next.y][next.x] = hours[here.y][here.x] + 1;
                }
            }
        }
    }
    return -1;
}

void solve(){
    int ans = count_hour();
    if(ans == -1) cout << "impossible" << "\n";
    else cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}