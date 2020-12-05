#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int get_id(string& s) {
    int i, l, r, m, row, col;

    l = 0; r = 127;
    for (i = 0; i < 7; ++i) {
        m = (l+r+1)/2;
        if (s[i] == 'B') l = m;
            else r = m;
    }
    row = l;

    l = 0; r = 7;
    for (i = i; i < 10; ++i) {
        m = (l+r+1)/2;
        if (s[i] == 'R') l = m;
            else  r = m;
    }
    col = l;

    return (row*8 + col);
}

int solve(vector<string>& v) {
    vector<bool> taken(1024, 0);
    for (auto s : v) taken[get_id(s)] = 1;

    for (int i = 1; i < 1023; ++i) {
        if (taken[i-1] && !taken[i] && taken[i+1]) return i;
    }
    return -1;
}

int main() {
    freopen("in2.txt", "r", stdin);

    string s;
    vector<string> input;
    while (cin >> s) {
        input.push_back(s);
    }

    cout << solve(input);

    return 0;
}
