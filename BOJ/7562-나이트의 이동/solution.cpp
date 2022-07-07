#include <bits/stdc++.h>
using namespace std;
int l;
pair<int, int> start, finish;

void input(){
    cin >> l;
    cin >> start.first >> start.second;
    cin >> finish.first >> finish.second;
}

const int y_grad[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
const int x_grad[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };

int bfs(){
    queue<pair<int, int>> q;
    int visited[301][301] = { 0, };

    q.push(start); visited[start.first][start.second] = 1;
    while(!q.empty()){
        pair<int, int> here = q.front(); q.pop();
        if(here == finish) return visited[here.first][here.second] - 1;

        for(int i = 0; i < 8; i++){
            pair<int, int> next = make_pair(here.first + y_grad[i], here.second + x_grad[i]);
            if(0 <= next.first && next.first < l && 0 <= next.second && next.second < l){
                if(visited[next.first][next.second] == 0){
                    q.push(next);
                    visited[next.first][next.second] = visited[here.first][here.second] + 1;
                }
            }
        }
    }
    return 0;
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        input();
        cout << bfs() << "\n";;
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}