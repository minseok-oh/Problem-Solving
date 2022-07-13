#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> in;
vector<vector<int>> graph;

void input(){
    cin >> n >> m;
    in.resize(n + 1, 0);
    graph.resize(n + 1);

    int u, v;
    for(int i = 0; i < m; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        in[v]++;
    }
}

void make_topology_sort(){
    queue<int> q;
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        int here = q.front(); q.pop();
        cout << here << " ";

        for(int next: graph[here]){
            in[next]--;
            if(in[next] == 0) q.push(next);
        }
    }
    cout << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    make_topology_sort();
    return 0;
}