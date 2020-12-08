#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 100005
vector<pair<int,int>> graph[N];
map<string,int> mp;
int id = 0;

bool register_bag(string& s) {
    if (mp.find(s) != mp.end()) return 0;
    mp[s] = id++;
    return 1;
}

void add_edge(string& from, string& to, int weight) {
    register_bag(from);
    register_bag(to);

    graph[mp[from]].push_back({mp[to], weight});
}

bool is_number(string& s) {
    for (char c : s) {
        if ((c < '0') || (c > '9')) return 0;
    }
    return 1;
}

int dfs(int u) {
    int cnt = 1;
    int v, w;
    for(auto p : graph[u]) {
        v = p.first;
        w = p.second;
        cnt += dfs(v)*w;
    }
    return cnt;
}

int solve() {
    return dfs(mp["shinygold"])-1;
}

int main() {
    freopen("in2.txt", "r", stdin);

    stringstream str;
    string s, ss, par, child;
    vector<string> input;
    int weight;

    while (getline(cin, s)) {
        str = stringstream(s);
        weight = -1;
        par = "";
        child = "";

        while (str >> ss) {
            if (ss.substr(0, 3) == "bag") break;
            par += ss;
        }

        while (str >> ss) {
            if (is_number(ss)) {
                weight = stoi(ss);
            } else if (weight != -1) {
                if (ss.substr(0, 3) == "bag") {
                    add_edge(par, child, weight);
                    weight = -1;
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
