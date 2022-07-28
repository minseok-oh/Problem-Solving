#include <bits/stdc++.h>
using namespace std;
int n;

const int x_grad[4] = { -1, 1, 1, -1 };
const int y_grad[4] = { 1, 1, -1, -1 };
void solve(){
    cin >> n;

    int y = 0, x = n - 1, here = 0;
    char ans[201][201] = { 0, };
    for(int i = n - 1; i >= 0; i--){
        ans[y][x] = here + 'A';
        if(here < 25) here++;
        else here = 0;
        
        for(int dir = 0; dir < 4; dir++){
            for(int j = 0; j < i; j++){
                if(dir == 3 && j == i - 1) break;
                y += y_grad[dir]; x += x_grad[dir];
                ans[y][x] = here + 'A';

                if(here < 25) here++;
                else here = 0;
            }
        }
        x--;
    }

    for(int i = 0; i < 2 * n; i++){
        if(i < n){
            for(int j = 0; j < n - i - 1; j++) cout << " ";
        }
        else{
            for(int j = 0; j < i - n + 1; j++) cout << " ";
        }

        for(int j = 0; j < 2 * n; j++){
            if(ans[i][j] == 0) cout << " ";
            else cout << ans[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    solve();
    return 0;
}