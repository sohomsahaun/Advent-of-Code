#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1000
bool vis[N];

vector<pair<string,int>> input;

int get_acc() {
    memset(vis, 0, sizeof(vis));

    pair<string,int> p;
    int n, i, acc;
    n = input.size();
    acc = 0;

    for (i = 0; i < n; ++i) {
        if (vis[i]) break;
        vis[i] = 1;

        p = input[i];
        if (p.first == "nop") continue;
            else if (p.first == "acc") acc += p.second;
            else if (p.first == "jmp") i += p.second-1;
    }
    if (i < n) acc = -1;

    return acc;
}

int solve() {
    int i, n, acc;
    n = input.size();
    acc = -1;

    for (i = 0; i < n; ++i) {
        string& s = input[i].first;

        if (s == "acc") continue;
        acc = -1;

        if (s == "nop") {
            s = "jmp";
            acc = get_acc();
            s = "nop";
        } else if (s == "jmp") {
            s = "nop";
            acc = get_acc();
            s = "jmp";
        }

        if (acc != -1) return acc;
    }

    return acc;
}

int main() {
    freopen("in2.txt", "r", stdin);

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
