#include <bits/stdc++.h>
using namespace std;
int n, r, c;

void input(){
    cin >> n >> r >> c;
}

long long solve(int y, int x, int size){
    if(size == 0) return 1;
    
    long long ret = 0;
    long long square = pow(2, --size);
    if(y + square > r && x + square > c){
        ret += solve(y, x, size);
    }
    else if(y + square > r && x + square <= c){
        ret += square * square;
        ret += solve(y, x + square, size);
    }
    else if(y + square <= r && x + square > c){
        ret += square * square * 2;
        ret += solve(y + square, x, size);
    }
    else{
        ret += square * square * 3;        
        ret += solve(y + square, x + square, size);
    }
    return ret;
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    cout << solve(0, 0, n) - 1 << "\n";
    return 0;
}