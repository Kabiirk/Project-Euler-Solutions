/*
Problem 58
Starting with 1 and spiralling anticlockwise in the following way,
a square spiral with side length 7 is formed.

[37] 36  35  34  33  32 [31]
38 [17] 16  15  14 [13] 30
39  18  [5]  4  [3]  12  29
40  19   6   1   2  11  28
41  20  [7]  8   9  10  27
42  21  22  23  24  25  26
[43]  44  45  46  47  48  49

It is interesting to note that the odd squares lie along the bottom
right diagonal, but what is more interesting is that 8 out of the 13
numbers lying along both diagonals are prime; that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square
spiral with side length 9 will be formed. If this process is continued,
what is the side length of the square spiral for which the ratio of
primes along both diagonals first falls below 10%?

Answer : 
*/

/*
TIPS:
we consider diagonals originating from the center of sprial (i.e. from 1) 
and going towards the corner :
1 -> Top-Right corner (top_right)
1 -> Top-Left corner (top_left)
1 -> Bottom-Left corner (bottom_left)
1 -> Bottom-Right corner (bottom_right)

As depicted below :
    ▲           ▲
    └┐         ┌┘
    .└┐       ┌┘.
    37└┐     ┌┘31
     17└┐   ┌┘13
       5└┬─┬┘3
         │1│
       7┌┴─┴┐9
     21┌┘   └┐25
    43┌┘     └┐49
    .┌┘       └┐.
    ┌┘         └┐
    ▼           ▼

    The number-series in each of these diagonals can be written as
Top-Right:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│2│                             = 3
          └─┘
              ┌─────┐
n = 2; 1 + 2 +│2 + 8│                     = 13
              └─────┘
                      ┌─────────┐
n = 3; 1 + 2 + 2 + 8 +│2 + 8 + 8│         = 31
                      └─────────┘

Top-Left:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│4│                             = 5
          └─┘
              ┌─────┐
n = 2; 1 + 4 +│4 + 8│                     = 17
              └─────┘
                      ┌─────────┐
n = 3; 1 + 4 + 4 + 8 +│4 + 8 + 8│         = 37
                      └─────────┘

Bottom-Left:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│6│                             = 7
          └─┘
              ┌─────┐
n = 2; 1 + 6 +│6 + 8│                     = 21
              └─────┘
                      ┌─────────┐
n = 3; 1 + 6 + 6 + 8 +│6 + 8 + 8│         = 43
                      └─────────┘

Bottom-Right:
n = 0; 1                                  = 1

          ┌─┐
n = 1; 1 +│8│                             = 9
          └─┘
              ┌─────┐
n = 2; 1 + 8 +│8 + 8│                     = 25
              └─────┘
                      ┌─────────┐
n = 3; 1 + 8 + 8 + 8 +│8 + 8 + 8│         = 49
                      └─────────┘

Therefore, from the given series we observe
the general forumula for nth term of the half-diagonals
can be written as :
                ┌────────────────────┐
n = n; 1 + ... +│inner_diff + (n-1)*8│
                └────────────────────┘
where inner_diff = inner difference of the 1st spiral after 1
i.e. 
inner_diff(Top-Right) = 9-1 = 8
inner_diff(Top-Left) = 7-1 = 6
inner_diff(Bottom-Left) = 5-1 = 4
inner_diff(Bottom-Right) = 3-1 = 2

Based on the above formula, we write a common function halfDiagonalElement()
to calculate sum of terms in a half-diagonal
*/

#include <iostream>
#include <vector>

using namespace std;

vector<bool> sieveOfEratosthenes(int n)
{
    vector<bool> prime(n, true);
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    return prime;
}

unsigned int halfDiagonalElement(int first_term, int inner_diff, int limit, vector<bool> prime_list){
    int n_term = first_term;
    int num_primes = 0;

    for(int n=1; n<=limit; n++){ //-2 because we are excluding 1 in the beginning
        n_term += inner_diff+(8*(n-1));
        num_primes += (int)prime_list[n_term];
        //cout<<n_term<<" "<<prime_list[n_term]<<endl;
    }
    return num_primes;
}

int main() {
    // cout<<"Hello Euler !!"<<endl;

    vector<bool> prime_list = sieveOfEratosthenes(1000000);

    // cout<<"bottom_right"<<endl;
    // unsigned int bottom_right = halfDiagonalElement(1, 8, 3, prime_list);
    // cout<<"bottom_left"<<endl;
    // unsigned int bottom_left = halfDiagonalElement(1, 6, 3, prime_list);
    // cout<<"top_left"<<endl;
    // unsigned int top_left = halfDiagonalElement(1, 4, 3, prime_list);
    // cout<<"top_right"<<endl;
    // unsigned int top_right = halfDiagonalElement(1, 2, 3, prime_list);

    double percentage_primes = 100.0;
    int ring = 2;
    while(percentage_primes > 10.0){
        unsigned int br_primes = halfDiagonalElement(1, 8, ring, prime_list); // bottom right
        unsigned int bl_primes = halfDiagonalElement(1, 6, ring, prime_list); // bottom left
        unsigned int tl_primes = halfDiagonalElement(1, 4, ring, prime_list); // top left
        unsigned int tr_primes = halfDiagonalElement(1, 2, ring, prime_list); // top right
        int diag_prime_sum = br_primes+bl_primes+tl_primes+tr_primes;
        int all_elements_along_diagonal = 1 + 4*ring;
        percentage_primes = (diag_prime_sum/all_elements_along_diagonal)*100.0;
        ring++;
    }

    cout<<2*ring+1<<endl;

    return 0;
}
