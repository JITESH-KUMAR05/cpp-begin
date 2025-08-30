// Bands
// Problem Description
// Two friends went to the mall for shopping. While there, they decided to buy friendship bands.

// The shop sells bands in pairs inside a case, which is exactly what they wanted. These bands could be of different shapes and sizes. These band pairs were displayed in a transparent box inside the shop. While most of them were fine i.e., two distinct and separate bands, in some cases the pairs of bands encased in the transparent box were not separate but were interlocked instead.

// Now, the bands should not be interlocked because then it would mean cutting one of them to separate the two. However, that was the case and there were complaints regarding the same.

// They did not want to miss out celebrating Friendship Day and desperately wanted the bands. Since the bands were packed in transparent cases, they could see the bands inside. They decided to select a good pair of bands from the case.

// They took photos of the cases and fed it to an AI program that could mathematically detect if there was interlocking between bands or not. The band case is represented in a square matrix format of size S. The bands are depicted by the characters "1" and "2," where they represent the first and second band, respectively. The period symbol "." indicates an empty space.

// The bands will only bend at right angles. One band will intersect the other exactly at a right angle, but they will never overlap at the corners. The character at the point of overlap indicates which band is on top, while the other character's band is underneath. To avoid confusion for them, the bands will not be kept adjacent and will have some space between them i.e. if a thread is running horizontal, then another thread will not run horizontal on the adjacent cells. vice versa for vertical also. the below assets_public/img represent the how the bands will not be arranged.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image1.png

// instead, it will be look like below.,

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image2.png

// The image below is an example of the case and the bands inside it.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image3.png

// Help the friends choose a case with non-interlocked bands i.e., check whether the given case with bands can be separated without cutting one of the bands.

// Constraints
// 5 < S < 25

// Input
// First line consists of an integer representing S, the side of the square matrix.

// Next S lines will consist of S characters either ".", "1" or "2" representing the case with bands.

// Output
// Single integer denoting the number of overlaps if bands can be separated without cutting,

// else print "Impossible"

// Time Limit (secs)
// 1

// Examples
// Example 1

// Input

// 10

// .11111....

// .1...1....

// .1.22122..

// .1.2.1.2..

// .11211.2..

// ...2...2..

// ...22222..

// ..........

// ..........

// ..........

// Output

// Impossible

// Explanation

// The image below depicts the input described above.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image4.png

// From the image it is easy to see that the two bands cannot be separated without cutting any one of it. Hence print Impossible.

// Example 2

// Input

// 10

// .11111....

// .1...1....

// .1.22122..

// .1.2.1.2..

// .11111.2..

// ...2...2..

// ...22222..

// ..........

// ..........

// ..........

// Output

// 2

// Explanation

// The image below depicts the input described above.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image5.png

// The band 1 is just placed above the band 2. They are not interlocked and can be separated without cutting. Since they are overlapping at two positions, the output is 2.

// Example 3

// Input

// 12

// .1111111111.

// .1........1.

// .1...111111.

// .1...1......

// .1.221222...

// .1.2.1..222.

// .1.2.1....2.

// .1.22122222.

// .1...1......

// .1...111111.

// .1........1.

// .1111111111.

// Output

// 2

// Explanation

// The image below depicts the input described above.

// com.tcs.cv.automata.ei.middleware.DocxToHtmlConverter@7e0aadd0:image6.png

// The band 1 is just placed above the band 2. They are