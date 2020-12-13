#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> in;
ll Time;

ll calc(ll n) {
    return (n * ((n+Time-1)/n));
}

ll solve() {
    ll id = in[0];
    for (auto& x : in) {
        if (calc(x) < calc(id)) id = x;
    }
    return (id * (calc(id)-Time));
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;

    cin >> Time;
    while (getline(cin, s, ',')) {
        if (s == "x") continue;
        in.push_back(stoi(s));
    }

    cout << solve();

    return 0;
}
