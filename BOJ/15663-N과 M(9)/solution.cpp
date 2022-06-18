#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> num;
vector<bool> visited;

void input(){
	cin >> n >> m;
	num.resize(n); visited.resize(n, false);
	for(int i = 0; i < n; i++) cin >> num[i];
	sort(num.begin(), num.end());
}

vector<int> ret;
set<vector<int>> rets;
void solve(int k){
	if(k == m){
		rets.insert(ret);
		return ;
	}

	for(int i = 0; i < n; i++){
		if(visited[i]) continue;

		ret.push_back(num[i]); visited[i] = true;
		solve(k + 1);
		ret.pop_back(); visited[i] = false;
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve(0);
	for(vector<int> idx: rets){
		for(int l: idx) cout << l << " ";
		cout << "\n";
	}
	return 0;
}