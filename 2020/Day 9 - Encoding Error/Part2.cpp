#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> input;

ll solve() {
    int n, l, r;
    n = input.size();

    ll sum, targ;

    l = 0; r = 0;
    sum = input[0];
    targ = 26796446LL;

    while (r++ < n) {
        while ((sum > targ) && (l+1 < r)) sum -= input[l++];
        if (sum == targ) {
            ll mn = *min_element(input.begin()+l, input.begin()+r);
            ll mx = *max_element(input.begin()+l, input.begin()+r);
            return (mn+mx);
        }
        if (r < n) sum += input[r];
    }

    return -1;
}

int main() {
    freopen("in2.txt", "r", stdin);

    stringstream str;
    string s, ss;

    while (getline(cin, s)) {
        str = stringstream(s);
        ll a;
        str >> a;
        input.push_back(a);
    }

    cout << solve();

    return 0;
}
