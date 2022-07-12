#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> in;
int parent[1000001], depth[1000001];

void init(){
    in.clear();
    for(int i = 0; i < 1000001; i++){
        parent[i] = depth[i] = -1;
    }
}

void input(){
    in.resize(n); 
    for(int i = 0; i < n; i++) cin >> in[i];
}

void make_tree(){
    int here_idx = 0; depth[in[0]] = 0;
    for(int i = 1; i < n; i++){
        for(; in[i] + 1 == in[i + 1] && i + 1 < n; i++){
            parent[in[i]] = in[here_idx];
            depth[in[i]] = depth[in[here_idx]] + 1;
        }

        parent[in[i]] = in[here_idx];
        depth[in[i]] = depth[in[here_idx]] + 1;
        here_idx++;
    }
}

int count_cousin(int node){
    int res = 0;
    for(int here: in){
        if(depth[here] == depth[node] && parent[here] != parent[node]){
            if(parent[here] == -1 || parent[node] == -1) continue;
            if(parent[parent[here]] == parent[parent[node]]){
                res++;
            }
        }
    }
    return res;
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    while(1){
        cin >> n >> k;
        if(n == 0 && k == 0) break;
        init();
        input();

        make_tree();
        cout << count_cousin(k) << "\n";
    }
    return 0;
}