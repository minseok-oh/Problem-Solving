#include <bits/stdc++.h>
using namespace std;
int n, paper[129][129];
int white_paper = 0, blue_paper = 0;

void input(){
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> paper[i][j];
        }
    }
}

void split(int y, int x, int size){
    bool flag = true;
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(paper[i][j] != paper[y][x]) flag = false;
        }
    }

    if(flag){
        if(paper[y][x] == 1) blue_paper++;
        else white_paper++;
    }
    else{
        size /= 2;
        split(y, x, size);
        split(y + size, x, size);
        split(y, x + size, size);
        split(y + size, x + size, size);
    }
}

void solve(){
    split(0, 0, n);
    cout << white_paper << "\n";
    cout << blue_paper << "\n";
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}