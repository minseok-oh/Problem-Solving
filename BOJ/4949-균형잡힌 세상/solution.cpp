#include <bits/stdc++.h>
using namespace std;
string line;

void solve() {
    stack<char> s;
    for (int i = 0; line[i]; i++) {
        if (line[i] == '[' || line[i] == '(') s.push(line[i]);
        else if (line[i] == ']') {
            if (!s.empty() && s.top() == '[') s.pop();
            else s.push(']');   
        }
        else if (line[i] == ')') {
            if (!s.empty() && s.top() == '(') s.pop();
            else s.push(')');
        }
    }

    if (s.empty()) cout << "yes\n";
    else cout << "no\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    while (1) {
        getline(cin, line);
        if (line.size() == 1 && line[0] == '.') break;
        
        solve();
    }
    return 0;
}