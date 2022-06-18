#include <bits/stdc++.h>
using namespace std;
int l, c;
vector<char> str;

void input(){
    cin >> l >> c;

    char temp;
    for(int i = 0; i < c; i++){
        cin >> temp;
        str.push_back(temp);
    }
    sort(str.begin(), str.end());
}

const string test = "aeiou";
bool isChecked(char s){
    for(int i = 0; test[i]; i++){
        if(s == test[i]) return true;
    }
    return false;
}

string ret;
vector<string> rets;
void solve(int idx, int mo, int ja){
    if(ret.size() == l){
        if(mo <= 0 && ja <= 0) rets.push_back(ret);
        return ;
    }
    if(idx == c) return ;

    ret.push_back(str[idx]);
    if(isChecked(str[idx])){
        solve(idx + 1, mo - 1, ja);
    }
    else{
        solve(idx + 1, mo, ja - 1);
    }
    ret.pop_back();
    solve(idx + 1, mo, ja);
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve(0, 1, 2);
    for(auto a: rets) cout << a << "\n";
    return 0;
}