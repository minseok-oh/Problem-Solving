#include <bits/stdc++.h>
using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> userList;
    for (string p: participant) {
        if (userList.find(p) != userList.end()) userList[p]++;
        else userList[p] = 1;
    }
    
    string answer;
    for (string c: completion) userList[c]--;
    for (auto user: userList) {
        if (user.second == 1) answer = user.first;
    }
    return answer;
}