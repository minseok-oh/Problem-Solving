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
	int left = 0, right = 0, res = 0;

	int sum = A[0];
	while(left < n && right < n){
		if(sum == m) res++;
		
		if(sum <= m){
			right++;
			sum += A[right];
		}
		else{
			sum -= A[left];
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