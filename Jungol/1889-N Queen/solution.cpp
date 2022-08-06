#include <bits/stdc++.h>
using namespace std;
int n;
bool row[30] = { false, }, col1[30] = { false, }, col2[30] = { false, };

long long make_queens(int y){
    if(y == n) return 1;

    long long ret = 0;
    for(int i = 0; i < n; i++){
        if(!row[i] && !col1[y - i + n] && !col2[y + i]){
            row[i] = col1[y - i + n] = col2[y + i] = true;
            ret += make_queens(y + 1);
            row[i] = col1[y - i + n] = col2[y + i] = false;
        }
    }
    return ret;
}

void solve(){
    cin >> n;
    cout << make_queens(0) << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}