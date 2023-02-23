#include <bits/stdc++.h>
using namespace std;
int n, recur_ret = 0;

int fibo(int n) {
    if (n == 1 || n == 2) {
        recur_ret++;
        return 1;
    }
    else return (fibo(n - 1) + fibo(n - 2));
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    cin >> n;
    fibo(n);
    cout << recur_ret << " " << n - 2 << "\n";
    return 0;
}