#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> in;

void next_cycle(vector<vector<vector<string>>>& hypercube) {
    int w, h, d, x, y, z, p, xx, yy, zz, pp, active;
    char ch;

    d = hypercube.size();
    h = hypercube[0][0].size();
    w = hypercube[0][0][0].size();

    vector<vector<vector<string>>> newHypercube(d, vector<vector<string>>(d, vector<string>(h, string(w, '.'))));

    for (p = 0; p < d; ++p) {
        for (z = 0; z < d; ++z) {
            for (y = 0; y < h; ++y) {
                for (x = 0; x < w; ++x) {
                    ch = hypercube[p][z][y][x];
                    active = 0;

                    for (int dp : {-1, 0, 1}) {
                        for (int dz : {-1, 0, 1}) {
                            for (int dy : {-1, 0, 1}) {
                                for (int dx : {-1, 0, 1}) {
                                    pp = p+dp; if ((pp < 0) || (pp >= d)) continue;
                                    zz = z+dz; if ((zz < 0) || (zz >= d)) continue;
                                    yy = y+dy; if ((yy < 0) || (yy >= h)) continue;
                                    xx = x+dx; if ((xx < 0) || (xx >= w)) continue;
                                    if ((xx == x) && (yy == y) && (zz == z) && (pp == p)) continue;
                                    active += (hypercube[pp][zz][yy][xx] == '#');
                                }
                            }
                        }
                    }

                    if (ch == '#') {
                        if ((active < 2) || (active > 3)) ch = '.';
                    } else {
                        if (active == 3) ch = '#';
                    }

                    newHypercube[p][z][y][x] = ch;
                }
            }
        }
    }

    hypercube = newHypercube;
}

int solve() {
    int times = 6;
    int iw, ih, w, h, d, x, y, z, p, ans;

    ih = in.size();
    iw = in[0].size();

    d = 1+times*2;
    h = ih+d*2;
    w = iw+d*2;

    vector<vector<vector<string>>> hypercube(d, vector<vector<string>>(d, vector<string>(h, string(w, '.'))));

    p = d/2;
    z = d/2;
    for (x = 0; x < iw; ++x) {
        for (y = 0; y < ih; ++y) {
            hypercube[p][z][y+d][x+d] = in[y][x];
        }
    }

    while (times--) next_cycle(hypercube);

    ans = 0;
    for (auto& v : hypercube) {
        for (auto& b : v) {
            for (auto& s : b) {
                for (auto& c : s) ans += (c == '#');
            }
        }
    }

    return ans;
}

int main() {
    freopen("in2.txt", "r", stdin);

    string s;

    while (getline(cin, s)) {
        in.push_back(s);
    }

    cout << solve();

    return 0;
}
