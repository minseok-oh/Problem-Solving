#include <bits/stdc++.h>
using namespace std;
int n, r, q;
vector<vector<int>> graph;

void input(){
    cin >> n >> r >> q;
    graph.resize(n + 1);

    int u, v;
    for(int i = 0; i < n - 1; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

int memo[100001] = { 0, };
bool visited[100001] = { false, };
int make_tree(int here){
    int ret = memo[here];
    if(ret != 0) return ret;

    for(int next: graph[here]){
        if(!visited[next]){
            visited[next] = true;
            ret += make_tree(next);
        }
    }
    return memo[here] = ret + 1;
}

void solve(){
    visited[r] = true;
    make_tree(r);
    
    int query;
    for(int i = 0; i < q; i++){
        cin >> query;
        cout << memo[query] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}