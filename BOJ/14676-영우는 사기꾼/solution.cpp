#include <bits/stdc++.h>
using namespace std;
int n, m, k;
vector<vector<int>> graph;
vector<int> in; vector<int> cons;

void input(){
    cin >> n >> m >> k;
    in.resize(n + 1, 0); cons.resize(n + 1, 0); 
    graph.resize(n + 1);
    
    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v); in[v]++;
    }
}

bool make_building(int x){
    if(in[x] != 0) return false;
    if(cons[x]) return cons[x]++;

    for(int next: graph[x]) in[next]--;
    cons[x] = true;
    return true;
}

bool erase_building(int x){
    if(!cons[x]) return false;
    else if(--cons[x] == 0){
        for(int next: graph[x]) in[next]++;
    }
    return true;
}

void solve(){
    bool ans = true;
    int q, building;
    for(int i = 0; i < k; i++){
        cin >> q >> building;
        if(q == 1) ans &= make_building(building);
        else ans &= erase_building(building);
    }
    if(ans) cout << "King-God-Emperor\n";
    else cout << "Lier!\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}