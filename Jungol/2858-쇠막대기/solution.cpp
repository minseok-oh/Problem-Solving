#include <bits/stdc++.h>
using namespace std;
string info;

void input(){
    cin >> info;
}

void solve(){
    int ans = 0, here = 0;
    for(int i = 0; info[i]; i++){
        if(info[i] == '('){
            if(info[i + 1] == ')'){
                ans += here;
                i++;
            }
            else here++;
        }
        else{
            ans++;
            here--;
        }
    }
    cout << ans << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}