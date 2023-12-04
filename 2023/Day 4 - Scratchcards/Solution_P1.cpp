#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, pair<vector<ll>,vector<ll>>> mp;

void get_input() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    string id, _;

    vector<ll> x, y;

    ss >> _ >> id; id.pop_back();

    while (ss >> s) {
      if (s == "|") break;
      x.push_back(stoll(s));
    }

    while (ss >> s) {
      y.push_back(stoll(s));
    }

    mp[stoll(id)] = { x, y };
  }
}

ll solve() {
  auto get_matches = [&](vector<ll> win, vector<ll> has) {
    ll res = 0;
    map<ll,ll> cnt;
    for (ll x : win) cnt[x] += 1;
    for (ll x : has) res += cnt[x];
    return res;
  };

  ll ans = 0;
  
  for (auto [ id, p ] : mp) {
    auto win = p.first;
    auto has = p.second;
    ll res = get_matches(win, has);
    if (res > 0) ans += (1ll << (res-1));
  }

  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}