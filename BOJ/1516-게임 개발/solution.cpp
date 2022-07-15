#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int>> graph;
vector<int> in, make_time;

void input(){
    cin >> n;
    graph.resize(n + 1);
    in.resize(n + 1, 0); make_time.resize(n + 1);

    for(int i = 1; i <= n; i++){
        cin >> make_time[i];
        
        int temp;
        cin >> temp;
        while(temp != -1){
            graph[temp].push_back(i);
            in[i]++;
            cin >> temp;
        }
    }
}

void make_topology_sort(){
    queue<int> q;
    vector<int> ans(n + 1, 0);

    for(int i = 1; i <= n; i++){
        if(in[i] == 0){
            q.push(i);
            ans[i] = make_time[i];
        }
    }
    while(!q.empty()){
        int here = q.front(); q.pop();

        for(int next: graph[here]){
            in[next]--;
            ans[next] = max(ans[next], ans[here] + make_time[next]);
            if(in[next] == 0){
                q.push(next);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        cout << ans[i] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    make_topology_sort();
    return 0;
}