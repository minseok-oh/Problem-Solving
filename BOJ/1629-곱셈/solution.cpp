#include <bits/stdc++.h>
using namespace std;
int A, B, C;

long long multiply(int m) {
    if (m == 1) return A;

    if (m % 2 == 1) return (A * multiply(m - 1)) % C;
    else {
        long long midRet = multiply(m / 2) % C;
        return midRet * midRet % C;
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> A >> B >> C;

    A %= C;
    cout << multiply(B) << "\n";
    return 0;
}