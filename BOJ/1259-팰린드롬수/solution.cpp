#include <bits/stdc++.h>
using namespace std;
string in;

void solve() {
    while(1) {
        cin >> in;
        if (in == "0") break;
        
        deque<char> dq;
        for (int i = 0; in[i]; i++) dq.push_back(in[i]);

        bool isPalindrome = true;
        while (dq.size() > 1) {
            char head = dq.front(); dq.pop_front();
            char tail = dq.back(); dq.pop_back();
            
            if (head != tail) isPalindrome = false;
        }
        
        if (isPalindrome) cout << "yes\n";
        else cout << "no\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}