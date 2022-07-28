#include <bits/stdc++.h>
using namespace std;
int n;

void solve(){
    cin >> n;

    int y = 0, x = 0, here = 1;
    int ans[101][101] = { 0, };
    for(int i = 0; i <= 2 * (n - 1); i++){
        ans[y][x] = here++;
        if(i % 2 == 1){
            while(y != 0 && x != n - 1){
                x++; y--;
                ans[y][x] = here++;
            }
            
            if(i < n - 1) x++;
            else y++;
        }
        else{
            while(x != 0 && y != n - 1){
                x--; y++;
                ans[y][x] = here++;
            }

            if(i < n - 1) y++;
            else x++;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}