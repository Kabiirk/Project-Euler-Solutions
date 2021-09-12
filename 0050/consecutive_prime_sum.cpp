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

Answer : 
*/

/*
TIPS:

*/

#include <iostream>
#include <vector>

using namespace std;

typedef unsigned long long ULL;

vector<int> prime_list;

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
            prime_list.push_back(j);
        }
    }

    return prime;
}

void printVector(vector<int> n){
    int sz = n.size();
    for(int j = 0; j<prime_list.size(); j++){
        cout<<prime_list[j]<<" ";
    }
}

int main()
{
    //cout<<"Hello Euler !!"<<endl;
    vector<bool> prime_bool = sieveOfEratosthenes(1000000);
    int n = prime_list.size();
    int sum = 0;
    int i = 0;
    int result;

    while(sum < 100000){
        //cout<<sum<<" + "<<prime_list[i]<<" ("<<i<<") "<<endl;
        sum+=prime_list[i];
        i++;
        if(prime_bool[sum]){
            result = sum;
        }
    }

    //printVector(prime_list);
    cout<<result<<endl;
    
    return 0;
}
