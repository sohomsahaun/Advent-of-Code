#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<string> a;

void get_input() {
  string s;
  while (cin >> s) a.push_back(s);
}

bool is_digit(char c) {
  return ('0' <= c) && (c <= '9');
}

ll solve() {
  int i;
  ll ans = 0;
  for (auto s : a) {
    string num = "";
    for (i = 0; i < s.size(); ++i) {
      if (is_digit(s[i])) {
        num += s[i];
        break;
      }
    }
    for (i = s.size()-1; i >= 0; --i) {
      if (is_digit(s[i])) {
        num += s[i];
        break;
      }
    }
    ans += stoll(num);
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}