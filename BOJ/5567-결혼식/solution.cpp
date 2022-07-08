#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<vector<int>> graph;

void input(){
    cin >> n >> m;
    graph.resize(n + 1);

    int first, second;
    for(int i = 0; i < m; i++){
        cin >> first >> second;
        graph[first].push_back(second);
        graph[second].push_back(first);
    }
}

void bfs(int start){
    queue<int> q;
    int visited[501] = { 0, };

    q.push(start); visited[start] = 1;
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int next: graph[here]){
            if(!visited[next]){
                q.push(next);
                visited[next] = visited[here] + 1;
            }
        }
    }

    int ans = 0;
    for(int i = 2; i <= n; i++){
        if(1 < visited[i] && visited[i] < 4) ans++;
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    bfs(1);
    return 0;
}