#include <bits/stdc++.h>
using namespace std;
int n, m, max_value;
vector<int> budget;

void input(){
    cin >> n;

    budget.resize(n);
    for(int i = 0; i < n; i++){
        cin >> budget[i];
        max_value = max(max_value, budget[i]);
    }
    sort(budget.begin(), budget.end());

    cin >> m;
}

int make_cost(int highest){
    int ret = 0;
    for(int i = 0; i < n; i++){
        if(budget[i] < highest) ret += budget[i];
        else ret += highest;
    }
    return ret;
}

void solve(){
    int left = 1, right = max_value;
    while(left <= right){
        int mid = (left + right) / 2;

        int here = make_cost(mid);
        if(here > m){
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