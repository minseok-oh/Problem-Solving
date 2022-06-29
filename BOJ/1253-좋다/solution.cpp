#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> A;

void input(){
	cin >> n;
	A.resize(n);
	for(int i = 0; i < n; i++) cin >> A[i];
	sort(A.begin(), A.end());
}

void solve(){
	int res = 0;
	for(int i = 0; i < n; i++){
		int left = 0, right = n - 1;
		
		while(left < right){
			if(left == i){
				left++;
			}
			else if(right == i){ 
				right--;
			}
			else{
				int here = A[left] + A[right];
				
				if(here == A[i]){
					res++;
					break;
				}
				else if(here > A[i]){
					right--;
				}
				else{
					left++;
				}
			}
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