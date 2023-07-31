#include <bits/stdc++.h>
using namespace std;
int n;
char mbti[100001][4];

int getDistance(int i1, int i2) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        if (mbti[i1][i] != mbti[i2][i]) res++;
    }
    return res;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> mbti[i];
    }
}

vector<int> member;
int bruteForce(int here) {
    if (member.size() == 3) {
        int res = 0;
        res += getDistance(member[0], member[1]);
        res += getDistance(member[0], member[2]);
        res += getDistance(member[1], member[2]);
        return res;
    }

    int res = 12;
    for (int dir = here + 1; dir < n; dir++) {
        member.push_back(dir);
        res = min(res, bruteForce(dir));
        member.pop_back();
    }
    return res;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while (t--) {
        input();
        if (n > 32) cout  << "0\n";
        else cout << bruteForce(-1) << "\n";
    }
    return 0;
}