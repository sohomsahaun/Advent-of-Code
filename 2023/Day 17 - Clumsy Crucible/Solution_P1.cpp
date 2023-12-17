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

const ll STEPS = 3;
const ll INF = 1e18;
const ll MX = 205;
ll W[MX][MX];
ll dis[MX][MX][5][5];
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
  ll r, c, w, d, rem, rr, cc, ww, dd, i, ans;

  for (r = 0; r < MX; ++r) {
    for (c = 0; c < MX; ++c) {
      for (w = 0; w < 5; ++w) {
        for (d = 0; d < 5; ++d) {
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
      rr = r + dr[i];
      cc = c + dc[i];
      ww = w + W[rr][cc];
      dd = i;

      if ((rr < 0) || (rr >= n)) continue;
      if ((cc < 0) || (cc >= m)) continue;
      if (abs(dd-d) == 2) continue;
      
      if (dd == d) {
        if (rem > 0) {
          if (ww < dis[rr][cc][dd][rem-1]) {
            dis[rr][cc][dd][rem-1] = ww;
            pq.push({ww, rr, cc, dd, rem-1});
          }
        }
      } else {
        if (ww < dis[rr][cc][dd][STEPS-1]) {
          dis[rr][cc][dd][STEPS-1] = ww;
          pq.push({ww, rr, cc, dd, STEPS-1});
        }
      }
    }
  }

  ans = INF;
  r = n-1; c = m-1;
  for (w = 0; w < 5; ++w) {
    for (d = 0; d < 5; ++d) {
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