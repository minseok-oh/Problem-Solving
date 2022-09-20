#include <bits/stdc++.h>
using namespace std;
int n;
vector<pair<int, int>> study;

void input() {
    cin >> n;
    study.resize(n);

    pair<int, int> temp;
    for (int i = 0; i < n; i++) {
        cin >> temp.first >> temp.second;
        study[i] = temp;
    }
}

bool comp(pair<int, int>& p1, pair<int, int>& p2) {
    if(p1.second == p2.second) {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

void solve() {
    sort(study.begin(), study.end(), comp);

    int last = -1, count = 0;
    for(int i = 0; i < n; i++) {
        if (last <= study[i].first) {
            last = study[i].second;
            count++;
        }
    }
    cout << count << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}