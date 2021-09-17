/*
Problem 51
By replacing the 1st digit of the 2-digit number *3,
it turns out that six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all prime.

By replacing the 3rd and 4th digits of 56**3 with
the same digit, this 5-digit number is the first
example having seven primes among the ten generated
numbers, yielding the family: 56003, 56113, 56333, 56443, 56663, 56773, and 56993.
Consequently 56003, being the first member of this family, 
is the smallest prime with this property.

Find the smallest prime which, by replacing part of
the number (not necessarily adjacent digits) with
the same digit, is part of an eight prime value family.

Answer : 121313
*/

/*
TIPS:
*/

#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

vector<int> prime_num;
unsigned int max_digits = 7;
unsigned int to_replace = 3;
unsigned int num_siblings = 7;
unsigned int smallest_prime = 99999999;
map<string, vector<unsigned int>> matches;
// matches = {
//    regular_expression : < primes matching that expression >
// }

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

    for(int j = 2; j<=n; j++)
    {
        if(prime[j])
        {
            prime_num.push_back(j);
        }
    }

    return prime;
}

void match_pattern(unsigned int num, string regex, unsigned int digit, unsigned int freq, unsigned int begin=0){
    char ascii_digit = digit + '0';

    for(unsigned int i = begin; i<max_digits; i++)
    {
        if(regex[i] != ascii_digit)
        {
            continue;
        }

        if(i == 0 && ascii_digit == '0')
        {
            continue;
        }

        regex[i] = '.';

        if(freq == 1)
        {
            auto& add_to = matches[regex];
            add_to.push_back(num);
            if(add_to.size() >= num_siblings && add_to.front() < smallest_prime){
                smallest_prime = add_to.front();
            }
        }
        else
        {
            match_pattern(num, regex, digit, freq-1, i+1);
        }

        regex[i] = ascii_digit;
    }
}

int main()
{
    unsigned int min_num = 1;

    for(unsigned int i = 1; i<max_digits; i++)
    {
        min_num *= 10;
    }

    unsigned int max_num = min_num*10 - 1;

    vector<bool> prime_bool = sieveOfEratosthenes(max_num);

    // regex creation
    for(unsigned int i = min_num; i<=max_num; i++)
    {
        if(prime_bool[i])
        {
            string str_num = to_string(i);

            for(unsigned int digit = 0; digit <= 9; digit++)
            {
                match_pattern(i, str_num, digit, to_replace);
            }

            if(max_digits == 7)
            {
                if(to_replace == 1 && i>2000000)
                {
                    break;
                }
                if(to_replace == 2 && i>3000000)
                {
                    break;
                }
            }
        }
    }

    string min;
    for(auto m : matches)
    {
        if(m.second.size() < num_siblings)
        {
            continue;
        }
        if(m.second.front() != smallest_prime)
        {
            continue;
        }

        string concat_string;
        for(unsigned i = 0; i<num_siblings; i++){
            concat_string+= to_string(m.second[i]) + " ";
        }

        if(min > concat_string || min.empty()){
            min = concat_string;
        }
    }
    
    cout<<min<<endl;

    return 0;
}
