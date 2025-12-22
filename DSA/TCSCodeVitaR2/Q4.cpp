Cubemid
Problem Description
Deep beneath the sands of an ancient civilization lies the Cubemid a mysterious cube-shaped structure resembling a pyramid but extending equally in all three dimensions.

Recently, scientists have reconstructed its interior using quantum echo imaging, revealing that the Cubemid is composed of S × S × S interconnected chambers. Each chamber is either empty or contains a floor that allows the exploration team to walk upon it.

The input will be given as S layers of S x S chambers.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6d868997:image1.png

The S layers must be arranged from front to back.

The green layer will be the first, brown at last.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6d868997:image2.png

Each chamber in the cube is marked by one of the following types:

E - Empty space

D - Flat Floor, connecting chamber on left, right, front and back

R - Connects the current floor to upper-level right floor

L - Connects the current floor to upper-level left floor

F - Connects the current layer current floor to next layer down floor

B - Connects the current layer current floor to next layer upper floor

The explorers can only move through chambers that have a walkable floor (D, R, L, F, or B).

From a chamber with a flat floor (D), the team can move in any of the 4 directions (left, right, front, back), but only into valid, walkable chambers.

Your task is to determine the minimum number of steps required to reach the gold chamber from the specified starting chamber. The chambers are 0-indexed as (Layer, Row, Column).

Constraints
3 <= S <= 10

Input
The first line contains an integer S denoting the number of layers

Next S x S lines each contain S alphabets (from amongst E, D, R, L, F, or B) each representing the state of the chambers corresponding to floor and the layer.Like first S lines for layer 0 and next S lines for layer 1 and so on.

The second last line consists of three space-separated integers that denote the starting chamber corresponding to (Layer, Row, Column) respectively

The last line contains three space-separated integers that represent the gold chamber corresponding to (Layer, Row, Column) respectively

Output
A single integer indicating the minimum number of steps needed to reach the gold chamber from the specified starting chamber.

Time Limit (secs)
1

Examples
Example 1

Input

3

DEE

ELD

EEE

EEE

EED

EEE

EEE

EED

DRE

0 0 0

2 2 0

Output

6

Explanation

The image below depicts the input. 3 Layers, each having 3 floors, each having 3 chambers.

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6d868997:image3.png

The starting chamber is (0, 0, 0) i.e. We are cell (0, 0) on 0th layer. We walk in chambers D (0, 0, 0), L (0, 1, 1), D (0, 1, 2). Then go D (1, 1, 2), D (2, 1, 2) and then R (2, 2, 1), D (2,2,0) reaching the golden chamber covering 6 chambers on the way. Hence, the output is 6.

Example 2

Input

4

DEEE

ELEE

EELD

EEEE

DEEE

EEEE

EEED

EEEE

DEEE

EEEE

EEED

EEEE

DEEE

ELEE

EELD

EEEE

0 0 0

2 2 3

Output

5

Explanation

The image below depicts the input. 4 Layers, each having 4 floors, each having 4 chambers

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6d868997:image4.png

The first and second yellow highlighted cells depict the starting and gold chambers, respectively. Their co-ordinates are (0, 0, 0) and (2, 2, 3) as mentioned in the last two lines of the input.

Following the green cells path, we can reach the gold chamber while covering 5 chambers, viz. L (0, 1, 1), L (0, 2, 2), D (0, 2, 3) , D (1, 2, 3) and finally D (2, 2, 3). Hence, the answer is 5.

Example 3

3

DEE

EEE

EED

EEE

FEE

EEB

EEE

DDD

EEE

0 0 0

0 2 2

Output

6

Explanation

The image below depicts the input. 3 Layers, each having 3 floors, each having 3 chambers

com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@6d868997:image5.png

For this example, representing in (layer, floor, chamber) fashion as done in previous 2 examples will not work because the semantics of F and B schematics as explained in Problem Description section cannot be understood with that representation. Hence, it is represented differently for getting a better understanding.

You are shown the left side of the cube for the left view and right side of the cube for the right view. The front view of the last layer is also shown.

From the images, we can infer that only one path exists from the starting chamber to golden chamber, and 6 chambers are covered enroute to the golden chamber. Hence, the output is 6.