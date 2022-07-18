#include <bits/stdc++.h>
using namespace std;
int dp[100001] = { 0, };
const int mod = 1000000009;

void init(){
    dp[1] = 1; dp[2] = 2; dp[3] = 2;
    dp[4] = 3; dp[5] = 3; dp[6] = 6; 
    for(int i = 7; i < 100001; i++){
        dp[i] = (dp[i - 2] + dp[i - 4]) % mod;
        dp[i] = (dp[i] + dp[i - 6]) % mod;
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