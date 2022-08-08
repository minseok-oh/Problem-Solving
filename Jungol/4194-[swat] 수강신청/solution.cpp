#include <bits/stdc++.h>
using namespace std;
int n, b, c;
int a[1000001];

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    cin >> b >> c;
}

void solve(){
    long long ans = n;
    for(int i = 1; i <= n; i++){
        a[i] -= b;
        if(a[i] < 0) continue;
        ans += ceil(a[i] / (double)c);
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}