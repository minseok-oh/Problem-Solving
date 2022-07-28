#include <bits/stdc++.h>
using namespace std;
int n, m, in[101] = { 0, };
long long value_count[101][101] = { 0, }; 
vector<int> adj[101]; 

void input(){
    cin >> n >> m;
    
    int u, v, w;
    for(int i = 0; i < m; i++){
        cin >> u >> v >> w;
        in[u] += w;
        for(int j = 0; j < w; j++){
            adj[v].push_back(u);
        }
    }
}

vector<int> base_idx;
void topology_sort(){
    queue<int> q;
    bool visited[101] = { false, };

    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
            visited[i] = true;
            value_count[i][i] = 1;
            base_idx.push_back(i);
        }
    }
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(auto next: adj[here]){
            in[next]--;
            for(int i = 1; i <= n; i++) 
                value_count[next][i] += value_count[here][i];

            if(!visited[next] && in[next] == 0){
                q.push(next);
                visited[next] = true;
            }
        }
    }
}

void solve(){
    topology_sort();
    for(int i: base_idx){
        cout << i << " " << value_count[n][i] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}