#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> in;

ll solve() {
    in.push_back(0);
    sort(in.begin(), in.end());
    in.push_back(in.back()+3);

    ll diff, one, three;
    one = three = 0;

    int n, i;
    n = in.size();

    for (i = 1; i < n; ++i) {
        diff = in[i]-in[i-1];
        one += (diff == 1);
        three += (diff == 3);
    }

    return (one*three);
}

int main() {
    freopen("in1.txt", "r", stdin);

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
