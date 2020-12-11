#include <bits/stdc++.h>

using namespace std;
using ll = long long;

vector<string> in;

int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct Count {
    int occupied, unoccupied, floor;

    Count(int occupied = 0, int unoccupied = 0, int floor = 0)
        : occupied(occupied), unoccupied(unoccupied), floor(floor) {}
};

bool valid(int r, int c, int rows, int cols) {
    if ((r < 0) || (r >= rows)) return 0;
    if ((c < 0) || (c >= cols)) return 0;
    return 1;
}

Count get_count(vector<string>& grid, int r, int c) {
    int rows, cols, i, j, rr, cc, o, e, f;
    rows = grid.size();
    cols = grid[0].size();

    o = e = f = 0;

    for (i = 0; i < 8; ++i) {
        rr = r+dr[i];
        cc = c+dc[i];

        while (valid(rr, cc, rows, cols) && (grid[rr][cc] == '.')) {
            rr += dr[i];
            cc += dc[i];
        }

        if (!valid(rr, cc, rows, cols)) continue;

        o += (grid[rr][cc] == '#');
        e += (grid[rr][cc] == 'L');
        f += (grid[rr][cc] == '.');
    }

    return Count(o, e, f);
}

vector<string> get_next_state(vector<string>& grid) {
    int rows, cols, i, j;
    rows = grid.size();
    cols = grid[0].size();

    vector<string> newGrid(rows, string(cols, '-'));

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            char ch = grid[i][j];
            Count cnt = get_count(grid, i, j);

            if (ch == 'L') {
                if (cnt.occupied == 0) ch = '#';
            } else if (ch == '#') {
                if (cnt.occupied >= 5) ch = 'L';
            }

            newGrid[i][j] = ch;
        }
    }

    return newGrid;
}

string grid_write(vector<string>& grid) {
    string s = "";
    for (auto r : grid) {
        for (auto c : r) s += c;
    }
    return s;
}

bool equals(vector<string>& grid1, vector<string>& grid2) {
    return (grid_write(grid1) == grid_write(grid2));
}

int solve() {
    int rows, cols, i, j, cnt;

    vector<string> prevGrid, grid;
    prevGrid = in;
    grid = get_next_state(prevGrid);

    while (!equals(prevGrid, grid)) {
        prevGrid = grid;
        grid = get_next_state(grid);
    }

    rows = grid.size();
    cols = grid[0].size();
    cnt = 0;

    for (i = 0; i < rows; ++i) {
        for (j = 0; j < cols; ++j) {
            cnt += (grid[i][j] == '#');
        }
    }

    return cnt;
}

int main() {
    freopen("in2.txt", "r", stdin);

    stringstream str;
    string s, ss;

    while (getline(cin, s)) {
        in.push_back(s);
    }

    cout << solve();

    return 0;
}
