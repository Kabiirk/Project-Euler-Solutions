/*
Problem 53
There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, (5C3) = 10.

In general, (nCr) = n! / [ r!*(n-r)! ] 
where r<=n, n!=n*(n-1)*(n-2)*...*3*2*1, and 0!=1.

It is not until n = 23, that a value exceeds one-million:
i.e. 23C10 = 1144066

How many, not necessarily distinct, values of (nCr)
for 1<=n<=100, are greater than one-million?

Answer : 4075
*/

/*
TIPS:
Example on How to calculate nCr with Pascal's triangle
Ref. : https://www.statisticshowto.com/pascals-triangle/

How to Calculate nCr with Pascal's Triangle (brief explanation):
Say, for now, we have a small Pascal's triangle which looks like :
Row 0                   1
Row 1                 1   1
Row 2               1   2   1
Row 3             1   3   3   1
Row 4           1   4   6   4   1
Row 5         1   5  10   10  5   1
Row 6       1   6  15  20   15  6   1
Row 7     1   7  21  35  35   21  7   1

say we want to calculate 6C4, all we need to do is
go to Row 6 and see the (4+1)th element. (since 1st element is 1)
and we get 15.
This can be verified by the factorial approach as :
       6!
6C2 =  ───────────
       2! * (6-2)!

  6!
= ───────
  2! * 4!

  (6*5*4*3*2*1)
= ─────────────────
  (2*1) * (4*3*2*1)

  6*5
= ───
   2

= 3*5

= 15

In our Code,
pascal_triangle is a 2D Array, it holds vectors(each_line) which hold integers
i.e. makePascalTriangle(6) would fill pascal_triangle like :
pascal_triangle = 
[
    [1, 0, 0, 0, 0, 0],
    [1, 1, 0, 0, 0, 0],
    [1, 2, 1, 0, 0, 0],
    [1, 3, 3, 1, 0, 0],
    [1, 4, 6, 4, 1, 0],
    [1, 5, 10, 10, 5, 1]
]

we need not traverse the arrays again, whenever
pascal_triangle[n][r] exceeds 1,000,000 while
calculation, just increment res then and there.

NOTE : Brute-Force method using factorial is not 
       advised because n! can be REALLY large
       for values of n > 10 & handling Big Integer
       in C++ is a pain.

NOTE : I tried is with Dynamic 2D Vectors but answer was incorrect
       & since there are only 100*100 elements which we have to
       calculate once and WON'T traverse later, i used a 100*100 array.

Some other amazing approaches could be found at :
Since pascal's triangle is symmetric, we may only need to traverse half of it 
as demonsrated by :
Ref. : https://www.mathblog.dk/project-euler-53-cnr-exceed-one-million/

With factorial approach
Ref. : https://euler.stephan-brumme.com/53/
*/

#include <iostream>

using namespace std;

typedef unsigned long long ULL;

const ULL num_limits = 100;
ULL pascal_triangle[num_limits][num_limits];

int main()
{
    ULL limit = 1000000;
    ULL res = 0;

    // populate all leftmost 1's
    for (ULL n = 0; n <= num_limits; n++){
        pascal_triangle[n][0] = 1;
    }
    // poppulate all other numbers
    for (ULL n = 1; n <= num_limits; n++) {
        for (ULL r = 1; r <= n; r++) {
            pascal_triangle[n][r] = pascal_triangle[n - 1][r] + pascal_triangle[n - 1][r - 1];
            
            if (pascal_triangle[n][r] > limit){
                pascal_triangle[n][r] = limit;
                res++;
            }
        }
    }

    cout<<res<<endl;

    return 0;
}
