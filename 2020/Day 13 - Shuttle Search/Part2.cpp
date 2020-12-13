#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<ll,ll>> in;
ll Time;

ll inv(ll a, ll m) {
    if (m == 1) return 0;

    ll x, y, p, q, t;
    x = 1;
    y = 0;
    p = m;

    while (a > 1) {
        q = a/m;

        t = m;
        m = a % m;
        a = t;

        t = y;
        y = x - q*y;
        x = t;
    }

    x = ((x % p) + p) % p;

    return x;
}

ll solve() {
    ll prd, ans, div;

    prd = 1;
    for (auto& p : in) {
        prd *= p.first;
        p.second = p.first - (p.second % p.first);
    }

    ans = 0;
    for (auto& p : in) {
        div = prd/p.first;
        ans = (ans + p.second*div*inv(div,p.first)) % prd;
    }

    return ans;
}

int main() {
    freopen("in2.txt", "r", stdin);

    string s;
    ll t = -1;

    cin >> Time;
    while (getline(cin, s, ',')) {
        ++t;
        if (s == "x") continue;
        in.push_back({stoi(s), t});
    }

    cout << solve();

    return 0;
}
