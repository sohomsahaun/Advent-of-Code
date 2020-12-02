#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Pass {
    int mn, mx;
    char ch;
    string pass;

    Pass(int mn, int mx, char ch, string pass)
        : mn(mn), mx(mx), ch(ch), pass(pass) {}

    bool is_valid() {
        int cnt = 0;
        for (char c : pass) cnt += (c == ch);
        return ((mn <= cnt) && (cnt <= mx));
    }
};

int solve(vector<Pass>& v) {
    int cnt = 0;
    for (auto pass : v) cnt += pass.is_valid();
    return cnt;
}

int main() {
    freopen("in1.txt", "r", stdin);

    int mn, mx;
    char hyp, ch, col;
    string s, pass;
    stringstream str;

    vector<Pass> input;
    while (getline(cin, s)) {
        str = stringstream(s);
        str >> mn >> hyp >> mx >> ch >> col >> pass;
        input.push_back(Pass(mn, mx, ch, pass));
    }

    cout << solve(input);

    return 0;
}
