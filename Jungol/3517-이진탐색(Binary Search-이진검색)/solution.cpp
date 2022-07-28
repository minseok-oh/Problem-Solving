#include <bits/stdc++.h>
using namespace std;
int n, q;
vector<int> a;

void input(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> q;
}

void binary_search(int value){
    int left = 0, right = n - 1;
    while(left <= right){
        int mid = (left + right) / 2;

        if(a[mid] == value){
            cout << mid;
            return;
        }
        else if(a[mid] < value) left = mid + 1;
        else right = mid - 1;
    }
    cout << -1;
}

void solve(){
    for(int i = 0; i < q; i++){
        int value;
        cin >> value;
        binary_search(value);
        cout << " ";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}