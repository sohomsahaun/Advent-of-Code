#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 36LL
map<ll,ll> mem;

struct Data {
    string mask;

    Data(string mask = "") : mask(mask) {}

    void write(ll pos, ll val) {
        string s = bitset<N>(val).to_string();
        ll i;

        for (i = 0; i < N; ++i) {
            if (mask[i] != 'X') s[i] = mask[i];
        }

        mem[pos] = stoll(s, nullptr, 2);
    }
};

ll solve() {
    ll ans = 0;
    for (auto& m : mem) ans += m.second;
    return ans;
}

int main() {
    freopen("in1.txt", "r", stdin);

    stringstream str;
    string s, ss, sign, mask;

    Data data;
    int i, len;
    ll ind, val;

    while (getline(cin, s)) {
        str = stringstream(s);
        str >> ss;

        if (ss == "mask") {
            str >> sign >> mask;
            data = Data(mask);
        } else {
            ss.pop_back();
            ind = stoll(ss.substr(ss.find('[')+1));

            str >> sign >> val;
            data.write(ind, val);
        }
    }

    cout << solve();

    return 0;
}
