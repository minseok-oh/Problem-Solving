#include <bits/stdc++.h>
using namespace std;
long long n, k;

void input(){
	cin >> n >> k;
}

long long count_value(long long value){
	long long res = 0;
	for(int i = 1; i <= n; i++){
		res += min(n, value / i);
	}
	return res;
}

void solve(){
	long long left = 0, right = n * n;
	while(left <= right){
		long long mid = (left + right) / 2;

		long long here = count_value(mid);
		if(here >= k){
			right = mid - 1;
		}
		else{
			left = mid + 1;
		}
	}
	cout << left << "\n";
}

int main(void){
	cin.tie(0), ios::sync_with_stdio(0);
	input();
	solve();
	return 0;
}