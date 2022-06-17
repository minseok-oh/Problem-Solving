#include <bits/stdc++.h>
using namespace std;
int n;
long long maxRet = -1000000000, minRet = 1000000000;
vector<int> A, op_count(4);

void input(){
	cin >> n;

	int temp;
	for(int i = 0; i < n; i++){
		cin >> temp;
		A.push_back(temp);
	}

	for(int i = 0; i < 4; i++) cin >> op_count[i];
}

void solve(int k, int idx){
	if(idx == n){
		if(k > maxRet) maxRet = k;
		if(k < minRet) minRet = k;
		return ;
	}

	if(op_count[0] > 0){
		op_count[0]--;
		solve(k + A[idx], idx + 1);
		op_count[0]++;
	}
	if(op_count[1] > 0){
		op_count[1]--;
		solve(k - A[idx], idx + 1);
		op_count[1]++;
	}
	if(op_count[2] > 0){
		op_count[2]--;
		solve(k * A[idx], idx + 1);
		op_count[2]++;
	}
	if(op_count[3] > 0){
		op_count[3]--;
		solve(k / A[idx], idx + 1);
		op_count[3]++;
	}
}

int main(void){
	input();
	solve(A[0], 1);
	cout << maxRet << "\n" << minRet << "\n";
	return 0;
}