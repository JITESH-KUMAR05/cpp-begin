// SofaProblem
// Problem Description
// Leo is trying to move his sofa to different place in his house. The issue is that the house is filled with lot of household items already.

// His home will be divided into cells of M rows and N columns like a matrix. The matrix is used to represent the house and the things in it. The current placement of sofa will be represented as "s" and place where the sofa is required will be represented as "S". "H" represents the presence of household items while "0" indicates empty spaces where the Sofa can be moved. The sofa will always occupy two cells and can either move vertically or horizontally. The sofa can be rotated, but the rotation can only occur within a 2*2 area of free cells that includes the sofa. The destination to where the sofa needs to be moved will always be free of household items.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image1.png

// Since sofa is heavy object, it must only be moved and not lifted. Help Leo to find the minimum possible steps required to move the sofa to the required place without altering the positions of other household items. Moving the sofa one cell as well as rotating the sofa are considered as one step.

// Constraints
// 4 < M, N < 25

// Input
// First line contains two space separated integers representing M, N.

// Next M lines contain N space separated characters being either "s", "S", "H" or "0" representing the house's matrix.

// Output
// Print a single integer representing minimum number of steps required to move the sofa to the required place. Print "Impossible" if it is impossible to move the sofa to the required place.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 5 5
// s s 0 0 0
// 0 H 0 0 H
// 0 H 0 H H
// 0 H 0 0 H
// 0 0 0 S S

// Output

// 8

// Explanation

// The diagram shown in the description depicts the input given

// Below diagrams show the movement of sofa to the required place.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@25f9407e:image2.png

// After two moves, the sofa occupies a 2x2 area of free cells, allowing it to be rotated. Following this process, the sofa has been moved to its destination in 8 steps, which represents the minimum required.

// Example 2

// Input

// 5 5
// s s 0 H 0
// 0 H 0 0 H
// 0 H 0 H H
// 0 H 0 0 H
// 0 0 0 S S

// Output

// Impossible

// Explanation

// As you can see it impossible to move the sofa to the required place without rotating and there is not enough place to rotate the sofa, hence print "Impossible".

#include<bits/stdc++.h>
using namespace std;


struct State {
    int r, c;    
    int orient;    
    int dist;      

    
    State(int _r, int _c, int _orient, int _dist) : r(_r), c(_c), orient(_orient), dist(_dist) {}
};

int R, C;
vector<string> grid;
bool visited[25][25][2];

