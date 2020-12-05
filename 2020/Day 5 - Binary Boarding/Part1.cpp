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
    int mx = -1;
    for (auto s : v) mx = max(mx, get_id(s));
    return mx;
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;
    vector<string> input;
    while (cin >> s) {
        input.push_back(s);
    }

    cout << solve(input);

    return 0;
}
