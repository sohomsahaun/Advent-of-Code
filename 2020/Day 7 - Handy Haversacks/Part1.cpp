#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 100005
vector<int> tree[N];
bool vis[N];
map<string,int> mp;
int id = 0;

bool register_bag(string& s) {
    if (mp.find(s) != mp.end()) return 0;
    mp[s] = id++;
    return 1;
}

void add_edge(string& from, string& to) {
    register_bag(from);
    register_bag(to);

    tree[mp[from]].push_back(mp[to]);
}

bool is_number(string& s) {
    for (char c : s) {
        if ((c < '0') || (c > '9')) return 0;
    }
    return 1;
}

void dfs(int u) {
    vis[u] = 1;
    for(int v : tree[u]) dfs(v);
}

int solve() {
    dfs(mp["shinygold"]);

    int cnt = 0;
    for (int i = 0; i < id; ++i) cnt += vis[i];

    return cnt-1;
}

int main() {
    freopen("in1.txt", "r", stdin);

    stringstream str;
    string s, ss, par, child;
    vector<string> input;
    bool f;

    while (getline(cin, s)) {
        str = stringstream(s);
        f = 0;
        par = "";
        child = "";

        while (str >> ss) {
            if (ss.substr(0, 3) == "bag") break;
            par += ss;
        }

        while (str >> ss) {
            if (is_number(ss)) {
                f = 1;
            } else if (f) {
                if (ss.substr(0, 3) == "bag") {
                    f = 0;
                    add_edge(child, par);
                    child = "";
                } else {
                    child += ss;
                }
            }
        }
    }

    cout << solve();

    return 0;
}
