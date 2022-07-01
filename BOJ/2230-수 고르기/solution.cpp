#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A;

void input(){
	cin >> n >> m;
	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
}

void solve(){
	sort(A.begin(), A.end());

	int left = 0, right = 0, res = 2000000001;
	while(left < n && right < n){
		int here = A[right] - A[left];
		if(here >= m) res = min(res, here);

		if(here < m){
			right++;
		}
		else{
			left++;
		}
	}
	cout << res << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}