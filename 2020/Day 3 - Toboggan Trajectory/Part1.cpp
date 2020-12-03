#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll count_trees(vector<string>& grid, ll right, ll down) {
    ll n, m, i, j, cnt = 0;
    n = grid.size();
    m = grid[0].size();
    i = down;
    j = right;
    for (i = i; i < n; i += down) {
        cnt += (grid[i][j] == '#');
        j = (j + right) % m;
    }
    return cnt;
}

ll solve(vector<string>& grid) {
    return count_trees(grid, 3, 1);
}

int main() {
    freopen("in1.txt", "r", stdin);

    string s;
    vector<string> input;
    while (cin >> s) {
        input.push_back(s);
    }

    cout << solve(input);

    return 0;
}
