#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> h;

void input(){
    cin >> n;
    h.resize(n);
    for(int i = 0; i < n; i++) cin >> h[i];
}

void solve(){
    long long ans = 0;
    stack<int> s;
    for(int i = 0; i < n; i++){
        if(s.empty()){
            s.push(h[i]);
        }
        else{
            while(!s.empty() && s.top() <= h[i]){
                s.pop();
            }

            ans += s.size();
            s.push(h[i]);
        }
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}