// Gravity Glide
// Problem Description
// Aarav is learning programming by creating fun simulations. One day, he decides to build a game where a ball drops onto a 2D grid filled with diagonal slides.

// Aarav's game involves a ball that drops onto a grid. The grid contains several diagonal slides, each placed randomly and tilted at a 45-degree angle. When the ball is dropped from a starting point, it will slide along a slope if it lands on one; otherwise, gravity pulls it straight down.

// Aarav starts with a certain amount of energy. For every unit of distance the ball slides, it uses 1 unit of energy. If the ball gets stuck between two slides, it can unlock itself by spending energy equal to the product of its current x-coordinate and y-coordinate. Once unlocked, the ball continues sliding along any available slide, still using 1 unit of energy per unit distance.

// The ball keeps moving until it either reaches the ground (x = 0) or runs out of energy and gets stuck. Slides may touch but never cross each other, creating complex paths where the ball can change direction. No two slides are collinear. From any given point, the ball will always have only one possible direction to move.

// Constraints
// 1 <= number of sliders <= 50

// 0 <= x, y coordinates <= 50

// The inputs will always ensure that from the given point, the ball will have only one possible direction to move.

// If the ball is on the slide, it should be considered on the outer side, not the inner side. Outer side is the side facing top of the grid.

// Input
// The first line contains an integer N, the number of slides.

// The next N lines each contain four space-separated integers, representing the starting and ending points of each slide.

// The last line contains three space-separated integers: the starting x and y coordinates of the ball, and its initial energy.

// Output
// Print the final position (x, y) where the ball lands.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 8

// 2 4 5 1

// 1 3 3 1

// 2 5 5 8

// 4 5 6 3

// 1 10 3 8

// 4 10 6 12

// 1 14 3 12

// 3 6 1 8

// 5 15 21

// Output

// 2 4

// Explanation

// The given input is visualized below.


// The black lines indicate sliders while the red dot is the position from where the ball is dropped.

// The ball starts at (5, 15) with 21 units of energy.
// It falls to (5, 11) due to gravity, then slides one unit (energy left: 20).
// Gravity pulls it to (4, 7), then it slides to (3, 6) (energy left: 19).
// At (3, 6), the ball is stuck. To unlock, it spends 18 energy (3 × 6), leaving 1 unit.
// With 1 unit energy left, it slides to (2, 5), then gravity pulls it to (2, 4), where it stops. Hence (2, 4) is the final position of the ball.
// Example 2

// Input

// 7

// 1 1 3 3

// 4 1 6 3

// 4 5 5 6

// 2 5 4 3

// 2 2 0 4

// 5 2 7 0

// 5 6 7 4

// 2 7 5

// Output

// 4 0

// Explanation

// The given input is visualized below.


// The black lines indicate sliders while the red dot is the position from where the ball is dropped.

// The ball starts at (2, 7) with 5 units of energy.
// Gravity pulls it to (2, 5), then it slides to (4, 3) (energy left: 3).
// Gravity pulls it to (4, 1), then to (4, 0), where it stops.


#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

struct Segment {
    Point p1, p2;
};


bool is_on_segment(const Point& p, const Segment& s) {
    
    bool in_x_box = (p.x >= min(s.p1.x, s.p2.x) && p.x <= max(s.p1.x, s.p2.x));
    bool in_y_box = (p.y >= min(s.p1.y, s.p2.y) && p.y <= max(s.p1.y, s.p2.y));
    if (!in_x_box || !in_y_box) {
        return false;
    }

    long long dxs = s.p2.x - s.p1.x;
    long long dys = s.p2.y - s.p1.y;
    long long dx1 = p.x - s.p1.x;
    long long dy1 = p.y - s.p1.y;

    if (dxs == 0 && dys == 0) {
        return p.x == s.p1.x && p.y == s.p1.y;
    }

    return dy1 * dxs == dys * dx1;
}

int count_segments_at_point(const Point& p, const vector<Segment>& segments) {
    int count = 0;
    for (const auto& s : segments) {
        if (is_on_segment(p, s)) {
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Segment> all_segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> all_segments[i].p1.x >> all_segments[i].p1.y >> all_segments[i].p2.x >> all_segments[i].p2.y;
    }

    Point ball_pos;
    long long energy;
    cin >> ball_pos.x >> ball_pos.y >> energy;

    while (ball_pos.y > 0) {
        Point landing_pos = {ball_pos.x, 0};
        int landing_segment_idx = -1;

        for (int y = ball_pos.y - 1; y >= 0; --y) {
            Point check_pos = {ball_pos.x, y};
            for (int i = 0; i < n; ++i) {
                if (is_on_segment(check_pos, all_segments[i])) {
                    if (y > landing_pos.y) { 
                        landing_pos = check_pos;
                        landing_segment_idx = i;
                    }
                }
            }
        }
        
        ball_pos = landing_pos;

        if (landing_segment_idx == -1 || energy <= 0) {
            break;
        }

        bool is_sliding = true;
        while (is_sliding) {
            if (energy <= 0 || ball_pos.y <= 0) {
                is_sliding = false;
                break;
            }

            if (count_segments_at_point(ball_pos, all_segments) > 1) {
                long long toll = (long long)ball_pos.x * ball_pos.y;
                if (energy < toll) {
                    energy = 0;
                    is_sliding = false;
                    break;
                }
                energy -= toll;
            }

            if (energy <= 0) {
                is_sliding = false;
                break;
            }
            
            int current_segment_idx = -1;
            Point target_end;

            for (int i = 0; i < n; ++i) {
                if (is_on_segment(ball_pos, all_segments[i])) {
                    Point temp_lower_end = (all_segments[i].p1.y < all_segments[i].p2.y) ? all_segments[i].p1 : all_segments[i].p2;
                    if (temp_lower_end.y < ball_pos.y) { 
                        current_segment_idx = i;
                        target_end = temp_lower_end;
                        break;
                    }
                }
            }

            if (current_segment_idx == -1) {
                is_sliding = false;
                break;
            }

            int dx = (target_end.x > ball_pos.x) ? 1 : -1;
            int dy = -1;
            
            int max_slide_dist = abs(ball_pos.x - target_end.x);
            int travel_dist = max_slide_dist;
            Point next_stop = target_end;

            for (int d = 1; d < max_slide_dist; ++d) {
                Point path_pos = {ball_pos.x + dx * d, ball_pos.y + dy * d};
                bool is_intersection = false;
                for(int j=0; j<n; ++j) {
                    if(j == current_segment_idx) continue;
                    if(is_on_segment(path_pos, all_segments[j])) {
                        is_intersection = true;
                        break;
                    }
                }

                if (is_intersection) {
                    travel_dist = d;
                    next_stop = path_pos;
                    break;
                }
            }

            if (energy < travel_dist) {
                ball_pos.x += dx * energy;
                ball_pos.y += dy * energy;
                energy = 0;
                is_sliding = false;
            } else {
                energy -= travel_dist;
                ball_pos = next_stop;
            }
        }
    }

    cout << ball_pos.x << " " << ball_pos.y << endl;
    return 0;
}