#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int cnum(string s) {
    if (s.empty()) return -1;
    for (char c : s) {
        if ((c < '0') || (c > '9')) return -1;
    }
    return stoi(s);
}

bool check(string key, string val) {
    if (key == "byr") {
        int x = cnum(val);
        if (x == -1) return 0;
        return ((1920 <= x) && (x <= 2002));
    } else if (key == "iyr") {
        int x = cnum(val);
        if (x == -1) return 0;
        return ((2010 <= x) && (x <= 2020));
    } else if (key == "eyr") {
        int x = cnum(val);
        if (x == -1) return 0;
        return ((2020 <= x) && (x <= 2030));
    } else if (key == "hgt") {
        string s = "";
        s += val.back(); val.pop_back();
        s += val.back(); val.pop_back();
        reverse(s.begin(), s.end());
        int x = cnum(val);
        if (x == -1) return 0;
        if (s == "cm") return ((150 <= x) && (x <= 193));
            else if (s == "in") return ((59 <= x) && (x <= 76));
        return 0;
    } else if (key == "hcl") {
        string s = val;
        if (val.size() != 7) return 0;
        if (val[0] != '#') return 0;
        for (int i = 1; i < 7; ++i) {
            if (('0' <= s[i]) && (s[i] <= '9')) continue;
            if (('a' <= s[i]) && (s[i] <= 'f')) continue;
            return 0;
        }
        return 1;
    } else if (key == "ecl") {
        set<string> st;
        st.insert("amb");
        st.insert("blu");
        st.insert("brn");
        st.insert("gry");
        st.insert("grn");
        st.insert("hzl");
        st.insert("oth");
        return (st.find(val) != st.end());
    } else if (key == "pid") {
        if (val.size() != 9) return 0;
        int x = cnum(val);
        return (x != -1);
    }
}

int solve(vector<map<string,string>>& v) {
    int cnt = 0, f;
    for (auto mp : v) {
        f = (mp.size() == 7);
        for (auto p : mp) {
            if (!check(p.first, p.second)) f = 0;
        }
        cnt += f;
    }
    return cnt;
}

int main() {
    freopen("in2.txt", "r", stdin);

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
