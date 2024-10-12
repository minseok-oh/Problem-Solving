#include <bits/stdc++.h>
using namespace std;
string line, bomb;
stack<char> s;

void input() {
    cin >> line >> bomb;
}

void check() {
    int size = bomb.size();
    vector<char> temp;
    
    for (int i = 0; bomb[i]; i++) {
        char top = s.top();
        if (top == bomb[size - i - 1]) {
            s.pop();
            temp.push_back(top);
        }
        else {
            break;
        }
    }
    
    if (temp.size() != size) {
        for (int i = 0; i < temp.size(); i++) {
            s.push(temp[temp.size() - i - 1]);
        }
    }
}

void solve() {
    int i = 0, size = bomb.size();
    
    while (line[i]) {
        s.push(line[i]);
        if (s.size() >= size && line[i] == bomb[size - 1]) {
            check();
        }
        i++;
    }
    
    if (s.size() == 0) {
        cout << "FRULA\n";
    }
    else {
        string result = "";
        while (!s.empty()) {
            result += s.top();
            s.pop();
        }
        reverse(result.begin(), result.end());
        cout << result << "\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}