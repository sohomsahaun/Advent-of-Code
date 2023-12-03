#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> a;
const int dr[] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int dc[] = {-1, -1, -1, 0, 0, 1, 1, 1};

void get_input() {
  string s;
  while (cin >> s) a.push_back(s);
}

ll solve() {
  ll ans = 0;
  
  ll n, m, i, j, k, r, c;
  n = a.size();
  m = a[0].size();
  
  vector<vector<bool>> vis(n, vector<bool>(m, 0));

  auto is_digit = [&](int x, int y) {
    if (('0' <= a[x][y]) && (a[x][y] <= '9')) return true;
    return false;
  };

  auto is_symbol = [&](int x, int y) {
    if (a[x][y] == '.') return false;
    if (is_digit(x, y)) return false;
    return true;
  };

  auto get_num = [&](int x, int y) {
    int l, r, i;
    l = r = y;
    while ((l >= 0) && is_digit(x, l)) --l;
    while ((r <= m) && is_digit(x, r)) ++r;
    ++l; --r;
    string s = "";
    for (i = l; i <= r; ++i) {
      s += a[x][i];
      vis[x][i] = 1;
    }
    return stoll(s);
  };

  for (i = 0; i < n; ++i) {
    for (j = 0; j < m; ++j) {
      if (!is_symbol(i, j)) continue;
      for (k = 0; k < 8; ++k) {
        r = i + dr[k];
        c = j + dc[k];
        if ((r < 0) || (r >= n)) continue;
        if ((c < 0) || (c >= m)) continue;
        if (vis[r][c]) continue;
        if (!is_digit(r, c)) continue;
        ans += get_num(r, c);
      }
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