bool is_safe(int r, int c) {
    return r >= 0 && r < R && c >= 0 && c < C && grid[r][c] != 'H';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> R >> C;
    
    vector<pair<int, int>> start_coords, target_coords;
    grid.assign(R, string(C, ' ')); 
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < C; ++j) {
            cin >> grid[i][j]; 
            
            if (grid[i][j] == 's') {
                start_coords.push_back({i, j});
                grid[i][j] = '0'; 
            } else if (grid[i][j] == 'S') {
                target_coords.push_back({i, j});
                grid[i][j] = '0'; 
            }
        }
    }
    State start_state(0,0,0,0), target_state(0,0,0,0);
    
    if (start_coords[0].first == start_coords[1].first) { // Horizontal
        start_state = State(start_coords[0].first, min(start_coords[0].second, start_coords[1].second), 0, 0);
    } else { // Vertical
        start_state = State(min(start_coords[0].first, start_coords[1].first), start_coords[0].second, 1, 0);
    }
   
    if (target_coords[0].first == target_coords[1].first) { // Horizontal
        target_state = State(target_coords[0].first, min(target_coords[0].second, target_coords[1].second), 0, 0);
    } else { // Vertical
        target_state = State(min(target_coords[0].first, target_coords[1].first), target_coords[0].second, 1, 0);
    }

    queue<State> q;
    memset(visited, false, sizeof(visited));

    q.push(start_state);
    visited[start_state.r][start_state.c][start_state.orient] = true;

    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        if (curr.r == target_state.r && curr.c == target_state.c && curr.orient == target_state.orient) {
            cout << curr.dist << '\n';
            return 0;
        }

        int r = curr.r, c = curr.c, o = curr.orient, d = curr.dist;

        // --- Translations ---
        if (o == 0) { // Horizontal
            if (is_safe(r, c - 1) && !visited[r][c - 1][0]) { q.push(State(r, c - 1, 0, d + 1)); visited[r][c - 1][0] = true; } // Left
            if (is_safe(r, c + 2) && !visited[r][c + 1][0]) { q.push(State(r, c + 1, 0, d + 1)); visited[r][c + 1][0] = true; } // Right
            if (is_safe(r - 1, c) && is_safe(r - 1, c + 1) && !visited[r - 1][c][0]) { q.push(State(r - 1, c, 0, d + 1)); visited[r - 1][c][0] = true; } // Up
            if (is_safe(r + 1, c) && is_safe(r + 1, c + 1) && !visited[r + 1][c][0]) { q.push(State(r + 1, c, 0, d + 1)); visited[r + 1][c][0] = true; } // Down
        } else { // Vertical
            if (is_safe(r - 1, c) && !visited[r - 1][c][1]) { q.push(State(r - 1, c, 1, d + 1)); visited[r - 1][c][1] = true; } // Up
            if (is_safe(r + 2, c) && !visited[r + 1][c][1]) { q.push(State(r + 1, c, 1, d + 1)); visited[r + 1][c][1] = true; } // Down
            if (is_safe(r, c - 1) && is_safe(r + 1, c - 1) && !visited[r][c - 1][1]) { q.push(State(r, c - 1, 1, d + 1)); visited[r][c - 1][1] = true; } // Left
            if (is_safe(r, c + 1) && is_safe(r + 1, c + 1) && !visited[r][c + 1][1]) { q.push(State(r, c + 1, 1, d + 1)); visited[r][c + 1][1] = true; } // Right
        }

        // --- Rotations ---
        // A rotation requires a 2x2 free area that includes the sofa.
        if (o == 0) { // Horizontal -> Vertical
            if (is_safe(r + 1, c) && is_safe(r + 1, c + 1)) { // Check 2x2 area below
                if (!visited[r][c][1]) { q.push(State(r, c, 1, d + 1)); visited[r][c][1] = true; }
                if (!visited[r][c + 1][1]) { q.push(State(r, c + 1, 1, d + 1)); visited[r][c + 1][1] = true; }
            }
            if (is_safe(r - 1, c) && is_safe(r - 1, c + 1)) { // Check 2x2 area above
                if (!visited[r - 1][c][1]) { q.push(State(r - 1, c, 1, d + 1)); visited[r - 1][c][1] = true; }
                if (!visited[r - 1][c + 1][1]) { q.push(State(r - 1, c + 1, 1, d + 1)); visited[r - 1][c + 1][1] = true; }
            }
        } else { // Vertical -> Horizontal
            if (is_safe(r, c + 1) && is_safe(r + 1, c + 1)) { // Check 2x2 area to the right
                if (!visited[r][c][0]) { q.push(State(r, c, 0, d + 1)); visited[r][c][0] = true; }
                if (!visited[r + 1][c][0]) { q.push(State(r + 1, c, 0, d + 1)); visited[r + 1][c][0] = true; }
            }
            if (is_safe(r, c - 1) && is_safe(r + 1, c - 1)) { // Check 2x2 area to the left
                if (!visited[r][c - 1][0]) { q.push(State(r, c - 1, 0, d + 1)); visited[r][c - 1][0] = true; }
                if (!visited[r + 1][c - 1][0]) { q.push(State(r + 1, c - 1, 0, d + 1)); visited[r + 1][c - 1][0] = true; }
            }
        }
    }

    cout << "Impossible" << '\n';

    return 0;
}