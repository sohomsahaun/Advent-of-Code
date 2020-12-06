#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int get_count(vector<string>& v) {
    vector<int> cnt(26, 0);

    for (auto s : v) {
        for (auto c : s) ++cnt[c-'a'];
    }

    int ans = 0;
    for (auto x : cnt) ans += (x > 0);
    return ans;
}

int solve(vector<vector<string>>& v) {
    int cnt = 0;
    for (auto g : v) cnt += get_count(g);
    return cnt;
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;
    vector<vector<string>> input;
    vector<string> v;
    while (getline(cin, s)) {
        if (s == "") {
            input.push_back(v);
            v.clear();
            continue;
        }
        v.push_back(s);
    }
    input.push_back(v);

    cout << solve(input);

    return 0;
}
