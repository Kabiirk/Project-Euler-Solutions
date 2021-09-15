/*
Problem 50
The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime
below one-hundred.

The longest sum of consecutive primes below one-thousand that adds
to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the
most consecutive primes?

Answer : 997651 (543 terms)
*/

/*
TIPS:
Brute Force iteration by using something similar to sliding window.

CAUTION : 
(This caused me some headache, apart from figuring out how to iterate)
The problem asks for sums of CONSECUTIVE primes, which need not necessarily
begin with the first prime. The fact that the shown example :

41 = 2 + 3 + 5 + 7 + 11 + 13 

starts with the first prime is incidental
(although it is no accident that the winning sequence starts with at a small prime).

953 =  7 + 11 + 13 + 17 + 19 + 23 + 29 
    + 31 + 37 + 41 + 43 + 47 + 53 + 59 
    + 61 + 67 + 71 + 73 + 79 + 83 + 89

That's 21 terms. There is no mistake in the problem description - the term 'FIRST' does not appear anywhere in the text.
Ref. : https://stackoverflow.com/questions/36854818/project-euler-50-prime-sums-not-correct

Some other approaches:
https://www.mathblog.dk/project-euler-50-sum-consecutive-primes/
https://radiusofcircle.blogspot.com/2016/06/problem-50-project-euler-solution-with-python.html
https://euler.stephan-brumme.com/50/
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> prime_num;

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

    for(int j = 2; j<=n; j++){
        if(prime[j]){
            prime_num.push_back(j);
        }
    }

    return prime;
}


int main(){
  int limit = 1000000;
  vector<bool> prime_bool = sieveOfEratosthenes(limit);

  int sum, num_terms = 1;
  for ( int i = 0; i + num_terms <= prime_num.size(); i++ ) {
    int j = i + 2;
    int s = prime_num[i] + prime_num[j - 1] + prime_num[j];

    if (i == 0){
      s -= prime_num[j--];
    }

    while ( s < limit && j < prime_num.size() ) {
      int l = j - i + 1;
      if (l > num_terms && prime_bool[s]) {
        num_terms = l;
        sum = s;
      }
      j += 2;
      s += prime_num[ j - 1 ] + prime_num[ j ];
    }
  }
  cout << sum << endl;//" " << num_terms << endl;

  return 0;
}


/*

 __   __          
 \ \ / /_ _ _   _ 
  \ V / _` | | | |
   | | (_| | |_| |
   |_|\__,_|\__, |
            |___/ 

  _____ _          _     ____   ___    ____        _               _   _   _ 
 |  ___(_)_ __ ___| |_  | ___| / _ \  / ___|  ___ | |_   _____  __| | | | | |
 | |_  | | '__/ __| __| |___ \| | | | \___ \ / _ \| \ \ / / _ \/ _` | | | | |
 |  _| | | |  \__ \ |_   ___) | |_| |  ___) | (_) | |\ V /  __/ (_| | |_| |_|
 |_|   |_|_|  |___/\__| |____/ \___/  |____/ \___/|_| \_/ \___|\__,_| (_) (_)

*/