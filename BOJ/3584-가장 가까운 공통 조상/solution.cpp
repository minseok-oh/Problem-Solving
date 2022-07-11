#include <bits/stdc++.h>
using namespace std;
int n, root;
vector<vector<int>> graph;
vector<int> depth, parent;

void init(){
    graph.clear();
    depth.clear();
    parent.clear();
}

void input(){
    cin >> n;
    graph.resize(n + 1);
    depth.resize(n + 1, -1);
    parent.resize(n + 1);

    int u, v;
    bool isRoot[n + 1] = { false, };
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        isRoot[v] = true;
    }

    for(int i = 1; i <= n; i++){
        if(!isRoot[i]) root = i;
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

void solve(int u, int v){
    while(u != v){
        if(depth[u] >= depth[v]){
            u = parent[u];
        }
        else{
            v = parent[v];
        }
    }
    cout << u << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        init();
        input();

        depth[root] = 0;
        make_tree(root);

        int u, v;
        cin >> u >> v;
        solve(u, v);
    }
    return 0;
}