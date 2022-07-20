#include <bits/stdc++.h>
using namespace std;
int dp[1000001] = { 0, };
const int mod = 1000000009;

void init(){
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i <= 1000000; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
        dp[i] = (dp[i] + dp[i - 3]) % mod;
    }
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << dp[n] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}