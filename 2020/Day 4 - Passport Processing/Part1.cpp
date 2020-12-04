#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int solve(vector<map<string,string>>& v) {
    int cnt = 0, f;
    for (auto mp : v) cnt += (mp.size() == 7);
    return cnt;
}

int main() {
    freopen("in1.txt", "r", stdin);

    stringstream str;
    string s;
    vector<map<string,string>> input;
    map<string,string> mp;
    while (getline(cin,s)) {
        if (s == "") {
            input.push_back(mp);
            mp.clear();
            continue;
        }
        str = stringstream(s);
        string r, key, val;
        int i;
        while (str >> r) {
            for (i = 0; i < r.size(); ++i) {
                if (r[i] == ':') break;
            }
            key = r.substr(0, i);
            val = r.substr(i+1);
            if (key == "cid") continue;
            mp[key] = val;
        }
    }

    cout << solve(input);

    return 0;
}
