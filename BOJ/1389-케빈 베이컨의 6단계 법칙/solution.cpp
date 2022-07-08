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

int bfs(int start){
    queue<int> q;
    int visited[101] = { 0, };

    q.push(start); visited[start] = 1;
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int next: graph[here]){
            if(!visited[next]){
                visited[next] = visited[here] + 1;
                q.push(next);
            }
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        ans += (visited[i] - 1);
    }
    return ans;
}

void solve(){
    int ans = 987654321, min_ans = 0;
    for(int i = 1; i <= n; i++){
        int here = bfs(i);
        if(ans > here){
            ans = here;
            min_ans = i;
        }
    }
    cout << min_ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}