#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> A;
vector<bool> checked(100001, false);

void input(){
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
}

void solve(){
	int left = 0, right = 0;
	long long res = 0;
	checked[A[0]] = true;

	bool here = false;
	while(left < n && right < n){
		if(!here){
			res += (right - left + 1);
			right++;
			here = checked[A[right]];
			checked[A[right]] = true;
		}
		else{
			if(A[left] == A[right]){
				here = false;
			}
			else{
				checked[A[left]] = false;
			}
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