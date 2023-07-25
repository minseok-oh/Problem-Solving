#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> arr;

void input() {
    cin >> n;
    arr.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    stack<int> s;

    int here = 0;
    string res = "";
    for (int i = 1; i <= n; i++) {
        s.push(i);
        res += "+\n";

        while (!s.empty() && s.top() == arr[here]) {
            s.pop();
            here++;
            res += "-\n";
        }
    }

    while (!s.empty() && s.top() == arr[here]) {
        s.pop();
        here++;
        res += "-\n";
    }

    if (s.empty()) cout << res;
    else cout << "NO\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}