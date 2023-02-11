#include <bits/stdc++.h>
using namespace std;
int x, y;
const int months[13] = {
    0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
};
const string days[7] = {
    "MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

void solve() {
    int ret = 0;
    for (int i = 1; i < x; i++) ret += months[i];
    ret += (y - 1);
    cout << days[ret % 7] << "\n";
}

int main (void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> x >> y;
    solve();
    return 0;
}