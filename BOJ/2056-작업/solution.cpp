#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> in, make_time;
vector<vector<int>> graph;

void input(){
    cin >> n;
    in.resize(n + 1, 0); make_time.resize(n + 1);
    graph.resize(n + 1);

    int t, v;
    for(int i = 1; i <= n; i++){
        cin >> make_time[i];
        cin >> t;
        while(t--){
            cin >> v;
            in[i]++;
            graph[v].push_back(i);
        }
    }
}

void make_topology_sort(){
    queue<int> q;
    vector<int> max_time(n + 1, 0);
    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
            max_time[i] = make_time[i];
        }
    }

    int ans = 0;
    while(!q.empty()){
        int here = q.front(); q.pop();
        ans = max(ans, max_time[here]);

        for(int next: graph[here]){
            in[next]--;
            max_time[next] = max(max_time[next], max_time[here] + make_time[next]);
            if(in[next] == 0){
                q.push(next);
            }
        }
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    make_topology_sort();
    return 0;
}