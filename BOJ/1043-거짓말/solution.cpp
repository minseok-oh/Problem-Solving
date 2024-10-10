#include <bits/stdc++.h>
using namespace std;
int n, m;
bool knownPerson[51] = { false, };
vector<int> parties[51], graph[51];

void input() {
    cin >> n >> m;
    
    int count;
    for (int i = 0; i <= m; i++) {
        cin >> count;
        parties[i].resize(count);
        for (int j = 0; j < count; j++) {
            cin >> parties[i][j];
        }
    }
}

void initKnownPerson() {
    for (int person: parties[0]) {
        knownPerson[person] = true;
    }    
}

bool containKnownPerson(vector<int>& party) {
    bool containKnownPerson = false;
    for (int person: party) {
        if (knownPerson[person]) {
            containKnownPerson = true;
            break;
        }
    }
    return containKnownPerson;
}

void makeKnownPerson() {
    for (int i = 1; i <= m; i++) {
        if (containKnownPerson(parties[i])) {
            for (int person: parties[i]) {
                knownPerson[person] = true;
            }
        }
    }
}

int solve() {
    int result = 0;
    for (int i = 1; i <= m; i++) {
        if (!containKnownPerson(parties[i])) {
            result++;
        }
    }
    return result;
}

int main(void) {
    cin.tie(0), ios::sync_with_stdio(0);
    input();
    initKnownPerson();
    for (int i = 0; i < m; i++) {
        makeKnownPerson();
    }
    cout << solve() << "\n";
    return 0;
}