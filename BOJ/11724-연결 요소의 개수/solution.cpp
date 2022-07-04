#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[1001];
bool visited[1001] = { false, };

void input(){
	cin >> n >> m;

	int first, second;
	for(int i = 0; i < m; i++){
		cin >> first >> second;
		graph[first].push_back(second);
		graph[second].push_back(first);
	}
}

void dfs(int here){
	if(visited[here]) return ;
	visited[here] = true;

	for(int i = 0; i < graph[here].size(); i++){
		int next = graph[here][i];
		dfs(next);
	}
}

void solve(){
	int ans = 0;
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			dfs(i);
			ans++;
		}
	}
	cout << ans << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}