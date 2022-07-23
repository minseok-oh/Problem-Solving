#include <bits/stdc++.h>
using namespace std;
int t;
vector<string> str;

void input(){
    cin >> t;
    str.resize(t);
    for(int i = 0; i < t; i++) cin >> str[i];
}

void solve(){
    for(int i = 0; i < t; i++){
        int days = 1;
        bool visited[26] = { false, };
        stack<int> visited_idx;

        for(int j = 0; str[i][j]; j++){
            if(!visited[str[i][j] - 'a']){
                if(visited_idx.size() == 3){
                    days++;
                    while(!visited_idx.empty()){
                        visited[visited_idx.top()] = false;
                        visited_idx.pop();
                    }
                }
                
                visited_idx.push(str[i][j] - 'a');
                visited[str[i][j] - 'a'] = true;
            }
        }
        cout << days << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}