/*
Problem 36
The decimal number, 585 = 10010010012 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

Answer : 872187
*/

/*
TIPS:
Standard approaches for reversing integer, converting
decimal number to binary & checking for binary palindrome.

To save time, we are only checking
binary palindromes for those numbers which
are decimal palindromes only.
*/

#include <iostream>
#include<string>
#include <algorithm> // for reverse

using namespace std;

// Iterative function to reverse digits of num
int reverseDigits(int num)
{
    int rev_num = 0;
    while (num > 0) {
        rev_num = rev_num * 10 + num % 10;
        num = num / 10;
    }
    return rev_num;
}

// convert decimal to binary string
string decToBinString(int n){
    string binary = "";
    while(n>0){
        int bit = n%2;
        n = n/2;
        binary = to_string(bit)+binary;
    }
    return binary;
}

bool isDigitPalindrome(int n){
    if(n%10 == 0){
        return false;
    }
    return n==reverseDigits(n);
}

bool isBinaryPalindrome(int n){
    string binary = decToBinString(n);
    string binary_reverse = binary;
    reverse(binary_reverse.begin(), binary_reverse.end());

    return binary == binary_reverse;
}

int main()
{
    int limit = 1000000;
    unsigned long long int double_base_palindrome_count = 0; // could be large

    for(int i = 0; i<limit; i++){
        if(isDigitPalindrome(i)){
            if(isBinaryPalindrome(i)){
                double_base_palindrome_count += i;
            }
        }
    }

    cout<<double_base_palindrome_count<<endl;

    return 0;
}