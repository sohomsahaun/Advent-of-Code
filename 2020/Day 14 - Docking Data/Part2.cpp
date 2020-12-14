#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 36LL
map<ll,ll> mem;

struct Data {
    string mask;
    vector<ll> x;
    ll cnt;

    Data(string mask = "") : mask(mask) {
        int n = mask.size();
        for (int i = n-1; i >= 0; --i) {
            if (mask[i] == 'X') x.push_back(i);
        }
        cnt = x.size();
    }

    void write(ll pos, ll val) {
        string s = bitset<N>(pos).to_string();
        ll i, m;

        for (i = 0; i < N; ++i) {
            if (mask[i] != '0') s[i] = mask[i];
        }

        for (m = (1LL << cnt) - 1; m >= 0; --m) {
            string r = s;
            for (i = 0; i < cnt; ++i) {
                r[x[i]] = ((m >> i) & 1LL) + '0';
            }

            mem[stoll(r, nullptr, 2)] = val;
        }
    }
};

ll solve() {
    ll ans = 0;
    for (auto& m : mem) ans += m.second;
    return ans;
}

int main() {
    freopen("in2.txt", "r", stdin);

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
