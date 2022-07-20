#include <bits/stdc++.h>
using namespace std;
int v, e, k;
vector<pair<int, int>> adj[20001];

void input(){
    cin >> v >> e >> k;
    
    int from, to, dist;
    for(int i = 0; i < e; i++){
        cin >> from >> to >> dist;
        adj[from].push_back({to, dist});
    }
}

void dijkstra(){
    priority_queue<pair<int, int>> pq;
    vector<int> dist(v + 1, 987654321);

    pq.push({0, k}); dist[k] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int here_dist = -1 * pq.top().first; 
        pq.pop();
        if(dist[here] < here_dist) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int next = adj[here][i].first;
            int next_dist = adj[here][i].second;
            if(dist[next] > dist[here] + next_dist){
                dist[next] = dist[here] + next_dist;
                pq.push({-1 * dist[next], next});
            }
        }
    }

    for(int i = 1; i <= v; i++){
        if(dist[i] != 987654321) cout << dist[i] << "\n";
        else cout << "INF\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    dijkstra();
    return 0;
}