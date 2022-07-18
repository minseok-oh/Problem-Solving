#include <bits/stdc++.h>
using namespace std;
vector<int> dp(11);

void init(){
    dp[1] = 1; dp[2] = 2; dp[3] = 4;
    for(int i = 4; i < 11; i++){
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
}

void solve(){
    int t;
    cin >> t;
    while(t--){
        int val;
        cin >> val;
        cout << dp[val] << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    init();
    solve();
    return 0;
}