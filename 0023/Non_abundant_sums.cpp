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
trick here is we already know that all numbers above 28123
can be written as a sum of two abundant numbers and we
also know that the list is sorted ascendantly.
So as soon as we reach a sum which is above 28123,
we can break out of the inner loop.

After generating a list of all abundant primes, we iterate through
the list twice to find which the numbers we require and add them.

Note : A better sumOfDivisors in problem 23 but I used the
simpler one as it was easy to understand and fast enough for now.
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int sumOfDivisors(int num)
{
    int result = 0;
    if(num == 1)
      return result;

    for (int i=2; i<=sqrt(num); i++)
    {
        if (num%i==0)
        {
            if (i==(num/i))
                result += i;
            else
                result += (i + num/i);
        }
    }
 
    // Add 1 to the result as 1 is also a divisor
    return (result + 1);
}

int main(){
    const int limit = 28123;
    vector<int> abundant;
    bool are_abundant[limit+1];
    fill_n(are_abundant, limit+1, false); // set every value for array as false

    // Find all abundant numbers
    for(int i = 2; i<=limit; i++){
        if(sumOfDivisors(i) > i){
            abundant.push_back(i);
        }
    }

    // Make all the sums of two abundant numbers
    for(int i=0; i<abundant.size(); i++){
        for(int j = i; j<abundant.size(); j++){
            if(abundant[i] + abundant[j] <= limit){
                are_abundant[abundant[i] + abundant[j]] = true;
            }
            else{
                break;
            }
        }
    }

    // final sum
    long sum = 0;
    for(int k = 1; k<=limit; k++){
        if(!are_abundant[k]){
            sum+=k;
        }
    }

    cout<<sum<<endl;

    return 0;
}
