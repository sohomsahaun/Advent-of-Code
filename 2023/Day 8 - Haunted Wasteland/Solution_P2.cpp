#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100005;
pair<int,int> g[MX];
map<string,int> mp_id;
map<int,string> mp_s;
string cmd;
int ans;

int get_id(string s) {
  static int id = 0;
  if (mp_id.find(s) == mp_id.end()) {
    mp_id[s] = id;
    mp_s[id] = s;
    id += 1;
  }
  return mp_id[s];
}

void get_input() {
  cin >> cmd;

  string s;
  while (getline(cin, s)) {
    stringstream ss(s);

    string _, curr, l, r;
    cin >> curr >> _ >> l >> r;
    l.pop_back(); l = l.substr(1);
    r.pop_back();

    g[get_id(curr)] = { get_id(l), get_id(r) };
  }
}

ll solve() {
  int n, u, v, i, cnt;
  n = cmd.size();

  ll ans = 1;
  for (v = 0; mp_s.count(v) > 0; ++v) {
    u = v;
    if (mp_s[u].back() != 'A') continue;

    cnt = 0;
    i = 0;
    while (mp_s[u].back() != 'Z') {
      u = (cmd[i] == 'L') ? g[u].first : g[u].second;
      cnt += 1;
      i = (i+1) % n;
    }
    
    ans = lcm(ans, cnt);
    // Apparently the input was just "nice" ¯\_(ツ)_/¯
  }

  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}