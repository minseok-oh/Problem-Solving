#include <bits/stdc++.h>
using namespace std;
int n;
string board[26];
bool visited[26][26] = { false, };

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> board[i];
}

const int x_grad[4] = { -1, 0, 0, 1 };
const int y_grad[4] = { 0, -1, 1, 0 };

int bfs(int y, int x){
    queue<pair<int, int>> q;

    int count = 0;
    q.push(make_pair(y, x)); visited[y][x] = true;
    while(!q.empty()){
        int here_y = q.front().first, here_x = q.front().second;
        q.pop(); count++;

        for(int i = 0; i < 4; i++){
            int next_y = here_y + y_grad[i];
            int next_x = here_x + x_grad[i];

            if(next_y < 0 || next_y >= n || next_x < 0 || next_x >= n) continue;
            if(!visited[next_y][next_x] && board[next_y][next_x] == '1'){
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
            }
        }
    }
    return count;
}

void solve(){
    vector<int> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j] && board[i][j] == '1'){
                ans.push_back(bfs(i, j));
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto count: ans) cout << count << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}