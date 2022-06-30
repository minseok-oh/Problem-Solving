#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> dolls;
const int MAX = 1000001;

void input(){
	cin >> n >> k;
	dolls.resize(n);
	for(int i = 0; i < n; i++) cin >> dolls[i];
}

void solve(){
	int left = 0, right = 0, count = 0, res = MAX;
	if(dolls[0] == 1) count++;
	while(left < n && right < n){
		if(count == k) res = min(res, right - left + 1);

		if(count < k){
			right++;
			if(dolls[right] == 1) count++;
		}
		else{
			if(dolls[left] == 1) count--;
			left++;
		}
	}
	if(res == MAX) cout << "-1\n";
	else cout << res << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}