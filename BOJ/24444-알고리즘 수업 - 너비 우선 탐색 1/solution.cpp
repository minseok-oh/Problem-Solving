#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> graph[100001];

void input() {
    cin >> n >> m >> r;
    
    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
}

void bfs() {
    int cnt = 1;
    queue<int> q;
    vector<int> visited(n + 1, 0);

    q.push(r); visited[r] = cnt++;
    while (!q.empty()) {
        int here = q.front(); q.pop();
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i];
            if (!visited[next]) {
                visited[next] = cnt++;
                q.push(next);    
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << visited[i] << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    bfs();
    return 0;
}