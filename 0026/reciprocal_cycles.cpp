/*
Problem 26
A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2	= 	0.5
1/3	= 	0.(3)
1/4	= 	0.25
1/5	= 	0.2
1/6	= 	0.1(6)
1/7	= 	0.(142857)
1/8	= 	0.125
1/9	= 	0.(1)
1/10	= 	0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part.

Answer : 983
*/

/*
TIPS:
When does the fractional part repeat?
We look at the part where we have already figured out the integer part,
which is floor(numerator/denominator). Now we are left with ( remainder = numerator%denominator ) / denominator. 
For the process of converting to decimal, at each step we do the following : 

1) Multiply the remainder by 10.
2) Append the remainder/denominator to the result.
3) Remainder = remainder % denominator.

At any moment, if the remainder becomes 0, we are done.
However, when there is a recurring sequence, the remainder never becomes 0.
For example, if you look at 1/3, the remainder never becomes 0.

Below is one important observation : 
If we start with the remainder and if the remainder repeats at any point in time,
the digits between the two occurrences of keep repeating.
So the idea is to store seen remainders in a map. Whenever a remainder repeats,
we return the sequence before the next occurrence.

E.g. :
Say we have to length of repeating pattern calculate for 1/7 we do:
we know 1/7 = 0.(142857)

1/7 = 0 (remainder = 1, multiply by 10 & it becomes our next dividend)
(1*10)/7 = 1 (remainder = 3, multiply like previous step)
(3*10)/7 = 4 (remainder = 2, multiply like previous step)
(2*10)/7 = 2 (remainder = 6)
(6*10)/7 = 8 (remainder = 4)
(4*10)/7 = 5 (remainder = 5)
(5*10)/7 = 7 (remainder = 1)
(7*10)/7 = 10 (remainder = 0) => Since remainder = 0, we stop dividing

what this did was that the remainder provided to us in
each step is a part of the recurring sequence.

another way to look at it is ;
as 1/7 = 0.142857..
10/7 = 1.42857... (remainder ~ 0.42875*7 ~ 3)
30/7 = 4.2857... (remainder ~ 0.2857*7 ~ 2)
and so on ...
*/

#include <iostream>
#include <map> // for map<int, int>
#include <string> // for to_string()

using namespace std;

// returns Length of recurring PATTERN in the DECIMAL component of division
// e.g. fractionToDecimal(1, 6) = 6 since 1/6 = 1.1666666... i.e 6 repeats
int repeatPatternLength(int numerator, int denominator){
	string result;
	
	map<int, int> pattern;
	pattern.clear();
	
	int remainder = numerator%denominator;
	
	// Keep finding remainder until either remainder
    // becomes 0 or repeats
	while( (remainder != 0) && (pattern.find(remainder) == pattern.end()) ){
		// Store this remainder in map
		pattern[remainder] = result.length();
		remainder = remainder*10;
		
		// Append remainder / denominator to result
		int result_part = remainder/denominator;
		result += to_string(result_part);
		
		// Update remainder
		remainder = remainder%denominator;
	}
	
	if(remainder == 0){
		return 0;
	}
	else{
		return result.substr(pattern[remainder]).length();
	}
}

int main()
{
	int max_reciprocal[2]  = {0, 0}; // {denominator, repeat_pattern_length}
	int limit = 1000;
	
	for(int i = 1; i<=limit; i++){
		// numerator = 1; 
		// denominator = i
		int repeat_pattern_len = repeatPatternLength(1,i);
		if( repeat_pattern_len > max_reciprocal[1] ){
			max_reciprocal[0] = i;
			max_reciprocal[1] = repeat_pattern_len;
		}
	}
	
	
    cout<< "Number : " <<max_reciprocal[0] <<endl;
    cout<< "Repeating Pattern Length : " <<max_reciprocal[1] <<endl;
    
    return 0;
}
