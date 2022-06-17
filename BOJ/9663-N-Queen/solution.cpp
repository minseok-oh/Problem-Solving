#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;
int queens[15];

bool isChecked(int k, int spot){
	for(int i = 0; i < k; i++){
		if(queens[i] == spot) return false;
		if(i + queens[i] == k + spot) return false;
		if(i - queens[i] == k - spot) return false;
	}
	return true;
}

void solve(int k){
	if(k == n){
		ans++;
		return ;
	}

	for(int i = 0; i < n; i++){
		if(isChecked(k, i)){
			queens[k] = i;
			solve(k + 1);
		}
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	cin >> n;
	solve(0);
	cout << ans << "\n";
	return 0;
}