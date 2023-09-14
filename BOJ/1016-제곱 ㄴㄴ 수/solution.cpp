#include <bits/stdc++.h>
using namespace std;
long long min_val, max_val;

void input() {
    cin >> min_val >> max_val;
}

void solve() {
    bool isSquare[1000001] = { false, };
    for (long long i = 2; i * i <= max_val; i++) {
        long long start = i * i - min_val % (i * i);
        if (start == i * i) start = 0;
        for (long long j = start; j <= max_val - min_val; j += i * i) {
            isSquare[j] = true;
        }
    }

    int count = 0;
    for (int i = 0; i <= max_val - min_val; i++) {
        if (!isSquare[i]) count++; 
    }
    cout << count << "\n";
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}