#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> A;

void input(){
	cin >> n >> k;
	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
}

void solve(){
	int left = 0, right = 0, res = -100000001;
	int sum = A[0];
	while(left < n && right < n){
		int here = right - left + 1;
		if(here == k){
			res = max(res, sum);
		}

		if(here > k){
			sum -= A[left];
			left++;
		}
		else{
			right++;
			sum += A[right];
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