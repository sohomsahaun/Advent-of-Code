#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<string,vector<ll>>> a;

vector<ll> explode(string s, char c) {
  s += c;
  string t = "";
  vector<ll> v;
  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == c) {
      v.push_back(stoll(t));
      t = "";
    } else {
      t += s[i];
    }
  }
	return v;
}

void get_input() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);
    string state, nums;
    ss >> state >> nums;
    a.push_back({ state, explode(nums, ',') });
  }
}

const int MX = 50;
ll dp[MX][MX][MX];
string S;
vector<ll> seq;

ll solve(int ind, int sind, int taken) {
  if (sind >= seq.size()) {
    for (int i = ind; i < S.size(); ++i) {
      if (S[i] == '#') return 0;
    }
    return 1;
  }
  if (ind >= S.size()) return 0;

  ll& curr = dp[ind][sind][taken];
  if (curr != -1) return curr;

  curr = 0;
  
  if (S[ind] == '.') {
    if (taken == seq[sind]) curr += solve(ind+1, sind+1, 0);
      else if (taken == 0) curr += solve(ind+1, sind, 0);
      else return 0;
  } else if (S[ind] == '#') {
    curr += solve(ind+1, sind, taken+1);
  } else {
    if (taken == seq[sind]) curr += solve(ind+1, sind+1, 0);
      else if (taken == 0) curr += solve(ind+1, sind, 0);
    curr += solve(ind+1, sind, taken+1);
  }

  return curr;
}

ll solve() {
  ll ans = 0;
  for (auto [x, y] : a) {
    S = x + ".";
    seq = y;
    memset(dp, -1, sizeof(dp));
    ans += solve(0, 0, 0);
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}