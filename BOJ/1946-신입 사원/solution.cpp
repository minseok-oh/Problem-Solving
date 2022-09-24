#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> person;

void input() {
    cin >> n;
    person.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> person[i].first >> person[i].second;
    }
}

void solve() {
    int t;
    cin >> t;
    while(t--) {
        input();
        sort(person.begin(), person.end());
        
        int res = 1, temp = person[0].second;
        for(int i = 1; i < n; i++) {
            if (person[i].second < temp) {
                temp = person[i].second;
                res += 1;
            }
        }
        cout << res << "\n";
        person.clear();
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}