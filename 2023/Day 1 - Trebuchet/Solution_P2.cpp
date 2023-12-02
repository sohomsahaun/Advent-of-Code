#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> a;

void get_input() {
  string s;
  while (cin >> s) a.push_back(s);
}

template<typename T>
vector<int> z_search(T& s) {
  int n, l, r, i;
  n = s.size();

  vector<int> z(n, 0);
  l = r = 0;
  for (i = 1; i < n; ++i) {
    if (i <= r) {
      z[i] = min(r-i+1, z[i-l]);
    }
    while ((i+z[i] < n) && (s[z[i]] == s[i+z[i]])) {
      ++z[i];
    }
    if (i+z[i]-1 > r) {
      l = i;
      r = i+z[i]-1;
    }
  }

  return z;
}

ll solve() {
  vector<string> digits = {
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
  };

  auto get_val = [&](string s) {
    if (s.size() == 1) return stoi(s);

    for (int i = 0; i < 9; ++i) {
      if (digits[i] == s) return i+1;
    }

    return -1;
  };

  int i, j;
  ll ans = 0;
  for (auto s : a) {
    vector<pair<int,string>> v;

    for (auto d : digits) {
      string t = d + "#" + s;
      vector<int> z = z_search(t);
      for (i = d.size()+1; i < z.size(); ++i) {
        if (z[i] == d.size()) v.push_back({i-d.size()-1, d});
      }
    }
    sort(v.begin(), v.end());

    ans += get_val(v[0].second) * 10;
    ans += get_val(v.back().second);
  }

  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}