#include <bits/stdc++.h>
using namespace std;
int n, s, ans = 0;
vector<int> num;

void input(){
    cin >> n >> s;
    int temp;
    for(int i = 0; i < n; i++){
        cin >> temp;
        num.push_back(temp);
    }
}

vector<int> selected;
void solve(int k){
    if(k == n){
        int ret = 0;
        for(int m: selected) ret += num[m];
        if(selected.size() != 0 && ret == s) ans++;
        return ;
    }

    selected.push_back(k);
    solve(k + 1);
    selected.pop_back();
    solve(k + 1);
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve(0);
    cout << ans << "\n";
    return 0;
}