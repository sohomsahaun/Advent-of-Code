#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> in;

ll solve() {
    sort(in.begin(), in.end());

    int n, i, j;
    n = in.size();

    vector<ll> dp(in.back()+1, 0);
    dp[0] = 1;

    for (i = 0; i < n; ++i) {
        for (j = max(0LL, in[i]-3); j < in[i]; ++j) {
            dp[in[i]] += dp[j];
        }
    }

    return dp.back();
}

int main() {
    freopen("in2.txt", "r", stdin);

    stringstream str;
    string s, ss;

    while (getline(cin, s)) {
        str = stringstream(s);
        ll a;
        str >> a;
        in.push_back(a);
    }

    cout << solve();

    return 0;
}
