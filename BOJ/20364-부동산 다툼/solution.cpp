#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> duck;
vector<bool> visited;

void input(){
    cin >> n >> q;
    duck.resize(q + 1);
    visited.resize(n + 1, false);
    for(int i = 1; i <= q; i++) cin >> duck[i];
}

int func(int d){
    int earth = 0, temp = d;
    while(temp != 0){
        if(visited[temp]){
            earth = temp;
        }
        temp /= 2;
    }

    if(earth == 0) visited[d] = true;
    return earth;
}

void solve(){
    for(int i = 1; i <= q; i++){
        int here = duck[i];
        cout << func(here) << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}