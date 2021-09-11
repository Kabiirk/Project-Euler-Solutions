/*
Problem 49
The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
increases by 3330, is unusual in two ways: (i) each of the three terms
are prime, and, (ii) each of the 4-digit numbers are permutations of one another.

There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
primes, exhibiting this property, but there is one other 4-digit increasing sequence.

What 12-digit number do you form by concatenating the three terms in this sequence?

Answer : 296962999629
*/

/*
TIPS:
Method used :
1) Generate a list of primes below between 1000 and 10000.
2) Take two primes i and j with i < j and calculate k = j + (j-i).
3) Check if k < 10000 and check if k is a prime, if not go to 2.
4) Check if i and j are permutations of each other and check if i and k are permutations of each other. If not go to 2.
5) Found the triple, so exit.

NOTE : Some other useful refferences :

Fast permutation generation :
Ref. : http://www.cplusplus.com/forum/general/44552/

A smart method to check permutations !
Ref. : https://www.mathblog.dk/project-euler-49-arithmetic-sequences-primes-permutations/

Binary search in vectors
Ref. : https://codereview.stackexchange.com/questions/161074/simple-binary-search-in-a-vector

Another ingenious approach of using a number's "Fingerprint":
https://euler.stephan-brumme.com/49/
*/

#include <iostream>
#include <vector>
#include<string> // for string and to_string()

using namespace std;

vector<int> prime_list;

// modified Sieve to poppulate prime_list with all
// primes greater than lower_limit and lesser than n
void sieveOfEratosthenes(int lower_limit, int n)
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
    int size = prime.size();

    for(int j = lower_limit; j<size; j++){
        if(prime[j]){
            prime_list.push_back(j);
        }
    }
}

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

// because vector::find() it O(n) which is too expensive
// checks if k is in prime_list returns true is present
// false otherwise
// recursive binary search
int binarySearch(int left, int right, int k){
    if(right >= left){
        int mid = left+(right-left)/2;

        if(prime_list[mid] == k){
            return true;
        }

        if(prime_list[mid] > k){
            return binarySearch(left, mid-1, k);
        }

        return binarySearch(mid+1, right, k);
    }

    return false;

}

int main()
{
    int limit = 10000;
    sieveOfEratosthenes(1489, limit);
    string result = "";
    int n = prime_list.size();

    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            int k = prime_list[j] + (prime_list[j] - prime_list[i]);
            
            if(k<10000 && binarySearch(0, n, k)){
                if(isPermutation(prime_list[i], prime_list[j]) && isPermutation(prime_list[i], k)){
                    result += to_string(prime_list[i])+to_string(prime_list[j])+to_string(k) ;
                }
                
            }
        }
    }

    cout<<result<<endl;

    return 0;
}
