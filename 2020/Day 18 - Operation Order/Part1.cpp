#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> in;

vector<char> tokenize(string s) {
    vector<char> tokens;
    for (auto& c : s) {
        if (c == ' ') continue;
        tokens.push_back(c);
    }
    return tokens;
}

ll calc(ll a, ll b, char c) {
    switch (c) {
        case '+': return a+b;
        case '*': return a*b;
    }
    return 0;
}

ll eval(vector<char> tokens) {
    stack<char> op;
    stack<ll> val;
    ll a, b;

    for (char& c : tokens) {
        if (c == '(') {
            op.push(c);
        } else if (c == ')') {
            while (op.top() != '(') {
                a = val.top(); val.pop();
                b = val.top(); val.pop();
                val.push(calc(a, b, op.top()));
                op.pop();
            }
            op.pop();
        } else if ((c == '+') || (c == '*')) {
            while (op.top() != '(') {
                a = val.top(); val.pop();
                b = val.top(); val.pop();
                val.push(calc(a, b, op.top()));
                op.pop();
            }
            op.push(c);
        } else {
            val.push(c-'0');
        }
    }

    return val.top();
}

ll solve() {
    ll ans = 0;
    for (auto& s : in) {
        ans += eval(tokenize("(" + s + ")"));
    }
    return ans;
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;

    while (getline(cin, s)) {
        in.push_back(s);
    }

    cout << solve();

    return 0;
}
