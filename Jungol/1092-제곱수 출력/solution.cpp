#include <bits/stdc++.h>
using namespace std;
long long x, y;
const int mod = 20091024;

void input(){
    cin >> x >> y;
}

long long split_pow(long long here, long long n){
    if(n == 0) return 1;
    else if(n == 1) return here % mod;

    if(n % 2 == 0){
        long long next = split_pow(here, n / 2) % mod;
        return (next * next) % mod;
    }
    else{
        return here * split_pow(here, n - 1) % mod;
    }
}

void solve(){
    cout << split_pow(x, y) << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}