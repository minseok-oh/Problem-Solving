#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<vector<int>> graph;
vector<short> visited;

void input(){
    cin >> n;
    graph.resize(n + 1);
    visited.resize(n + 1, -1);
    
    int u, v;
    for(int i = 0; i < n; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

bool bfs(int start){
    queue<int> q;

    q.push(start); visited[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        
        for(int next: graph[here]){
            if(visited[next] == -1){
                visited[next] = visited[here]^1;
                q.push(next);
            }
            else if(visited[here] == visited[next]){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    cin >> t;
    while(t--){
        input();

        bool ans = true;
        for(int i = 1; i <= n; i++){
            if(graph[i].size() > 2) ans = false;
        }

        for(int i = 1; i <= n; i++){
            if(visited[i] == -1){
                ans &= bfs(i);
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";

        graph.clear();
        visited.clear();
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}