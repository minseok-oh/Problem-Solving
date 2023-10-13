#include <bits/stdc++.h>
using namespace std;
int n, m, k;
const int MAX = 1000000;
long long values[MAX], tree[4 * MAX + 1];

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> values[i];
}

void init(int node, int left, int right) {
    if (left == right) {
        tree[node] = values[left];
        return ;
    }
    
    int mid = (left + right) / 2;
    init(node * 2, left, mid);
    init(node * 2 + 1, mid + 1, right);
    tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

long long sum(int L, int R, int node, int left, int right) {
    if (right < L || R < left) return 0;
    if (L <= left && right <= R) return tree[node];
    
    int mid = (left + right) / 2;
    return sum(L, R, node * 2, left, mid) + sum(L, R, node * 2 + 1, mid + 1, right);
}

void update(int node, int left, int right, long long diff, int index) {
    if (left <= index && index <= right) tree[node] += diff;
    else return ;
    
    if (left == right) return;
    
    int mid = (left + right) / 2;
    update(node * 2, left, mid, diff, index);
    update(node * 2 + 1, mid + 1, right, diff, index);
}

void print(int i) {
    cout << "#" << i << ": ";
    for (int i = 0; i < 4 * n; i++) cout << tree[i] << " ";
    cout << "\n";
}

void solve() {
    init(1, 0, n - 1);
    
    long long a, b, c;
    for (int i = 0; i < m + k; i++) {
        //print(i);
        cin >> a >> b >> c;
        if (a == 1) {
            update(1, 0, n - 1, c - values[b - 1], b - 1);
            values[b - 1] = c;
        }
        else {
            cout << sum(b - 1, c - 1, 1, 0, n - 1) << "\n";
        }
    }
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}