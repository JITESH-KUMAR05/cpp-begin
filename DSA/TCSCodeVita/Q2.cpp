// Ladder Problem
// Problem Description
// Shyam is tasked with relocating a lengthy ladder within his residence. The substantial presence of various household items throughout the house presents significant challenges when attempting to manoeuvre the ladder through confined areas.

// The house is represented as a grid of M rows and N columns. Each cell in the grid can contain:

// 'l' - part of the current position of the ladder (source).
// 'L' - part of the destination where the ladder needs to go.
// 'B' - a household item (Block).
// 'E' - an empty cell where the ladder can move.
// The ladder has a fixed length and is placed either horizontally or vertically in the grid. It must always remain in a straight line unless it is being rotated.

// Movement Rules
// The ladder can be moved one cell at a time in any of the four directions (up/down/left/right), maintaining its orientation.
// The ladder can be rotated by 90 degrees (from horizontal to vertical or vice versa) only if all cells in the square area formed by both the current and rotated positions are empty (no B or walls).
// Each move or rotation counts as 1 step.
// Goal is to find the minimum number of steps required to move the ladder from the source ('l') to the destination ('L').
// If it is not possible, print "Impossible".

// Constraints
// 0 <= M, N <= 15

// 2 <= Length of ladder <= 6

// Input
// First line: Two integers M and N, the dimensions of the grid.

// Next M lines: N space-separated characters representing the grid ('l', 'L', 'B', or 'E').

// Output
// A single integer representing the minimum number of steps, or the string "Impossible".

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 5 5
// llEEE
// EBEEB
// EBEBB
// EBEEB
// EEELL

// Output

// 8

// Explanation

// The input is diagrammatically represented as depicted below.

// The sequence of diagrams shows the movement of ladder to the required place.


// After two moves, the ladder occupies a 2x2 area of free cells, allowing it to be rotated. Following this process, the ladder has been moved to its destination in 8 steps, which represents the minimum required.

// Example 2

// Input

// 6 6
// lllEEE
// EBEEEE
// EEEEEE
// EEEEBE
// EEEEEE
// LLLEBE

// Output

// 7

// Explanation

// Below diagrams shows the movement of ladder to the required place.


// As you can see that 7 steps are required to move the ladder to its destination.

#include <bits/stdc++.h>
using namespace std;

int R, C;
vector<string> grid;

struct State {
    int r, c, d, cost; 
};

State find_initial_state(char target_char) {
    vector<pair<int, int>> points;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            if (grid[i][j] == target_char) {
                points.push_back({i, j});
            }
        }
    }
    sort(points.begin(), points.end());
    bool is_horizontal = (points.size() > 1 && points[0].first == points[1].first);
    return {points[0].first, points[0].second, is_horizontal ? 0 : 1, 0};
}

bool is_valid(int r, int c, int d, int sz) {
    for (int i = 0; i < sz; ++i) {
        int current_r = (d == 1) ? r + i : r;
        int current_c = (d == 0) ? c + i : c;
        if (current_r < 0 || current_r >= R || current_c < 0 || current_c >= C || grid[current_r][current_c] == 'B') {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    grid.assign(R, string(C, ' '));
    int ladder_sz = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'l' || grid[i][j] == 'L') {
                ladder_sz++;
            }
        }
    }
    ladder_sz /= 2;

    State initial = find_initial_state('l');
    State target = find_initial_state('L');

    queue<State> bfs_q;
    set<tuple<int, int, int>> visited;

    bfs_q.push(initial);
    visited.insert({initial.r, initial.c, initial.d});

    while (!bfs_q.empty()) {
        State current_state = bfs_q.front();
        bfs_q.pop();

        if (current_state.r == target.r && current_state.c == target.c && current_state.d == target.d) {
            cout << current_state.cost << endl;
            return 0;
        }

        int move_r[] = {0, 0, 1, -1};
        int move_c[] = {1, -1, 0, 0};
        for (int i = 0; i < 4; ++i) {
            int next_r = current_state.r + move_r[i];
            int next_c = current_state.c + move_c[i];
            if (visited.find({next_r, next_c, current_state.d}) == visited.end() && is_valid(next_r, next_c, current_state.d, ladder_sz)) {
                visited.insert({next_r, next_c, current_state.d});
                bfs_q.push({next_r, next_c, current_state.d, current_state.cost + 1});
            }
        }

        int new_d = 1 - current_state.d;
        for (int i = 0; i < ladder_sz; ++i) {
            int p_r = (current_state.d == 1) ? current_state.r + i : current_state.r;
            int p_c = (current_state.d == 0) ? current_state.c + i : current_state.c;

            bool can_pivot = true;
            for (int k = 0; k < ladder_sz; ++k) {
                for (int l = 0; l < ladder_sz; ++l) {
                    int box_r = p_r + k;
                    int box_c = p_c + l;
                    if (box_r < 0 || box_r >= R || box_c < 0 || box_c >= C || grid[box_r][box_c] == 'B') {
                        can_pivot = false;
                        break;
                    }
                }
                if (!can_pivot) break;
            }

            if (can_pivot) {
                int final_r = p_r, final_c = p_c;
                if (new_d == 0) {
                    final_c = p_c - i;
                } else {
                    final_r = p_r - i;
                }

                if (visited.find({final_r, final_c, new_d}) == visited.end() && is_valid(final_r, final_c, new_d, ladder_sz)) {
                    visited.insert({final_r, final_c, new_d});
                    bfs_q.push({final_r, final_c, new_d, current_state.cost + 1});
                }
            }
        }
    }

    cout << "Impossible" << endl;
    return 0;
}