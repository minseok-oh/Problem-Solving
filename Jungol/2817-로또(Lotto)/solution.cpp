#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> arr;

void input(){
    cin >> k;
    arr.resize(k);
    for(int i = 0; i < k; i++) cin >> arr[i];
}

vector<int> ans;
void dfs(int here){
    if(ans.size() == 6){
        for(auto value: ans) cout << arr[value] << " ";
        cout << "\n";
        return ;
    }

    for(int i = here + 1; i < k; i++){
        ans.push_back(i);
        dfs(i);
        ans.pop_back();
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    dfs(-1);
    return 0;
}