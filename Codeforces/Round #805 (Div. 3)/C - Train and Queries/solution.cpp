#include <bits/stdc++.h>
using namespace std;
int t, n, k;
map<int, pair<int, int>> m;

void input(){
    cin >> n >> k;

    int u;
    for(int i = 0; i < n; i++){
        cin >> u;
        if(!m.count(u)){
            m[u].first = i;
            m[u].second = i;
        }
        else m[u].second = i;
    }
}

void solve(){
    cin >> t;
    while(t--){
        input();

        int start, finish;
        for(int i = 0; i < k; i++){
            cin >> start >> finish;
            if(!m.count(start) || !m.count(finish) || m[start].first > m[finish].second){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
        }
        m.clear();
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}