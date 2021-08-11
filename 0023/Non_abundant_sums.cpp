/*
Problem 23
A perfect number is a number for which the sum of its proper divisors is exactly equal to the number.
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16,
the smallest number that can be written as the sum of two abundant numbers is 24.
By mathematical analysis, it can be shown that all integers greater than 28123 can be written as the sum of two abundant numbers.
However, this upper limit cannot be reduced any further by analysis even though it is known that the greatest number that cannot
be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers.

Answer : 4179871
*/

/*
TIPS:

*/

#include <array>
#include <iostream>
#include <vector>

long sum_of_dividends(int n)
{
    long sum{1};
    int i = 2;
    for (int j = n; i < j; ++i)
    {
        if ( n % i == 0 )
        {
            sum += i;
            j = n / i;
            if (i == j)
               break;
            sum += j;
        }
    }
    return sum;
}

int main() 
{
    std::vector<int> abundants;
    abundants.reserve(7000);
    constexpr int max_value = 28123;
    for (int i{1}; i <= max_value; ++i)
    {
        if (sum_of_dividends(i) > i)
            abundants.push_back(i);
    }

    std::array<bool, max_value> are_sums{};

    for (unsigned i{}; i < abundants.size(); ++i)
    {
        for (unsigned j{i}; ; ++j)
        {
            long k = abundants[i] + abundants[j];
            if (k >= max_value)
                break;
            are_sums[k] = true;
        } 
    }
    long sum{};
    for (int i{}; i < max_value; ++i)
        if (!are_sums[i])
            sum += i;

    std::cout << sum << '\n';
}
