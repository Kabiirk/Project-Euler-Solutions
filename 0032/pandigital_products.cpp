/*
Problem 32
We shall say that an n-digit number is pandigital if it makes use
of all the digits 1 to n exactly once; for example, the 5-digit
number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254,
containing multiplicand, multiplier, and product is 1 through 9
pandigital.

Find the sum of all products whose multiplicand/multiplier/product
identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to
only include it once in your sum.

Answer : 45228
*/

/*
TIPS:
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int main()
{
  unsigned int maxDigit=9;

  std::vector<unsigned int> digits = { 1,2,3,4,5,6,7,8,9 };
  // remove higher numbers so there is only 1..n left
  digits.resize(maxDigit);

  // all pandigital products
  std::set<unsigned int> valid;

  // create all permutations
  do
  {
    for (unsigned int lenA = 1; lenA < maxDigit; lenA++)
      for (unsigned int lenB = 1; lenB < maxDigit - lenA; lenB++)
      {
        unsigned int lenC = maxDigit - lenA - lenB;

        if (lenC < lenA || lenC < lenB)
          break;

        unsigned int pos = 0;

        unsigned int a = 0;
        for (unsigned int i = 1; i <= lenA; i++)
        {
          a *= 10;
          a += digits[pos++];
        }

        unsigned int b = 0;
        for (unsigned int i = 1; i <= lenB; i++)
        {
          b *= 10;
          b += digits[pos++];
        }

        unsigned int c = 0;
        for (unsigned int i = 1; i <= lenC; i++)
        {
          c *= 10;
          c += digits[pos++];
        }

        if (a*b == c)
          valid.insert(c);
      }
  } while (std::next_permutation(digits.begin(), digits.end()));

  // find sum
  unsigned int sum = 0;
  for (auto x : valid)
    sum += x;
  std::cout << sum << std::endl;

  return 0;
}
