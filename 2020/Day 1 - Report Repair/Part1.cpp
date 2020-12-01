#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll>& v) {
    int i, j, sz = v.size();
    for (i = 0; i < sz; ++i) {
        for (j = i+1; j < sz; ++j) {
            if (v[i]+v[j] == 2020) return v[i]*v[j];
        }
    }
    return -1;
}

int main() {
    freopen("in1.txt", "r", stdin);

    ll n;
    vector<ll> input;
    while (cin >> n) input.push_back(n);

    cout << solve(input);

    return 0;
}
