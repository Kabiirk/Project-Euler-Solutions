/*
Problem 62
The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3).
In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.

Answer : 127035954683
(Which is a cube of : 5027)
*/

#include <map>
#include <set>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

uint64_t fingerprint(uint64_t x)
{
    uint64_t result = 0;
    while (x > 0)
    {
        // extract lowest digit
        auto digit = x % 10;
        x /= 10;

        // subdivide 64 bit integer into 10 "digit counters", each 6 bits wide
        // => each digit may occur up to 2^6=64 times, more than enough ...
        const auto BitsPerDigit = 6;
        result += 1ULL << (BitsPerDigit * digit);
    }
    return result;
}

int main(){
    unsigned int maxCube = 10000;
    unsigned int numPermutations = 5;
  
    // [fingerprint] : < list of numbers, where number^3 produced that fingerprint >
    map<uint64_t, vector<unsigned int>> matches;
    // 22^3 = 10648, smallest 5 digit cube
    for (unsigned int i = 1; i < maxCube; i++){
        auto cube = (uint64_t)i * i * i;
        matches[fingerprint(cube)].push_back(i);
    }
  
    // extract all smallest cube, set is sorting them
    set<uint64_t> smallest;
    for (auto m : matches){
        // right number of permutations ?
        if (m.second.size() == numPermutations){
            smallest.insert(m.second.front());
        }
    }

    uint64_t s = *smallest.begin();
    cout<<s*s*s<<endl;
    cout<<"Which is a cube of : "<<s<<endl;

    return 0;
}