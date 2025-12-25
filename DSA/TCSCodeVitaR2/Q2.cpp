Ascii Homes
Problem Description
You are required to develop a program that generates and displays several ASCII art houses with different sizes and orientations, ensuring they are aligned neatly side by side along a common base level.

Each house is represented using ASCII characters /, \, @, &, and #.
The house consists of a roof (formed by slashes) and walls (formed by @ and & representing the left and right walls), ending with a base (#).
The input consists of multiple specifications in the form <length>x<height><direction>, where:
          length -> width of the house

          height -> height of the walls

          direction -> orientation of the house (H,U, D, L, or R)

Depending on the direction:
          H -> No tilting, visualize the house as it is

          U -> Tilt the house upwards

          D -> Tilt the house downwards

          L -> Tilt left (mirror reflection along the left)

          R -> Tilt right (mirror reflection along the right)

All houses are padded and aligned such that their bases lie on the same level, appearing seamlessly side by side without any gaps between the houses.
A 2x4 home looks like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image1.png

Fig.1

A 4x6 home looks like below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image2.png

Fig.2

Constraints
1 <= number of houses <= 100

2 <= length, height <= 100

direction ∈ {U, D, L, R, H}

Input
A single line containing one or more space-separated house specifications in the format defined above.

Output
Print the resulting multi-line ASCII art houses next to each other.

You may refer to Example section for better understanding.

Time Limit (secs)
1

Examples
Example 1

Input

6x3U 4x2U 8x4L 2x2H

Output

/\

/ \

###### / \

@ & / \

@ &####& @

\ /@ && @/\

\ / \ /& @@&

\/ \/ ##########

Explanation

The output is shown in the below diagram.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image3.png

Fig.3

The first two houses, sized 6x3 and 4x2, are tilted upward; the third house, sized 8x4, is tilted to the left; and the fourth house, sized 2x2, is displayed in its original orientation.

Example 2

Input

4x6R 12x8H 2x6D

Output

/\

/ \

/ \

/ \

/ \

/ \

/\ @ &

/ \@ &##

& @@ &@&

& @@ &@&

& @@ &@&

& @@ &@&

& @@ &@&

################\/

Explanation

The output is shown in the diagram below.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6e6fce47:image4.png

Fig.4

The first house, sized 4x6, is tilted to the right; the second house, sized 12x8, is displayed in its normal upright position; and the third house, sized 2x6, is tilted downward.


#include <bits/stdc++.h>

using namespace std;

struct House {
    int w, h;
    char dir;
};

int main() {
    string line;
    if (!getline(cin, line) || line.empty()) return 0;

    stringstream ss(line);
    vector<House> houses;
    int w_in, h_in;
    char x_char, dir_in;

    while (ss >> w_in >> x_char >> h_in >> dir_in) {
        houses.push_back({w_in, h_in, dir_in});
    }

    if (houses.empty()) return 0;

    int total_width = 0;
    int max_height = 0;

    for (const auto& h : houses) {
        total_width += h.w;
        int current_h = h.h + (h.w / 2);
        if (current_h > max_height) max_height = current_h;
    }

    vector<string> grid(max_height, string(total_width, ' '));
    
    int cur_x = 0;
    int floor_y = max_height - 1;

    for (const auto& h : houses) {
        int w = h.w;
        int wall_h = h.h - 1;
        int roof_h = w / 2;
        char d = h.dir;

        char l_char = '@';
        char r_char = '&';

        if (d == 'L' || d == 'R') {
            l_char = '&';
            r_char = '@';
        }

        if (d == 'U' || d == 'D') {
            for (int r = 0; r < roof_h; r++) {
                int y = floor_y - r;
                int offset = (w / 2) - 1 - r;
                
                grid[y][cur_x + offset] = '\\';
                grid[y][cur_x + w - 1 - offset] = '/';
            }

            int wall_start = floor_y - roof_h;
            for (int r = 0; r < wall_h; r++) {
                int y = wall_start - r;
                if (y >= 0) {
                    grid[y][cur_x] = l_char;
                    grid[y][cur_x + w - 1] = r_char;
                }
            }

            int base_y = wall_start - wall_h;
            if (base_y >= 0) {
                for (int k = 0; k < w; k++) {
                    grid[base_y][cur_x + k] = '#';
                }
            }
        } else {
            for (int k = 0; k < w; k++) {
                grid[floor_y][cur_x + k] = '#';
            }

            int wall_start = floor_y - 1;
            for (int r = 0; r < wall_h; r++) {
                int y = wall_start - r;
                if (y >= 0) {
                    grid[y][cur_x] = l_char;
                    grid[y][cur_x + w - 1] = r_char;
                }
            }

            int roof_start = wall_start - wall_h;
            for (int r = 0; r < roof_h; r++) {
                int y = roof_start - r;
                int offset = r; 
                
                if (y >= 0) {
                    grid[y][cur_x + offset] = '/';
                    grid[y][cur_x + w - 1 - offset] = '\\';
                }
            }
        }
        cur_x += w;
    }

    int start_row = 0;
    while (start_row < max_height) {
        bool empty = true;
        for (char c : grid[start_row]) {
            if (c != ' ') {
                empty = false;
                break;
            }
        }
        if (!empty) break;
        start_row++;
    }

    for (int i = start_row; i < max_height; i++) {
        string row = grid[i];
        
        int last_char_idx = -1;
        for (int j = row.length() - 1; j >= 0; j--) {
            if (row[j] != ' ') {
                last_char_idx = j;
                break;
            }
        }
        
        if (last_char_idx != -1) {
            cout << row.substr(0, last_char_idx + 1);
        }
        cout << endl;
    }

    return 0;
}