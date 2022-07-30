#include <bits/stdc++.h>
using namespace std;
int t, n;
string s;

void input(){
    cin >> n >> s;
}

void solve(){
    cin >> t;
    while(t--){
        input();
        bool visited[26] = { false, };

        int ans = 0;
        for(int i = 0; s[i]; i++){
            if(!visited[s[i] - 'A']){
                visited[s[i] - 'A'] = true;
                ans += 2;
            }
            else{
                ans += 1;
            }
        }
        cout << ans << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}