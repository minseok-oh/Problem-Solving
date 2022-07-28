#include <bits/stdc++.h>
using namespace std;
string key, sentence;

void input(){
    getline(cin, key);
    getline(cin, sentence);
}

void solve(){
    int key_value[26] = { 0, };
    for(int i = 0; i < 26; i++) key_value[i] = key[i] - 'a';

    for(int i = 0; sentence[i]; i++){
        if(sentence[i] == ' ') cout << sentence[i];
        else{
            if('a' <= sentence[i] && sentence[i] <= 'z'){
                cout << (char)('a' + key_value[sentence[i] - 'a']);
            }
            else if('A' <= sentence[i] && sentence[i] <= 'Z'){
                cout << (char)('A' + key_value[sentence[i] - 'A']);
            }
        }
    }
}

int main(void){
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    solve();
    return 0;
}