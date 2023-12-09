#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> T, D;

void get_input() {
  string s;
  stringstream ss;
  string _;
  ll x;

  getline(cin, s);
  ss = stringstream(s);
  ss >> _;
  while (ss >> x) T.push_back(x);

  getline(cin, s);
  ss = stringstream(s);
  ss >> _;
  while (ss >> x) D.push_back(x);
}

ll calc_ways(ll t, ll d) {
  ll ways = 0;
  for (ll i = 0; i <= t; ++i) {
    ll rem = t-i;
    if (rem*i > d) ways += 1;
  }
  return ways;
}

ll solve() {
  ll ans = 1;
  for (int i = 0; i < T.size(); ++i) {
    ans *= calc_ways(T[i], D[i]);
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}