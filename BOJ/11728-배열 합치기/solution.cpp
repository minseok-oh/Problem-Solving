#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> A, B;

void input(){
	cin >> n >> m;
	A.resize(n);
	B.resize(m);
	for(int i = 0; i < n; i++) cin >> A[i];
	for(int i = 0; i < m; i++) cin >> B[i];
}

void solve(){
	int left = 0, right = 0;
	while(left < n && right < m){
		if(A[left] < B[right]){
			cout << A[left] << " ";
			left++;
		}
		else{
			cout << B[right] << " ";
			right++;
		}
	}

	if(left == n){
		while(right < m){
			cout << B[right] << " ";
			right++;
		}
	}
	else{
		while(left < n){
			cout << A[left] << " ";
			left++;
		}
	}
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}