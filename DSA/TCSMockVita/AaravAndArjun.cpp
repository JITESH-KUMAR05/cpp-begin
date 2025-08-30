// Aarav And Arjun
// Problem Description
// Aarav and Arjun, twin brothers in the eighth grade, enjoy spending time together playing. They have already learned about shapes, area, perimeter, and other geometric concepts.

// Their mother decided to introduce a game to enhance their geometric skills. She took some very thin straight and elastic sticks and arranged them on a 2D coordinate system, trying to form a closed figure.

// Given the positions of the sticks in the coordinate system, she asked both of them to make a choice viz. 1) the closed figure, or 2) the left-over stick pieces (all the pieces that do not take part in forming the closed figure).

// Aarav went with closed figure while Arjun went with left over pieces. Arjun is allowed to cut the left-over pieces in any manner that he chooses to attempt to fulfil his mother's ask as stated below.

// She asks both of them to calculate the things in the below order.

// Check whether closed figure is formed.
// If formed,
// Calculate its area.
// Find whether Arjun can form the same shape and sized figure using any combination of the sticks he got.
// If the sticks did not form a closed figure, they would ask her for a new arrangement. In that case, they will skip the previous steps i.e. calculation of area etc.
// Solve the same problem that Aarav and Arjun are trying to solve.

// Given the coordinates of the starting and ending points of the sticks placed in a 2D coordinate system, print the respective output following the output specification.

// Constraints
// 1 <= N <= 20

// 0 <= x, y coordinates <= 50

// There can at most be one closed figure.

// Closed figure is a figure with number of sides >= 3.

// Left-over sticks will not intersect with lines of closed figure, but themselves they may intersect.

// No more than two lines intersect at the same point.

// All computations must be accurate, including round-off, up to two decimal points.

// Input
// First line consists of an integer N, denoting the number of sticks placed in the 2D coordinate system.

// Next N lines consist of four space separated integers x1 y1 x2 y2, where (x1, y1) and (x2, y2) denote the starting and ending points of the stick.

// Output
// In the first line, print "Yes" or "No" indicating whether a closed figure is formed or not.

// If the first line of output is "Yes", then two more lines should be printed.

// Second line - Print "Yes" if Arjun can arrange the leftover stick pieces to form a figure that is both the same shape and the same size. He is allowed to cut and join the leftover sticks. Also use the part of sticks hanging out of closed figure.
// Third line - Print the area of the closed figure up to 2 decimal points.
// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 4

// 2 1 2 6

// 5 1 5 6

// 0 2 6 2

// 0 5 6 5

// Output

// Yes

// No

// 9.00

// Explanation

// The above input when plotted looks like below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67207d8a:image1.png

// Here, you can see that a closed figure is formed. So, print "Yes" in the first line and the next two lines of output do exist.

// As you can see that with the left-over sticks, one cannot form the closed figure of same shape and size. Hence, print "No" on the second line.

// And the area of the closed figure is 9, which we need to print up to 2 decimal points, hence print 9.00

// Hence, the output looks like below -

// Yes

// No

// 9.00

// Example 2

// Input

// 5

// 4 1 4 5

// 5 0 1 4

// 1 2 5 6

// 0 0 3 1

// 5 2 5 5

// Output

// Yes

// Yes

// 4.00

// Explanation

// The above input when plotted looks like below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67207d8a:image2.png

// Here, you can see that a closed figure is formed. So, print "Yes" in the first line and the next two lines of output do exist.

// As you can see that with the left-over sticks, you can form the closed figure of same shape and size. Hence, print "Yes" on the second line.

// And the area of the closed figure is 4, which we need to print up to 2 decimal points, hence print 4.00

// Hence, the output looks like below -

// Yes

// Yes

// 4.00

// Example 3

// Input

// 6

// 0 4 0 6

// 1 2 4 4

// 5 5 5 1

// 1 6 4 4

// 1 4 3 1

// 4 2 6 3

// Output

// No

// Explanation

// The above input when plotted looks like below.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@67207d8a:image3.png

// Since there is no closed figure for