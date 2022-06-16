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

	for(int i = k + 1; i <= n; i++){
		ans.push_back(i);
		solve(i);
		ans.pop_back();
	}
}

int main(void){
	cin >> n >> m;
	solve(0);
	return 0;
}