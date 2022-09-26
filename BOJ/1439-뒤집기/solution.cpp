#include <bits/stdc++.h>
using namespace std;
string s;

void solve() { 
    cin >> s;
    
    int zero = 0, one = 0;

    if(s[0] == '0') zero++;
    else if(s[0] == '1') one++;
    for(int i = 1; s[i]; i++) {
        if(s[i - 1] == '0' && s[i] == '1') {
            one++;
        }
        else if (s[i - 1] == '1' && s[i] == '0') {
            zero++;
        }
    }
    cout << min(zero, one) << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}