#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ans;
vector<bool> visited;

void solve(int k){
	if(k == m + 1){
		for(int selected: ans) cout << selected << " ";
		cout << "\n";
		return ;
	}

	for(int i = 1; i <= n; i++){
		if(visited[i]) continue;
		ans.push_back(i); visited[i] = true;
		solve(k + 1);
		ans.pop_back(); visited[i] = false;
	}
}

int main(void){
	cin >> n >> m;
	visited.resize(n + 1, false);
	solve(1);
	return 0;
}