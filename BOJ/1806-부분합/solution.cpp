#include <bits/stdc++.h>
using namespace std;
int n, s;
vector<int> A;

void input(){
	cin >> n >> s;
	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
}

void solve(){
	int left = 0, right = 0, res = 100000;
	
	int sum = A[0];
	while(left < n && right < n){
		if(sum < s){
			right = right + 1;
			sum += A[right];
		}
		else{
			res = min(res, right - left + 1);
			sum -= A[left];
			left = left + 1;
		}
	}
	if(res == 100000) cout << "0\n";
	else cout << res << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}