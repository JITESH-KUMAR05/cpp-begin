

// Learning With Clock
// Problem Description
// Deva recently learned about angles in his mathematics class and is eager to explore them further! He began learning about angles using a wall clock.

// He chose an ancient wall clock for his learning. This clock has only two hands: the hour hand and the minute hand. The hour hand moves to the next hour only after the minute hand completes a full rotation, staying at the current hour until then. The task is to form a given angle between the two hands of the clock. The rules for forming the given angle are as follows -

// Starting from the given position, you can move both hands, but in opposite directions without crossing each other. For example, if you move the hour hand clockwise, you must move the minute hand counterclockwise, and vice versa, without them crossing over each other.
// The hour hand can only be moved from one hour to the next or previous hour; it cannot be positioned between the hours. However, there are no such restrictions for the minute hand.
// There is a cost attached to moving either the hour hand or minute hand. Likewise, the direction in which each of them is moved also has different costs attached to it as follows.
// The cost of moving a hand clockwise incurs cost of A rupees
// The cost of moving a hand anti-clockwise incurs cost of B rupees.
// The cost of moving hour hand is X rupees
// The cost of moving minutes hand is Y rupees.
// All costs are for per degree.
// You can form the given angle in any direction i.e. it can either be exterior angle or interior angle. Refer figures in example below for better understanding.
// For example, if the time is 12:15 and one needs to form an angle of 300 degrees, one can achieve this by moving the minute hand 30 degrees in anti-clockwise direction (i.e., from the 3 to the 2), if the resulting cost is low, as shown in Figure 2 below.
// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image1.png


// Fig. 1

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image2.png


// Fig.2

// Given the initial time, an integer Q representing the number of queries, and four integers A, B, X, and Y as defined above, an angle will be provided in each query that one needs to form between the hands of the clock. For each query, determine the minimum cost required to form the specified angle and print the total minimum cost as the output.

// Constraints
// 0 <= Angle <= 360 degrees and Angle will be an integer

// 1 <= A, B, X and Y <= 10

// A, B, X and Y are unique.

// 1 <= Q <=20

// Input
// The first line contains the initial time in the format hours:minutes.

// The second line contains an integer Q, representing the number of queries.

// The third line contains four space delimited integers A, B, X, and Y respectively, as defined above.

// The next Q lines each contain a single integer, representing the angle that you need to form between the hands of the clock.

// Output
// A single integer representing the sum of minimum cost for processing each query.

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 2:35

// 4

// 1 2 3 4

// 200

// 160

// 60

// 130

// Output

// 670

// Explanation

// The initial time is 2:35, resembling the image below on the clock.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image3.png

// Fig. 3

// The first query is to form 200 degrees between the two hands. For this, we can set up the hands like below.

// Keep the hours hand in same position and move the minutes hand 10 degrees in clockwise direction. This will incur a cost of 10 * 4 * 1 = 40 rupees (10 degrees * cost of moving minutes hand * cost of moving clockwise).

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image4.png

// Fig. 4

// Next query is to form 160 degrees between the two hands which is already present as shown below. Thus, we need not make any changes, in this query. Hence no cost incurred.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image5.png

// Fig. 5

// Third query is to form 60 degrees between the two hands. For this, we can set up the hands like below.

// Move the hours hand 90 degrees in clockwise direction and move the minutes hand 10 degrees in anti-clockwise direction. This will incur a cost of (90 * 3 * 1) + (10 * 4 * 2) = 350 rupees.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image6.png

// Fig. 6

// Fourth query is to form 130 degrees between the two hands. For this, we can set up the hands like below.

// Keep the hour hand in the same position and move the minutes hand 70 degrees in clockwise direction. This will incur a cost of 70 * 4 * 1 = 280 rupees.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image7.png

// Fig. 7

// Hence the total cost incurred is 40 + 0 + 350 + 280 = 670. Hence output is 670.

// Example 2

// Input

// 8:25

// 1

// 5 8 3 9

// 68

// Output

// 990

// Explanation

// The initial time is 8:25, resembling the image below on the clock.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image8.png

// Fig. 8

// The only query is to form 68 degrees between the two hands. For this, we can set up the hands like below.

// Remain the hour hand in the same position and move the minutes hand 22 degrees in clockwise direction. This will incur a cost of 22 * 9 * 5 = 990 rupees (22 degrees * cost of moving minutes hand * cost of moving clockwise).

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67af833b:image9.png

// Fig. 9

// Hence, the total cost incurred is 990 rupees. Hence, the output is 990.