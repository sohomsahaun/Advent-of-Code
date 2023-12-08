#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MX = 100005;
pair<int,int> g[MX];
map<string,int> mp;
string cmd;
int ans;

int get_id(string s) {
  static int id = 0;
  if (mp.find(s) == mp.end()) mp[s] = id++;
  return mp[s];
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
  int n, i, u, ans;
  n = cmd.size();
  ans = 0;
  u = get_id("AAA");
  i = 0;
  while (u != get_id("ZZZ")) {
    u = (cmd[i] == 'L') ? g[u].first : g[u].second;
    ans += 1;
    i = (i+1) % n;
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}