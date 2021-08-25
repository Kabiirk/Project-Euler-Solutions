/*
Problem 34
145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: As 1! = 1 and 2! = 2 are not sums they are not included.

Answer : 40730
*/

/*
TIPS:
1) Brute force:
   Iterate throught possible solution space
   while calculating sum of factorial of digits
   and see if they match with their parent number.
*/

#include <iostream>

// to save from writing long data type
typedef unsigned long int ULI;

using namespace std;

ULI factorial(ULI n)
{
    ULI res = 1, i;
    for (ULI i = 2; i <= n; i++)
        res *= i;
    return res;
}


int main()
{
    // pre-caching factorials
    ULI facts[10];
    ULI result = 0;
    for(int i = 0; i<10; i++){
        facts[i] = factorial(i);
    }

    for(ULI i = 10; i<2540161; i++){
        ULI digit_factorial_sum =  0;
        ULI num = i;
        while(num>0){
            ULI digit = num%10;
            num = num/10;
            digit_factorial_sum += facts[digit];
        }

        if(digit_factorial_sum == i){
            result += i;
        }
    }

    cout<<result<<endl;

    return 0;
}
