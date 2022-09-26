#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> cards;

void input() {
    cin >> n;
    cards.resize(n);
    for(int i = 0; i < n; i++) cin >> cards[i];
}

void solve() {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++) pq.push(cards[i]);

    long long res = 0;
    while(!pq.empty()) {
        long long first = pq.top(); pq.pop();
        if(pq.empty()) break;
        long long second = pq.top(); pq.pop();

        res += (first + second);
        pq.push(first + second);
    }
    cout << res << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}