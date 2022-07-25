#include <bits/stdc++.h>
using namespace std;
int t, p;
string w;

void input(){
    cin >> w >> p;
}

void solve(){
    cin >> t;
    while(t--){
        input();
        
        int cost = 0;
        priority_queue<pair<int, int>> pq;
        vector<bool> B(w.length(), true);
        for(int i = 0; w[i]; i++){
            pq.push({ w[i] - 'a' + 1, i });
            cost += w[i] - 'a' + 1;
        }

        while(cost > p){
            cost -= pq.top().first;
            B[pq.top().second] = false;
            pq.pop();
        }

        for(int i = 0; w[i]; i++){
            if(B[i]) cout << w[i];
        }
        cout << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}