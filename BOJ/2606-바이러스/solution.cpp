#include <bits/stdc++.h>
using namespace std;
int v, e;
bool graph[101][101] = { false, };
bool visited[101] = { false, };

void input(){
    cin >> v >> e;

    int first, second;
    for(int i = 0; i < e; i++){
        cin >> first >> second;
        graph[first][second] = graph[second][first] = true;
    }
}

int bfs(int start){
    queue<int> q;
    
    int res = 0;
    q.push(start); visited[start] = true;
    while(!q.empty()){
        int here = q.front(); q.pop();
        res++;

        for(int i = 1; i <= v; i++){
            if(graph[here][i] && !visited[i]){
                q.push(i);
                visited[i] = true;
            }
        }
    }
    return res - 1;
}

void solve(){
    int ans = bfs(1);
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}