#include <bits/stdc++.h>
using namespace std;
int s, e;

void input(){
    cin >> s >> e;
    while(s < 2 || s > 9 || e < 2 || e > 9){
        cout << "INPUT ERROR!\n";
        cin >> s >> e;
    };
}

void solve(){
    if(s < e){
        for(int t = 1; t <= 9; t++){
            for(int i = s; i <= e; i++){
                if((i * t) < 10) printf("%d * %d =  %d", i, t, i * t);
                else printf("%d * %d = %d", i, t, i * t);
                printf("   ");
            }
            printf("\n");
        }
    }
    else{
        for(int t = 1; t <= 9; t++){
            for(int i = s; i >= e; i--){
                if((i * t) < 10) printf("%d * %d =  %d", i, t, i * t);
                else printf("%d * %d = %d", i, t, i * t);
                printf("   ");
            }
            printf("\n");
        }
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}