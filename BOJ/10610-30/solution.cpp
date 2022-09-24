#include <bits/stdc++.h>
using namespace std;
int sum = 0; bool zero = false;
vector<char> res; string n;

void init() {
    for(int i = 0; n[i]; i++) {
        if (n[i] == '0' && zero == false) {
            zero = true;
        }
        else {
            sum += (n[i] - '0');
            res.push_back(n[i]);
        }
    }
}

void solve() {
    cin >> n;
    init();
    sort(res.begin(), res.end(), greater<char>());

    if (zero == false || (sum % 3) != 0) {
        cout << "-1\n";
    }
    else {
        for(int i = 0; i < res.size(); i++) {
            cout << res[i];
        }
        cout << "0\n";
    }
}

int  main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}