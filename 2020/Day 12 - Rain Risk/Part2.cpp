#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<char,int>> in;

ll solve() {
    int x, y, wx, wy, i;
    x = y = 0;

    wx = 10;
    wy = 1;

    for (auto p : in) {
        char ch = p.first;
        int val = p.second;

        if (ch == 'L') {
            for (i = 0; i < val; i += 90) {
                swap(wx, wy);
                wx = -wx;
            }
        } else if (ch == 'R') {
            for (i = 0; i < val; i += 90) {
                swap(wx, wy);
                wy = -wy;
            }
        } else if (ch == 'F') {
            x += wx * val;
            y += wy * val;
        }

        if (ch == 'N') wy += val;
            else if (ch == 'S') wy -= val;
            else if (ch == 'E') wx += val;
            else if (ch == 'W') wx -= val;
    }

    return abs(x)+abs(y);
}

int main() {
    freopen("in2.txt", "r", stdin);

    string s;

    while (cin >> s) {
        in.push_back({s[0], stoi(s.substr(1))});
    }

    cout << solve();

    return 0;
}
