#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> in;

void next_cycle(vector<vector<string>>& cube) {
    int w, h, d, i, x, y, z, xx, yy, zz, active;
    char ch;

    d = cube.size();
    h = cube[0].size();
    w = cube[0][0].size();

    vector<vector<string>> newCube(d, vector<string>(h, string(w, '.')));

    for (z = 0; z < d; ++z) {
        for (y = 0; y < h; ++y) {
            for (x = 0; x < w; ++x) {
                ch = cube[z][y][x];
                active = 0;

                for (int dz : {-1, 0, 1}) {
                    for (int dy : {-1, 0, 1}) {
                        for (int dx : {-1, 0, 1}) {
                            zz = z+dz; if ((zz < 0) || (zz >= d)) continue;
                            yy = y+dy; if ((yy < 0) || (yy >= h)) continue;
                            xx = x+dx; if ((xx < 0) || (xx >= w)) continue;
                            if ((xx == x) && (yy == y) && (zz == z)) continue;
                            active += (cube[zz][yy][xx] == '#');
                        }
                    }
                }

                if (ch == '#') {
                    if ((active < 2) || (active > 3)) ch = '.';
                } else {
                    if (active == 3) ch = '#';
                }

                newCube[z][y][x] = ch;
            }
        }
    }

    cube = newCube;
}

int solve() {
    int times = 6;
    int iw, ih, w, h, d, x, y, z, ans;

    ih = in.size();
    iw = in[0].size();

    d = 1+times*2;
    h = ih+d*2;
    w = iw+d*2;

    vector<vector<string>> cube(d, vector<string>(h, string(w, '.')));

    z = d/2;
    for (x = 0; x < iw; ++x) {
        for (y = 0; y < ih; ++y) {
            cube[z][y+d][x+d] = in[y][x];
        }
    }

    while (times--) next_cycle(cube);

    ans = 0;
    for (auto& v : cube) {
        for (auto& s : v) {
            for (auto& c : s) ans += (c == '#');
        }
    }

    return ans;
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;

    while (getline(cin, s)) {
        in.push_back(s);
    }

    cout << solve();

    return 0;
}
