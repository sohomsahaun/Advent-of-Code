#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<pair<char,int>> in;

int solve() {
    char f[4] = {'E', 'N', 'W', 'S'};

    int x, y, face;
    x = y = face = 0;

    for (auto p : in) {
        char ch = p.first;
        int val = p.second;

        if (ch == 'F') ch = f[face];
            else if (ch == 'L') face = (((face + val/90) % 4) + 4) % 4;
            else if (ch == 'R') face = (((face - val/90) % 4) + 4) % 4;

        if (ch == 'N') y += val;
            else if (ch == 'S') y -= val;
            else if (ch == 'E') x += val;
            else if (ch == 'W') x -= val;
    }

    return abs(x)+abs(y);
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;

    while (cin >> s) {
        in.push_back({s[0], stoi(s.substr(1))});
    }

    cout << solve();

    return 0;
}
