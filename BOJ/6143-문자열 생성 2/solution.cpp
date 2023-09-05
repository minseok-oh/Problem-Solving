#include <bits/stdc++.h>
using namespace std;
int n;
vector<char> s;

void input() {
    cin >> n;
    s.resize(n);
    for (int i = 0; i < n; i++) cin >> s[i];
}

bool check_deque(int left, int right) {
    bool isLeft = false;
    while (left != right) {
        if (s[left] < s[right]) {
            isLeft = true;
            break;
        }
        else if (s[left] > s[right]) {
            isLeft = false;
            break;
        }
        else {
            left++;
            right--;
        }
    }
    return isLeft;
}

void solve() {
    int count = 0;
    int left = 0, right = s.size() - 1;

    while (left != right) {
        count++;
        if (s[left] < s[right]) {
            cout << s[left];
            left++;
        }
        else if (s[left] > s[right]) {
            cout << s[right];
            right--;
        }
        else {
            bool isLeft = check_deque(left, right);
            if (isLeft) {
                cout << s[left]; 
                left++;
            } 
            else {
                cout << s[right];
                right--;
            }
        }
        if (count % 80 == 0) cout << "\n";
    }
    cout << s[left];
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}