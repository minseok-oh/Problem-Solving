#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> spot;

void input(){
    cin >> n >> m;
    spot.resize(m);
    for(int i = 0; i < m; i++) cin >> spot[i];
}

bool count_light(int height){
    int cur = 0;
    for(int i = 0; i < m; i++){
        if(cur < spot[i] - height) return false;
        else{
            cur = spot[i] + height;
        }
    }

    if(n <= cur) return true;
    else return false;
}

void solve(){
    int left = 0, right = n;
    while(left <= right){
        int mid = (left + right) / 2;

        bool here = count_light(mid);
        if(!here){
            left = mid + 1;
        }
        else{
            right = mid - 1;
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