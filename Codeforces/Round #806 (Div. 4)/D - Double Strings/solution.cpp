#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<string> s;
map<string, bool> mp;

void input(){
    cin >> n;
    s.resize(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
        mp[s[i]] = true;
    }
}

void solve(){
    cin >> t;
    while(t--){
        input();
        for(int i = 0; i < n; i++){
            bool ok = false;
            for(int j = 1; s[i][j]; j++){
                string pre = s[i].substr(0, j), post = s[i].substr(j, s[i].length() - j);
                if(mp[pre] && mp[post]) ok = true;
            }
            cout << ok;
        }
        cout << "\n";
        s.clear();
        mp.clear();
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}