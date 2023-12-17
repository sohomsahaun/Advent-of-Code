#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = tuple<ll,ll,ll,ll,ll>;

const int R = 0;
const int U = 1;
const int L = 2;
const int D = 3;

const int dr[] = {0, -1, 0, 1};
const int dc[] = {1, 0, -1, 0};

const ll STEPS = 10;
const ll INF = 1e18;
const ll MX = 205;
ll W[MX][MX];
ll dis[MX][MX][5][15];
ll n, m;

void get_input() {
  string s;
  int i = 0;
  while (cin >> s) {
    m = s.size();
    for (int j = 0; j < m; ++j) {
      W[i][j] = s[j]-'0';
    }
    i += 1;
  }
  n = i;
}

ll solve() {
  ll r, c, w, d, rem, rr, cc, ww, dd, remm, i, k, steps, ans;

  for (r = 0; r < MX; ++r) {
    for (c = 0; c < MX; ++c) {
      for (w = 0; w < 5; ++w) {
        for (d = 0; d < 15; ++d) {
          dis[r][c][w][d] = INF;
        }
      }
    }
  }

  r = c = 0;
  priority_queue<P, vector<P>, greater<P>> pq;
  pq.push({0, r, c, -100, 0});

  while (!pq.empty()) {
    tie(w, r, c, d, rem) = pq.top(); pq.pop();

    for (i = 0; i < 4; ++i) {
      rr = r;
      cc = c;
      ww = w;
      dd = i;
      if (abs(dd-d) == 2) continue;

      if (dd == d) {
        if (rem > 0) {
          bool f = 1;
          for (k = 0; k < 1; ++k) {
            rr = rr + dr[i];
            cc = cc + dc[i];
            if ((rr < 0) || (rr >= n)) { f = 0; break; }
            if ((cc < 0) || (cc >= m)) { f = 0; break; };
            ww += W[rr][cc];
          }
          if (!f) continue;

          remm = rem-1;
          if (ww < dis[rr][cc][dd][remm]) {
            dis[rr][cc][dd][remm] = ww;
            pq.push({ww, rr, cc, dd, remm});
          }
        }
      } else {
        bool f = 1;
        for (k = 0; k < 4; ++k) {
          rr = rr + dr[i];
          cc = cc + dc[i];
          if ((rr < 0) || (rr >= n)) { f = 0; break; }
          if ((cc < 0) || (cc >= m)) { f = 0; break; };
          ww += W[rr][cc];
        }
        if (!f) continue;

        remm = STEPS-4;
        if (ww < dis[rr][cc][dd][remm]) {
          dis[rr][cc][dd][remm] = ww;
          pq.push({ww, rr, cc, dd, remm});
        }
      }
    }
  }

  ans = INF;
  r = n-1; c = m-1;
  for (w = 0; w < 5; ++w) {
    for (d = 0; d < 15; ++d) {
      ans = min(ans, dis[r][c][w][d]);
    }
  }

  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}