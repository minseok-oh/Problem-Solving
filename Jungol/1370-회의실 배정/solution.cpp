#include <bits/stdc++.h>
using namespace std;
int n;

struct Seminar{
    int idx;
    pair<int, int> plan;
};
vector<Seminar> seminar;

void input(){
    cin >> n;
    seminar.resize(n + 1);
    
    int idx, start, end;
    for(int i = 1; i <= n; i++){
        cin >> idx >> start >> end;
        seminar[i].idx = idx;
        seminar[i].plan = make_pair(start, end);
    }
}

bool comp(const Seminar& p1, const Seminar& p2){
    return p1.plan.second < p2.plan.second;
}

void solve(){
    sort(seminar.begin() + 1, seminar.end(), comp);
    
    int last_end = 0;
    vector<int> ans;
    for(int i = 1; i <= n; i++){
        if(seminar[i].plan.first >= last_end){
            last_end = seminar[i].plan.second;
            ans.push_back(seminar[i].idx);
        }
    }

    cout << ans.size() << "\n";
    for(int v: ans) cout << v << " ";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}