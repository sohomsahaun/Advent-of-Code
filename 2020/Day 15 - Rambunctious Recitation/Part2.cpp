#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<int> in;

int solve() {
    int n, i, num, curr, next;

    unordered_map<int,int> pos;

    num = 30000000;
    n = in.size();

    for (i = 0; i < n-1; ++i) {
        curr = in[i];
        pos[curr] = i;
        next = in[i+1];
    }

    for (i = i; i < num; ++i) {
        curr = next;
        if (pos.find(curr) == pos.end()) next = 0;
            else next = i-pos[next];
        pos[curr] = i;
    }

    return curr;
}

int main() {
    freopen("in2.txt", "r", stdin);

    string s;

    while (getline(cin, s, ',')) {
        in.push_back(stoi(s));
    }

    cout << solve();

    return 0;
}
