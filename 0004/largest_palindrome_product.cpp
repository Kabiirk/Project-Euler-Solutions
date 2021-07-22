/*
Problem 4
A palindromic number reads the same both ways. The largest palindrome made
from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.

Answer : 906609
*/

/*
TIPS:
100 = Lowest number
999 = highest number

100*100 = 10000 (5 digits)
999*999 = 998001 (6 digits)
*/

#include <bits/stdc++.h>
using namespace std;



int larrgestPalindrome(int n)
{
    int upper_limit = pow(10,n) - 1;

    // largest number of n-1 digit.
    // One plus this number is lower
    // limit which is product of two numbers.
    int lower_limit = 1 + upper_limit / 10;

    // Initialize result
    int max_product = 0;
    for (int i = upper_limit; i >= lower_limit; i--)
    {
        for (int j = i; j >= lower_limit; j--)
        {
            // calculating product of
            // two n-digit numbers
            int product = i * j;
            if (product < max_product)
                break;
            int number = product;
            int reverse = 0;
 
            // calculating reverse of
            // product to check whether
            // it is palindrome or not
            while (number != 0)
            {
                reverse = reverse * 10 + number % 10;
                number /= 10;
            }
 
            // update new product if exist
            // and if greater than previous one
            if (product == reverse && product > max_product){
            	max_product = product;
			}
        }
    }
    return max_product;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n = 3;
    cout << larrgestPalindrome(n);
    return 0;
    
    
    return 0;
}
