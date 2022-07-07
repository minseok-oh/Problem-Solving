#include <bits/stdc++.h>
using namespace std;
int n, m, x, y;
vector<vector<int>> graph;

void input(){
    cin >> n;
    cin >> x >> y;
    graph.resize(n + 1);

    cin >> m;
    int first, second;
    for(int i = 0; i < m; i++){
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
}

int bfs(int start, int finish){
    queue<int> q;
    int visited[101] = { 0, };

    q.push(start); visited[start] = 1;
    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == finish) return visited[here] - 1;

        for(int next: graph[here]){
            if(!visited[next]){
                visited[next] = visited[here] + 1;
                q.push(next);
            }
        }
    }
    return -1;
}

void solve(){
    int ans = bfs(x, y);
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}