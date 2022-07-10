#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;

void input(){
    cin >> n;
    graph.resize(n + 1);

    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int bfs(int start){
    int res = 0;
    queue<int> q;
    vector<int> visited(n + 1, -1);

    q.push(start); visited[start] = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();

        bool isLeaf = true;
        for(int next: graph[here]){
            if(visited[next] == -1){
                q.push(next);
                isLeaf = false;
                visited[next] = visited[here] + 1;
            }
        }
        if(isLeaf) res += visited[here];
    }
    return res;
}

void solve(){
    int floor = bfs(1);
    if(floor % 2 == 0){
        cout << "No\n";
    }
    else{
        cout << "Yes\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}