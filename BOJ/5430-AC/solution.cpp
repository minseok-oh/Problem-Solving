#include <bits/stdc++.h>
using namespace std;
int t, n;
string p, arr;
deque<int> dq;

void input() {
    cin >> p >> n >> arr;
}

void init() {
    while (!dq.empty()) dq.pop_front();

    if (n != 0) {
        for (int i = 1; arr[i]; i++) {
            int res = 0;
            for (; '0' <= arr[i] && arr[i] <= '9'; i++) {
                res *= 10;
                res += (arr[i] - '0');
            }
            dq.push_back(res);
        }
    }
}

void solve() {
    cin >> t;
    while (t--) {
        input();
        init();

        bool isHead = true, isError = false;
        for (int i = 0; p[i]; i++) {
            if (p[i] == 'R') {
                isHead = !isHead;
            } else if (p[i] == 'D') {
                if (dq.empty()) {
                    isError = true;
                    break;
                }

                if (isHead) dq.pop_front();
                else dq.pop_back();
            }
        }
        if (isError) {
            cout << "error\n";
            continue; 
        }

        cout << "[";
        if (isHead) {
            while (!dq.empty()) {
                cout << dq.front(); 
                dq.pop_front();
                if (!dq.empty()) cout << ",";
            }
        } else {
            while (!dq.empty()) {
                cout << dq.back();
                dq.pop_back();
                if (!dq.empty()) cout << ",";
            }
        }
        cout << "]\n";
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}