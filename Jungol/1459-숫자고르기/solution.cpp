#include <bits/stdc++.h>
using namespace std;
int n, arr[101];
bool visited[101] = { false, };
vector<int> ans;

void input(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arr[i];
}

void bfs(int x){
    queue<int> q;
    bool here_visited[101] = { false, };

    q.push(x);
    visited[x] = here_visited[x] = true;
    while(!q.empty()){
        int here = q.front(); q.pop();

        int next = arr[here];
        if(visited[next] == true){
            if(here_visited[next] == true){
                int h = arr[next]; ans.push_back(next);
                while(next != h){
                    ans.push_back(h);
                    h = arr[h];
                }
            }
            return ;
        }
        else{
            q.push(next);
            visited[next] = here_visited[next] = true;
        }
    }
}

void bfs_all(){
    for(int i = 1; i <= n; i++){
        if(!visited[i]){
            bfs(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for(auto i: ans) cout << i << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    bfs_all();
    return 0;
}