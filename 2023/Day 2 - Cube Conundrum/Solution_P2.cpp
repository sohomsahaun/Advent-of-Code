#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<ll, vector<tuple<ll,ll,ll>>> mp;

void get_input() {
  string s;
  while (getline(cin, s)) {
    s += ";";
    stringstream ss(s);
    string _, id, col;
    ss >> _;
    ss >> id; id.pop_back();
    ll cnt, r, g, b;
    r = g = b = 0;
    while (ss >> cnt >> col) {
      bool f = (col.back() == ';');
      col.pop_back();
      if (col[0] == 'r') r += cnt;
        else if (col[0] == 'g') g += cnt;
        else b += cnt;
      if (f) {
        mp[stoll(id)].push_back(make_tuple(r, g, b));
        r = g = b = 0;
      }
    }
  }
}

ll solve() {
  ll ans = 0;
  for (auto [id, a] : mp) {
    ll pr, pg, pb;
    pr = pg = pb = 0;
    for (auto [r, g, b] : a) {
      pr = max(pr, r);
      pb = max(pb, b);
      pg = max(pg, g);
    }
    ans += pr*pb*pg;
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}