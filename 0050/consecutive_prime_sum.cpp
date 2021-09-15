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

bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
  
    // Check from 2 to n-1
    for (int i = 2; i < n; i++)
        if (n % i == 0)
            return false;
  
    return true;
}

vector<int> slidingWindow(int lmt, vector<bool> prime_bool){
  vector<int> sum_window;
  int i = 0;
  int sum;
  int i_offset = 0;
  bool keep_going = true;

  while(keep_going){
    sum = 0;
    while(sum<lmt){
      i = i_offset;
      sum+=prime_num[i];
      i++;
    }
    cout<<sum<<" "<<i<<endl;
    i_offset++;
  }

  return sum_window;
}


int main(){
  int limit = 1000;
  vector<bool> prime_bool = sieveOfEratosthenes(limit);
  int n = prime_num.size();
  vector<int> sum_window = slidingWindow(100, prime_bool);

  // for(int i = 0; i<sum_window.size();i++){
  //   cout<<sum_window[i]<<endl;
  // }
  
  
}
