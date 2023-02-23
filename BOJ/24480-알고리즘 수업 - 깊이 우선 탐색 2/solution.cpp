#include <bits/stdc++.h>
using namespace std;
int n, m, r;
vector<int> graph[100001];
vector<int> visited;

void input() {
    cin >> n >> m >> r;
    visited.resize(n + 1, 0);

    int u, v;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end());
}

int cnt = 1;
void dfs(int here) {
    visited[here] = cnt++;

    for (int i = graph[here].size()-1 ; i >= 0; i--) {
        int next = graph[here][i];
        if (visited[next] == 0) {
            dfs(next);
        }
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    dfs(r);
    for (int i = 1; i <= n; i++) cout << visited[i] << "\n";
    return 0;
}