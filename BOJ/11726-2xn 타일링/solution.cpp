#include <bits/stdc++.h>
using namespace std;
vector<int> dp(1001);
const int mod = 10007;

void init(){
    dp[1] = 1; dp[2] = 2;
    for(int i = 3; i < 1001; i++){
        dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
    }
}

void solve(){
    int val;
    cin >> val;
    cout << dp[val] << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}