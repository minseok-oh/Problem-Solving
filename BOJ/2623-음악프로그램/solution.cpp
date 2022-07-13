#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> in;
vector<vector<int>> graph;

void input(){
    cin >> n >> m;
    in.resize(n + 1);
    graph.resize(n + 1);

    int t, u, v;
    for(int i = 0; i < m; i++){
        cin >> t >> u;
        for(int j = 0; j < t - 1; j++){
            cin >> v;
            graph[u].push_back(v);
            in[v]++; u = v;
        }
    }
}

void make_topology_sort(){
    queue<int> q;
    vector<int> res;
    for(int i = 1; i <= n; i++)
        if(in[i] == 0) q.push(i);

    while(!q.empty()){
        int here = q.front(); q.pop();
        res.push_back(here);

        for(int next: graph[here]){
            in[next]--;
            if(in[next] == 0) q.push(next);
        }
    }

    if(res.size() != n) cout << "0\n";
    else{
        for(int here: res) cout << here << "\n";
    }
}

int main(void){
    cin.tie(0);
    input();
    make_topology_sort();
    return 0;
}