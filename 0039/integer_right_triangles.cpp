/*
Problem 39
If p is the perimeter of a right angle triangle with integral length sides, {a,b,c},
there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

Answer : 840
*/

/*
TIPS:
2 Equations : 
1) a^2 + b^2 = c^2
2) a + b+ c = p

this implies :
if a and b is even so is c and thus p is even

if a or b (but not both) is odd then c is odd and thus p is even

no matter what nature (a, b, c), p (perimeter) will
always be even, w=s we have to check only even values
of p.

we know a < c and b < c and without loss of generality
we can assume that a ≤ b (otherwise we could switch them)
which gives us that a ≤ b < c.  That implies  a < p/3 and
thus we don’t need to check values higher than that.

A faster Approach : 
Also we can use the Pythagorean triplets approach
addition of squares of a and b is equal to square of c, we
can write these number in terms of m and n such that :
a = m2 - n2
       b = 2 * m * n
       c  = m2 + n2
because,
       a2 = m4 + n4 – 2 * m2 * n2
       b2 = 4 * m2 * n2
       c2 = m4 + n4 + 2* m2 * n2

We can see that a2 + b2 = c2, so instead of
iterating for a, b and c we can iterate for m and n and can generate these triplets. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int countTriangles(int p)
{
    // making a list to store (a, b) pairs
    vector<pair<int,int>> store;
   
    // no triangle if p is odd
    if (p % 2 != 0)
      return 0;
    else
    {
      int count = 1;
   
      for(int b = 1; b < p / 2; b++)
      {
        float a = (float)p / 2.0f * ((float)((float)p - 2.0 * (float)b) / ((float)p - (float)b));
   
        int inta = (int)(a);
   
        if (a == inta)
        {
          // make (a, b) pair in sorted order
          pair<int,int> ab;
   
          if(inta<b)
          {
            ab = {inta, b};
          }
          else
          {
            ab = {b, inta};
          }
   
          // check to avoid duplicates
          if(find(store.begin(), store.end(), ab) == store.end())
          {
            count += 1;
            // store the new pair
            store.push_back(ab);
          }
        }
   
      }
      return count;
    }
}

int main()
{
    int max_sol = 0;
    int max_sol_peri = 0;

    for(int i = 1; i<=1000; i++){
        int possible_right_tri = countTriangles(i);
        if(possible_right_tri > max_sol){
            max_sol = possible_right_tri;
            max_sol_peri = i;
        }
    }

    cout<<max_sol_peri<<endl;

    return 0;
}
