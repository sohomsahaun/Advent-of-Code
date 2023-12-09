#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int HIGH_CARD = 1;
const int ONE_PAIR = 2;
const int TWO_PAIR = 3;
const int THREE_OF_A_KIND = 4;
const int FULL_HOUSE = 5;
const int FOUR_OF_A_KIND = 6;
const int FIVE_OF_A_KIND = 7;

int get_card_strength(char card) {
  if (card == 'A') return 14;
  if (card == 'K') return 13;
  if (card == 'Q') return 12;
  if (card == 'J') return 0;
  if (card == 'T') return 10;
  return (card-'0');
}

struct Hand {
  string cards;
  int type;

  Hand() {}
  Hand(string cards) : cards(cards) {
    type = calc_type();
  }

  int calc_type() {
    int j = 0;
    map<char,int> mp;
    for (char c : cards) {
      if (c == 'J') j += 1;
        else mp[c] += 1;
    }

    vector<int> v;
    for (auto [_, cnt] : mp) v.push_back(cnt);
    sort(v.begin(), v.end());

    int n = v.size();
    switch (n) {
      case 5:
        return HIGH_CARD;
      case 4:
        if (j == 1) return ONE_PAIR;
        return ONE_PAIR;
      case 3:
        if (j == 2) return THREE_OF_A_KIND;
        if (j == 1) return THREE_OF_A_KIND;
        return ((v.back() == 3) ? THREE_OF_A_KIND : TWO_PAIR);
      case 2:
        if (j == 3) return FOUR_OF_A_KIND;
        if (j == 2) return FOUR_OF_A_KIND;
        if (j == 1) return ((v.back() == 3) ? FOUR_OF_A_KIND : FULL_HOUSE);
        return ((v.back() == 4) ? FOUR_OF_A_KIND : FULL_HOUSE);
      case 1:
      case 0:
        return FIVE_OF_A_KIND;
      default: break;
    }

    return 0;
  }


  bool operator < (const Hand& other) const {
    if (type != other.type) return (type < other.type);
    for (int i = 0; i < cards.size(); ++i) {
      int x = get_card_strength(cards[i]);
      int y = get_card_strength(other.cards[i]);
      if (x == y) continue;
      return (x < y);
    }
    return 0;
  }
};

vector<pair<Hand,ll>> a;

void get_input() {
  string s;
  while (getline(cin, s)) {
    stringstream ss(s);

    string cards;
    ll bid;
    ss >> cards >> bid;

    a.push_back({ Hand(cards), bid });
  }
}

ll solve() {
  sort(a.begin(), a.end());
  ll ans = 0;
  for (int i = 0; i < a.size(); ++i) {
    ans += a[i].second * (i+1);
  }
  return ans;
}

int main() {
  freopen("in.txt", "r", stdin);

  get_input();
  cout << solve() << "\n";

  return 0;
}