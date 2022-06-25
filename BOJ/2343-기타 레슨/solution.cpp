#include <bits/stdc++.h>
using namespace std;
int n, m, max_value;
long long sum_time;
vector<int> blue_ray;

void input(){
    cin >> n >> m;

    blue_ray.resize(n);
    for(int i = 0; i < n; i++){
        cin >> blue_ray[i];
        sum_time += blue_ray[i];
        max_value = max(max_value, blue_ray[i]);
    }
}

int count_split(long long time){
    int res = 0;
    long long sum = 0;
    for(int i = 0; i < n; i++){
        if(sum + blue_ray[i] <= time){
            sum += blue_ray[i];
        }
        else{
            sum = blue_ray[i];
            res++;
        }
    }
    return res;
}

void solve(){
    long long left = max_value, right = sum_time;
    while(left <= right){
        long long mid = (left + right) / 2;

        int here = count_split(mid);
        if(here < m){
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }
    }
    cout << left << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}