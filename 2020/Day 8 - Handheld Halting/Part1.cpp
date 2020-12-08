#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1000
bool vis[N];

vector<pair<string,int>> input;

int solve() {
    memset(vis, 0, sizeof(vis));

    pair<string,int> p;
    int n, i, acc;
    n = input.size();
    acc = 0;

    for (i = 0; i < n; ++i) {
        if (vis[i]) return acc;
        vis[i] = 1;

        p = input[i];
        if (p.first == "nop") continue;
            else if (p.first == "acc") acc += p.second;
            else if (p.first == "jmp") i += p.second-1;
    }

    return -1;
}

int main() {
    freopen("in1.txt", "r", stdin);

    stringstream str;
    string s;

    while (getline(cin, s)) {
        str = stringstream(s);
        pair<string,int> p;
        str >> p.first >> p.second;
        input.push_back(p);
    }

    cout << solve();

    return 0;
}
