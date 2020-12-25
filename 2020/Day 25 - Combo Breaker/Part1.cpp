#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 20201227;

ll cpk, dpk;

ll solve() {
    ll cls, n;
    cls = 0;

    n = 1;
    while (n != cpk) {
        n = (n*7LL) % MOD;
        ++cls;
    }

    n = 1;
    while (cls--) {
        n = (n*dpk) % MOD;
    }

    return n;
}

int main() {
    freopen("in1.txt", "r", stdin);

    cin >> cpk >> dpk;

    cout << solve();

    return 0;
}
