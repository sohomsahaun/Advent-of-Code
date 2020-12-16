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

int solve() {
    int i, ans;
    vector<bool> valid(N, 0);

    for (auto& field : fields) {
        for (i = field.l1; i <= field.r1; ++i) valid[i] = 1;
        for (i = field.l2; i <= field.r2; ++i) valid[i] = 1;
    }

    ans = 0;
    for (auto& ticket: nearbyTickets) {
        for (auto& x : ticket.values) {
            if (!valid[x]) ans += x;
        }
    }

    return ans;
}

int main() {
    freopen("in1.txt", "r", stdin);

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
