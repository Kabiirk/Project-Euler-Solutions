/*
Problem 55
If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers,
like 196, never produce a palindrome. A number that never forms a
palindrome through the reverse and add process is called a Lychrel
number. Due to the theoretical nature of these numbers, and for the
purpose of this problem, we shall assume that a number is Lychrel
until proven otherwise. In addition you are given that for every
number below ten-thousand, it will either (i) become a palindrome
in less than fifty iterations, or, (ii) no one, with all the computing
power that exists, has managed so far to map it to a palindrome.

In fact, 10677 is the first number to be shown to require over fifty
iterations before producing a palindrome: 4668731596684224866951378664 (53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves
Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

NOTE: Wording was modified slightly on 24 April 2007 to emphasise the
theoretical nature of Lychrel numbers.

Answer : 249
*/

/*
TIPS:
Straightforward approach :
helper functions are
reverse() -> Reverse a given number
isPalindrome() -> check if number is palindrome

In isLychrel(), as per instructions in the question, we assume
each number is a Lychrel number(i.e. doesn't produce a palindrome
after reversal & Addition) until it's Palindrome is found
before 50 iterations (done with reverse() & isPalindrome()) .


Alternate approaches :
Using vectors to handle BigIntegers in C++
Ref.: https://euler.stephan-brumme.com/55/
(While this is good, using unsigned long long int worked for me)

Leveraging Caching:
Ref.: https://www.mathblog.dk/project-euler-55-how-many-lychrel-numbers-are-there-below-ten-thousand/
*/

#include <iostream>

using namespace std;

typedef unsigned long long int ULLI;

ULLI reverse(ULLI n){
    ULLI a=0, t=n, temp;
    while(t){
        temp = t%10;
        a = a*10 + temp;
        t = t/10;
    }
    return a;
}

bool isPalindrome(ULLI n){
    return reverse(n) == n;
}

// As per isLychrel(), a number is NOT a Lychrel Number
// if, after reversal and addition, it is able
// to produce a Palindrome Sum within 50 iterations.
// (As nstructed in the question)
bool isLychrel(ULLI n){
    ULLI k = n;
    // 50 iterations
    for(int i=0; i<50; i++){
        k+=reverse(k);
        if(isPalindrome(k)){
            return false;
        }
    }
    return true;
}

int main() {
    ULLI i, res=0;
    ULLI limit = 10000;
    for(i = 1; i<limit; i++){
        if(isLychrel(i)){
            res++;
        }
    }

    cout<<res<<endl;

    return 0;
}
