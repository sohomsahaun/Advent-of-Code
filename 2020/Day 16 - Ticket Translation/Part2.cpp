#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#define N 1005

struct Field {
    string name;
    int l1, r1, l2, r2;

    Field (string name = "", int l1 = 0, int r1 = 0, int l2 = 0, int r2 = 0)
        : name(name), l1(l1), r1(r1), l2(l2), r2(r2) {}
};

struct Ticket {
    vector<int> values;
};

vector<Field> fields;
Ticket myTicket;
vector<Ticket> nearbyTickets;
vector<Ticket> validTickets;

bool is_between(int n, int l, int r) {
    return ((l <= n) && (n <= r));
}

bool is_departure(Field& field) {
    string s = field.name;
    if (s.size() < 9) return 0;
    if (s.substr(0, 9) != "departure") return 0;
    return 1;
}

ll solve() {
    int n,i, j, k, val, l1, r1, l2, r2, cnt;
    ll ans;
    bool f;
    vector<bool> valid(N, 0);
    vector<bool> taken(N, 0);

    for (auto& field : fields) {
        for (i = field.l1; i <= field.r1; ++i) valid[i] = 1;
        for (i = field.l2; i <= field.r2; ++i) valid[i] = 1;
    }

    for (auto& ticket: nearbyTickets) {
        f = 1;
        for (auto& x : ticket.values) {
            if (!valid[x]) f = 0;
        }
        if (f) validTickets.push_back(ticket);
    }

    n = validTickets.size();
    cnt = fields.size();
    vector<vector<int>> validPos(cnt);

    for (i = 0; i < cnt; ++i) {
        l1 = fields[i].l1; r1 = fields[i].r1;
        l2 = fields[i].l2; r2 = fields[i].r2;

        for (j = 0; j < cnt; ++j) {
            vector<int> ok(n, 0);

            for (k = 0; k < n; ++k) {
                val = validTickets[k].values[j];
                ok[k] += is_between(val, l1, r1) || is_between(val, l2, r2);
            }

            if (count(ok.begin(), ok.end(), 1) == n) validPos[i].push_back(j);
        }
    }

    vector<int> it(cnt);
    iota(it.begin(), it.end(), 0);
    sort(it.begin(), it.end(), [&](int p, int q) {
        return (validPos[p].size() < validPos[q].size());
    });

    vector<int> pos(cnt, -1);
    for (auto& x : it) {
        for (auto& p : validPos[x]) {
            if (!taken[p]) {
                taken[p] = 1;
                pos[x] = p;
                break;
            }
        }
    }

    ans = 1;
    for (auto& x : it) {
        if (is_departure(fields[x])) {
            ans *= myTicket.values[pos[x]];
        }
    }

    return ans;
}

int main() {
    freopen("in2.txt", "r", stdin);

    stringstream str;
    string s, ss, name, ignore;
    int l1, r1, l2, r2, num;
    char hyphen;

    while (getline(cin, s)) {
        if (s.empty()) break;

        str = stringstream(s);
        str >> name;
        while (name.back() != ':') {
            str >> ss;
            name += ss;
        }

        str >> l1 >> hyphen >> r1;
        str >> ignore;
        str >> l2 >> hyphen >> r2;

        fields.push_back(Field(name, l1, r1, l2, r2));
    }

    getline(cin, s);
    while (getline(cin, s)) {
        if (s.empty()) break;

        str = stringstream(s);
        while (getline(str, ss, ',')) {
            myTicket.values.push_back(stoi(ss));
        }
    }

    getline(cin, s);
    while (getline(cin, s)) {
        if (s.empty()) break;

        Ticket near;

        str = stringstream(s);
        while (getline(str, ss, ',')) {
            near.values.push_back(stoi(ss));
        }

        nearbyTickets.push_back(near);
    }

    cout << solve();

    return 0;
}
