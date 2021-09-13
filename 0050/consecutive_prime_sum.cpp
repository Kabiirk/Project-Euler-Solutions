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
  int n = prime_num.size();
  vector<long long> prime_sum(n, 0);

  int max_run = 0;
  prime_sum[0] = 0;
  for(int i = 1; i<n; i++){
    prime_sum[i] = prime_sum[i-1] + prime_num[i-1];
    if(prime_sum[i]>limit){
      max_run = i-1;
    }
  }

  for(int j = max_run; j>0; j--){
    for(int k = 0;;k++){
      long long next = prime_sum[k+j] - prime_sum[k];

      if(next > limit){
        break;
      }

      if(next%2 && !prime_bool[(next-1)/2]){
        cout<<next<<endl;
        return 0;
      }
    }
  }
}
