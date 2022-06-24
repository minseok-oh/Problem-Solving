#include <bits/stdc++.h>
using namespace std;
int k, n;
vector<long long> lan;

void input(){
    cin >> k >> n;

    lan.resize(k);
    for(int i = 0; i < k; i++) cin >> lan[i];
    sort(lan.begin(), lan.end());
}

long long count_lans(long long length){
    long long res = 0;
    for(int i = 0; i < k; i++){
        res += (lan[i] / length);
    }
    return res;
}

void solve(){
    long long left = 1;
    long long right = LLONG_MAX - 1;
    while(left <= right){
        long long mid = (left + right) / 2;

        long long here = count_lans(mid);
        if(here < n){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << right << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}