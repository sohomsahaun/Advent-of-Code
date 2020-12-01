#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll solve(vector<ll>& v) {
    int i, j, k, sz = v.size();
    for (i = 0; i < sz; ++i) {
        for (j = i+1; j < sz; ++j) {
            for (k = j+1; k < sz; ++k) {
                if (v[i]+v[j]+v[k] == 2020) return v[i]*v[j]*v[k];
            }
        }
    }
    return -1;
}

int main() {
    freopen("in2.txt", "r", stdin);

    ll n;
    vector<ll> input;
    while (cin >> n) input.push_back(n);

    cout << solve(input);

    return 0;
}
