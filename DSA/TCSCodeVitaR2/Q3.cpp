Folded Area
Problem Description
Konan is an origamist. Origami is the art of folding paper, and an origamist is a person who practices origami. She is currently working on an origami character-making tutorial, where she needs to draw figures to represent each folding step.

The sheet will be in square shaped and will be placed on origin towards the first quadrant. Initially, she will draw a line on the origami sheet. This is called as "folding line" through which the paper is going to get folded. Imagine walking along the folding line from starting point to ending point. Split the regions into left and right side regions.The left side region of the folding line will always folded onto the right side region. The folding line will always separate the sheet into two regions.

The sheet will be having four corners initially. A corner is basically a point where two adjacent sides of the given figure meets. After folding the paper along the folding line, you will get a new polygon. Given the area of the sheet and the cordinates of the folding line, your task is to print all the co-ordinates of the corners of the folded sheet,(resulting polygon).

Constraints
3 < Area of the sheet < 37

The starting and Ending point of the folding line will always on the edges / corners of the square

Input
The first line contains the area of the sheet.

Second line consists of four space separated integers representing the folding line. First two values representing (x, y) of starting point, second two values representing (x ,y) of ending point.

Output
It contains M lines, where M is the number of corners of the polygon resulting after folding

Each line contains two space separated values representing the (x ,y) of the current corner point

Restrict the output of points up to two decimal places.

Print the (x,y) co ordinates of polygon points obtained after folding in sorted order of x co ordinate,followed by y co ordinate

Time Limit (secs)
1

Examples
Input

4

0 1 1 2

Output

0.00 0.00

0.00 1.00

1.00 2.00

2.00 0.00

2.00 2.00

Explanation

The area will be four so the sheet will have sides of 2 units and it will be represented as (0,0), (0,2), (2,2), (2,0). And the folding line be (0,1),(1,2)

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image1.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image2.png

After folding,

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image3.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image4.png

since the folded region(left side) lies completely inside the right side, the edges of the new polygon are (0.0),(0,1),(1,2),(2,2),(2,0)

Hence the output is

0.00 0.00

0.00 1.00

1.00 2.00

2.00 0.00

2.00 2.00

Example 2

Input

9

0 1 3 2

Output

0.00 0.00

0.00 1.00

0.75 0.00

1.20 -0.60

2.00 0.00

3.00 0.00

3.00 0.75

3.00 2.00

3.60 1.20

Explanation:

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image5.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image6.png

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image7.pngcom.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@5c1bd44c:image8.png

#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-9;

struct Point {
    double x, y;
    bool operator<(const Point& other) const {
        if (abs(x - other.x) > EPS) return x < other.x;
        return y < other.y - EPS;
    }
    bool operator==(const Point& other) const {
        return abs(x - other.x) < EPS && abs(y - other.y) < EPS;
    }
};

