/*
Problem 52
It can be seen that the number, 125874, and its double, 251748,
contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
contain the same digits.

Answer : 142857
*/

/*
TIPS:
For 1-limit, we check whether a num(i) & it's multiples (2i, 3i, 4i, 5i & 6i)
have the same number of digits. For numbers that satisfy this condition,
we then check if they have the same digits as their multiples (2i, 3i, 4i, 5i & 6i). 

NOTE : Check for same length i.e. same number of digits done to eliminate those
numbers whose multiples aren't the same length and only check valid numbers & their multiples
*/

#include <iostream>
#include <cmath>

using namespace std;

bool haveSameDigit(int a, int b){
    return floor(log10(a)+1) == floor(log10(b)+1);
}

// isPermutation from problem 49
bool isPermutation(int a, int b){
    int arr[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; // index is important

    int temp1 = b;
    while(temp1>0){
        arr[temp1%10]++; // increment that index value by +1
        temp1 /= 10;
    }

    int temp2 = a;
    while(temp2>0){
        arr[temp2%10]--; // decrement that index value by +1
        temp2 /= 10;
    }

    for(int i = 0; i<10; i++){
        if(arr[i] != 0){
            return false;
        }
    }

    return true;
}

int main()
{
    int limit = 200000; // based on assumptions
    for(int i = 10; i<limit; i++){
        // Made sure all multiples have same digit before checking for permutations
        // to reduce the numbers it has to check as permutations
        if(haveSameDigit(i, 2*i) && haveSameDigit(i, 3*i) && haveSameDigit(i, 4*i) && haveSameDigit(i, 5*i) && haveSameDigit(i, 6*i)){
            if(isPermutation(i, 2*i) && isPermutation(i, 3*i) && isPermutation(i, 4*i) && isPermutation(i, 5*i) && isPermutation(i, 6*i)){
                cout<<i<<endl;
            }
        }
    }
    return 0;
}
