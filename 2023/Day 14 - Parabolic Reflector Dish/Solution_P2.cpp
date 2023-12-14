#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> g;

void get_input() {
  string s;
  while (cin >> s) g.push_back(s);
}

const int CYCLES = 1000000000;
const int L = 102;  // Found using BF
const int R = 143;  // Found using BF

ll solve() {
  ll n, m, i, j, cnt, start, ti, ans;
  n = g.size();
  m = g[0].size();

  auto get_ans = [&]() {
    ll ret = 0;
    for (i = 0; i < n; ++i) for (j = 0; j < m; ++j) {
      if (g[i][j] == 'O') {
        ret += n-i;
      }
    }    
    return ret;
  };

  auto rotate = [&]() {
    // N
    for (j = 0; j < m; ++j) {
      start = 0;
      for (i = 0; i < n; ++i) {
        if (g[i][j] == '#') {
          start = i+1;
          continue;
        } else if (g[i][j] == 'O') {
          g[i][j] = '.';
          g[start][j] = 'O';
          start += 1;
        }
      }
    }

    // W
    for (i = 0; i < n; ++i) {
      start = 0;
      for (j = 0; j < m; ++j) {
        if (g[i][j] == '#') {
          start = j+1;
          continue;
        } else if (g[i][j] == 'O') {
          g[i][j] = '.';
          g[i][start] = 'O';
          start += 1;
        }
      }
    }

    // S
    for (j = 0; j < m; ++j) {
      start = n-1;
      for (i = n-1; i >= 0; --i) {
        if (g[i][j] == '#') {
          start = i-1;
          continue;
        } else if (g[i][j] == 'O') {
          g[i][j] = '.';
          g[start][j] = 'O';
          start -= 1;
        }
      }
    }

    // E
    for (i = 0; i < n; ++i) {
      start = m-1;
      for (j = m-1; j >= 0; --j) {
        if (g[i][j] == '#') {
          start = j-1;
          continue;
        } else if (g[i][j] == 'O') {
          g[i][j] = '.';
          g[i][start] = 'O';
          start -= 1;
        }
      }
    }
  };

  for (ti = 1; ti < L; ++ti) rotate();

  cnt = R-L+1;
  vector<ll> a(cnt);
  for (ti = 0; ti < cnt; ++ti) {
    rotate();
    a[ti] = get_ans();
  }
  
  ans = a[(CYCLES-L) % cnt];
  
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}