#include <bits/stdc++.h>
using namespace std;
int t;
string s;

const char yes_data[3][2] = {{'y', 'Y'},
                             {'e', 'E'},
                             {'s', 'S'},};

void solve(){
    cin >> t;
    while(t--){
        cin >> s;

        bool ans = true;
        for(int i = 0; s[i]; i++){
            if(s[i] != yes_data[i][0] && s[i] != yes_data[i][1]){
                ans = false;
            }
        }
        if(ans) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}