#include <bits/stdc++.h>
using namespace std;
int n, erase_node, start_node;
vector<int> parents;
vector<vector<int>> graph;

void input(){
    cin >> n;
    graph.resize(n);
    parents.resize(n);

    for(int i = 0; i < n; i++){
        cin >> parents[i];
        if(parents[i] == -1) start_node = i;
        else graph[parents[i]].push_back(i);
    }
    cin >> erase_node;
}

int ans = 0;
void bfs(int start){
    queue<int> q;
    q.push(start);

    while(!q.empty()){
        int here = q.front(); q.pop();
        if(here == erase_node){
            if(graph[parents[here]].size() == 1) ans++;
            continue;
        }
        
        if(graph[here].size() == 0){
            ans++;
        }
        else{
            for(int next: graph[here]){
                q.push(next);
            }
        }
    }
}

void solve(){
    bfs(start_node);
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}