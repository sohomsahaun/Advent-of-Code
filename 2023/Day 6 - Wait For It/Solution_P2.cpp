#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> T, D;

void get_input() {
  string s;
  stringstream ss;
  string _;
  string num, x;

  getline(cin, s);
  ss = stringstream(s);
  ss >> _;
  num = "";
  while (ss >> x) num += x;
  T.push_back(stoll(num));

  getline(cin, s);
  ss = stringstream(s);
  ss >> _;
  num = "";
  while (ss >> x) num += x;
  D.push_back(stoll(num));
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