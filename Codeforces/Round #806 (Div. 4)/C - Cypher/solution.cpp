#include <bits/stdc++.h>
using namespace std;
int t, n;
vector<int> a;

void input(){
    cin >> n;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
}

void solve(){
    cin >> t;
    while(t--){
        input();

        int k; string b;
        for(int i = 0; i < n; i++){
            cin >> k >> b;
            int here = a[i];
            for(int j = b.size() - 1; j >= 0; j--){
                if(b[j] == 'U'){
                    here--;
                    if(here == -1) here = 9;
                }
                else if(b[j] == 'D'){
                    here++;
                    if(here == 10) here = 0;
                }
            }
            cout << here << " ";
        } 
        cout << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}