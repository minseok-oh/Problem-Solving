#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<int> parent;

void input(){
    cin >> n;
    graph.resize(n + 1);
    parent.resize(n + 1);

    int first, second;
    for(int i = 0; i < n - 1; i++){
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
}


void bfs(int start){
    queue<int> q;
    vector<bool> visited(n + 1, false);

    q.push(start); visited[start] = true;
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int next: graph[here]){
            if(!visited[next]){
                parent[next] = here;
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void solve(){
    bfs(1);
    for(int i = 2; i <= n; i++){
        cout << parent[i] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}