double cross_product(Point a, Point b, Point c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

Point intersection(Point a, Point b, Point c, Point d) {
    double cp1 = cross_product(c, d, a);
    double cp2 = cross_product(c, d, b);
    if (abs(cp1 - cp2) < EPS) return {NAN, NAN};
    double t = cp1 / (cp1 - cp2);
    return {a.x + t * (b.x - a.x), a.y + t * (b.y - a.y)};
}

Point reflect(Point p, Point a, Point b) {
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double t = ((p.x - a.x) * dx + (p.y - a.y) * dy) / (dx * dx + dy * dy);
    double projx = a.x + t * dx;
    double projy = a.y + t * dy;
    return {2 * projx - p.x, 2 * projy - p.y};
}

bool on_segment(Point p, Point a, Point b) {
    return p.x >= min(a.x, b.x) - EPS && p.x <= max(a.x, b.x) + EPS &&
           p.y >= min(a.y, b.y) - EPS && p.y <= max(a.y, b.y) + EPS &&
           abs(cross_product(a, b, p)) < EPS;
}

bool is_strictly_inside(const vector<Point>& poly, Point p) {
    for (size_t i = 0; i < poly.size(); ++i) {
        if (on_segment(p, poly[i], poly[(i + 1) % poly.size()])) return false;
    }
    
    bool inside = false;
    for (size_t i = 0, j = poly.size() - 1; i < poly.size(); j = i++) {
        if (((poly[i].y > p.y) != (poly[j].y > p.y)) &&
            (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x)) {
            inside = !inside;
        }
    }
    return inside;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double area;
    if (!(cin >> area)) return 0;

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double s = sqrt(area);
    vector<Point> square = {{0, 0}, {s, 0}, {s, s}, {0, s}};
    Point p1 = {x1, y1};
    Point p2 = {x2, y2};

    vector<Point> left_poly, right_poly;
    
    for (size_t i = 0; i < square.size(); ++i) {
        Point cur = square[i];
        Point next = square[(i + 1) % square.size()];
        
        double cp1 = cross_product(p1, p2, cur);
        double cp2 = cross_product(p1, p2, next);

        if (cp1 > EPS) left_poly.push_back(cur);
        else if (cp1 < -EPS) right_poly.push_back(cur);
        else {
            left_poly.push_back(cur);
            right_poly.push_back(cur);
        }

        if ((cp1 > EPS && cp2 < -EPS) || (cp1 < -EPS && cp2 > EPS)) {
            Point inter = intersection(p1, p2, cur, next);
            left_poly.push_back(inter);
            right_poly.push_back(inter);
        }
    }

    if (left_poly.empty()) {
        sort(right_poly.begin(), right_poly.end());
        for (size_t i = 0; i < right_poly.size(); ++i) {
             cout << fixed << setprecision(2) << (abs(right_poly[i].x) < EPS ? 0.00 : right_poly[i].x) << " " 
                  << (abs(right_poly[i].y) < EPS ? 0.00 : right_poly[i].y);
             if (i != right_poly.size() - 1) cout << "\n";
        }
        return 0;
    }

    vector<Point> reflected_poly;
    for (auto p : left_poly) {
        reflected_poly.push_back(reflect(p, p1, p2));
    }

    vector<Point> result;
    
    auto add_point = [&](Point p) {
        for (const auto& existing : result) {
            if (existing == p) return;
        }
        result.push_back(p);
    };

    for (auto p : right_poly) {
        if (!is_strictly_inside(reflected_poly, p)) {
            add_point(p);
        }
    }

    for (auto p : reflected_poly) {
        if (!is_strictly_inside(right_poly, p)) {
            add_point(p);
        }
    }

    int n_right = right_poly.size();
    int n_ref = reflected_poly.size();
    
    if (n_right > 0 && n_ref > 0) {
        for (int i = 0; i < n_right; ++i) {
            Point a = right_poly[i];
            Point b = right_poly[(i + 1) % n_right];
            for (int j = 0; j < n_ref; ++j) {
                Point c = reflected_poly[j];
                Point d = reflected_poly[(j + 1) % n_ref];

                double cp1 = cross_product(c, d, a);
                double cp2 = cross_product(c, d, b);
                double cp3 = cross_product(a, b, c);
                double cp4 = cross_product(a, b, d);

                if (((cp1 > EPS && cp2 < -EPS) || (cp1 < -EPS && cp2 > EPS)) &&
                    ((cp3 > EPS && cp4 < -EPS) || (cp3 < -EPS && cp4 > EPS))) {
                    add_point(intersection(a, b, c, d));
                }
            }
        }
    }

    sort(result.begin(), result.end());

    cout << fixed << setprecision(2);
    for (size_t i = 0; i < result.size(); ++i) {
        double val_x = (abs(result[i].x) < EPS) ? 0.00 : result[i].x;
        double val_y = (abs(result[i].y) < EPS) ? 0.00 : result[i].y;
        cout << val_x << " " << val_y;
        if (i != result.size() - 1) cout << "\n";
    }

    return 0;
}