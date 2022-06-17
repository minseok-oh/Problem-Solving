#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> ans;

void solve(int k){
	if(k == m + 1){
		for(int selected: ans) cout << selected << " ";
		cout << "\n";
		return ;
	}

	for(int i = 1; i <= n; i++){
		ans.push_back(i);
		solve(k + 1);
		ans.pop_back();
	}
}

int main(void){
	cin >> n >> m;
	solve(1);
	return 0;
}