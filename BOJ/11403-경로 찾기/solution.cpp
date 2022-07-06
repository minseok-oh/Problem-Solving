#include <bits/stdc++.h>
using namespace std;
int n;
bool graph[101][101] = { false, };

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> graph[i][j];
        }
    }
}

void bfs(int start){
    queue<int> q;
    bool visited[101] = { false, };

    q.push(start); visited[start] = true;
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int i = 0; i < n; i++){
            if(graph[here][i]){
                graph[start][i] = true;
                if(!visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
}

void solve(){
    for(int i = 0; i < n; i++){
        bfs(i);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << graph[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}