#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> cons_time, in;
vector<vector<int>> graph;

void init(){
    cons_time.clear(); in.clear();
    graph.clear();
}

void input(){
    cin >> n >> k;
    cons_time.resize(n + 1), in.resize(n + 1, 0);
    graph.resize(n + 1);

    for(int i = 1; i <= n; i++) cin >> cons_time[i];
    int u, v;
    for(int i = 0; i < k; i++){
        cin >> u >> v;
        graph[u].push_back(v);
        in[v]++;
    }
}

int make_topology_sort(int finish){
    queue<int> q;
    vector<int> res(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
            res[i] = cons_time[i];
        }
    }

    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == finish) return res[here];

        for(int next: graph[here]){
            in[next]--;
            res[next] = max(res[next], cons_time[next] + res[here]);
            if(in[next] == 0) q.push(next);
        }
    }
    return res[finish];
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        init();
        input();

        int last;
        cin >> last;
        cout << make_topology_sort(last) << "\n";
    }
    return 0;
}