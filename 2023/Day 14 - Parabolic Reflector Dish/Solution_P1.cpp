#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> g;

void get_input() {
  string s;
  while (cin >> s) g.push_back(s);
}

ll solve() {
  ll n, m, i, j, start, ans;
  n = g.size();
  m = g[0].size();

  ans = 0;
  for (j = 0; j < m; ++j) {
    start = 0;
    for (i = 0; i < n; ++i) {
      if (g[i][j] == '#') {
        start = i+1;
        continue;
      } else if (g[i][j] == 'O') {
        ans += n-start;
        start += 1;
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