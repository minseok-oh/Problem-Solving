#include <bits/stdc++.h>
using namespace std;
int n, m, dist[1001][1001] = { 0, };
vector<vector<int>> graph;
vector<int> parent, depth;

void input(){
    cin >> n >> m;
    graph.resize(n + 1);
    depth.resize(n + 1, -1);
    parent.resize(n + 1);

    int u, v, d;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v >> d;
        graph[u].push_back(v);
        graph[v].push_back(u);
        dist[u][v] = dist[v][u] = d;
    }
}

void make_tree(int here){
    for(int next: graph[here]){
        if(depth[next] == -1){
            depth[next] = depth[here] + 1;
            parent[next] = here;
            make_tree(next);
        }
    }
}

int func(int u, int v){
    int cost = 0;
    while(u != v){
        if(depth[u] >= depth[v]){
            cost += dist[u][parent[u]];
            u = parent[u];
        }
        else{
            cost += dist[v][parent[v]];
            v = parent[v];
        }
    }
    return cost;
}

void solve(){
    depth[1] = 0;
    make_tree(1);

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        cout << func(u, v) << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}