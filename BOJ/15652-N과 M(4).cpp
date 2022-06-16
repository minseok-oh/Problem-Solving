#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ans;

void solve(int k){
	if(ans.size() == m){
		for(int selected: ans) cout << selected << " ";
		cout << "\n";
		return ;
	}

	for(int i = k; i <= n; i++){
		ans.push_back(i);
		solve(i);
		ans.pop_back();
	}
}

int main(void){
	cin >> n >> m;
	solve(1);
	return 0;
}