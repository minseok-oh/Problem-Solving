#include <bits/stdc++.h>
using namespace std;
long long a, r, n, mod;

void input(){
    cin >> a >> r >> n >> mod;
}

long long get_pow(long long value, long long pow_value){
    if(pow_value == 0) return 1;
    if(pow_value == 1) return value % mod;

    if(pow_value % 2 == 0){
        long long temp = get_pow(value, pow_value / 2) % mod;
        return (temp * temp) % mod;
    }
    else{
        return (value * (get_pow(value, pow_value - 1) % mod) % mod);
    }
}

long long func(long long start, long long end){
    if(start == end){
        return get_pow(r, start) % mod;
    }
    long long mid = (start + end) / 2;

    if((end - start + 1) % 2 == 0){
        long long head = func(start, mid) % mod;
        return (head + (head * (get_pow(r, mid - start + 1) % mod))) % mod;
    }
    else{
        return ((get_pow(r, start) % mod) + (func(start + 1, end) % mod)) % mod; 
    }
}

void solve(){
    cout << a * (func(0, n - 1) % mod) % mod << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}