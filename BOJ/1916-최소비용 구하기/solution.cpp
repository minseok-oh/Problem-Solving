#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> adj[1001];

void input(){
    cin >> n >> m;
    
    int u, v, d;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
}

void dijkstra(int start, int finish){
    priority_queue<pair<int, int>> pq;
    vector<int> dist(n + 1, 987654321); 

    pq.push({0, start}); dist[start] = 0;
    while(!pq.empty()){
        int here = pq.top().second;
        int d = -1 * pq.top().first; pq.pop();

        if(dist[here] < d) continue;

        for(int i = 0; i < adj[here].size(); i++){
            int next = adj[here][i].first;
            int next_dist = adj[here][i].second;
            if(dist[next] > dist[here] + next_dist){
                dist[next] = dist[here] + next_dist;
                pq.push({-1 * dist[next], next});
            }
        }
    }
    cout << dist[finish] << "\n";
}

void solve(){
    int start, finish;
    cin >> start >> finish;
    dijkstra(start, finish);
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}