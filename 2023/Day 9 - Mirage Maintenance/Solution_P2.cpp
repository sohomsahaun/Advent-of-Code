#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<ll>> a;

void get_input() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);

    vector<ll> v;
    ll x;
    while (ss >> x) v.push_back(x);
    reverse(v.begin(), v.end());
    
    a.push_back(v);
  }
}

ll get(vector<ll> v) {
  vector<ll> d;
  for (int i = 1; i < v.size(); ++i) d.push_back(v[i]-v[i-1]);
  bool f = 1;
  for (ll x : d) if (x != 0) f = 0;
  if (f) return v.back();
  return v.back() + get(d);
}

ll solve() {
  ll ans = 0;
  for (vector<ll> v : a) ans += get(v);
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}