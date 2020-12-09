#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<ll> input;

ll solve() {
    int n, i, j, k;
    n = input.size();

    for (i = 25; i < n; ++i) {
        for (j = i-25; j < i; ++j) {
            for (k = j+1; k < i; ++k) {
                if (input[j]+input[k] == input[i]) goto BreakProMax;
            }
        }
        return input[i];
        BreakProMax:;
    }

    return -1;
}

int main() {
    freopen("in1.txt", "r", stdin);

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
