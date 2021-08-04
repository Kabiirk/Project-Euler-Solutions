/*
Problem 17
If the numbers 1 to 5 are written out in words: one, two, three, four, five,then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two)
contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
The use of "and" when writing out numbers is in compliance with British usage.

Answer : 21124
*/

/*
TIPS:
1-20 -> Unique names
20-99 -> [number%10]-ty [numberName(1-9)]
e.g.            Twen-ty  One,
                Thir-ty  Two,
				 Six-ty  Nine

100-999 -> [number%100] hunderd and [numberName(number%100)]
                                    |______________________|
                                              |
                            Done recursively as this part is now essentially either
							numberName(1-20) case or numberName(20-999) case
e.g.                    Four  hundred and Twenty
                       Seven  hundred and Eighty Four

We can see that after 20 names start repeating in a pattern .
Hundreds, Thousands, millions, billions, trillions and quadrillions
all follow a similar pattern, so it can be done recursively.
(As a bonus, this solution scales to higher values as well.)

In the end we add 11 since we have only accounted for 
numbers 1-999 and 1000 (One Thousand) is still left.
It has 11 letters excluding the space.
*/

#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string digitName(int digit);
string teenName(int number);
string tensName(int number);
string intName(int number);

vector<string> ones{"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens{"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tens{"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

string numberName(int number){
	if(number<10){
		return ones[number];
	}
	else if(number < 20){
		return teens[number-10];
	}
	else if(number < 100){
		return tens[number/10] + ( (number%10 != 0) ? " "+numberName(number%10) : "");
	}
	else if(number<1000){
		return numberName(number/100) + " hundred" + ( (number%100 != 0) ? " and "+numberName(number%100) : "" );
	}
	else {
		return "Number greater than 1000 !";
	}
}

string removeSpaces(string s){
    int l = s.length(); // original length
    int c = count(s.begin(), s.end(),' '); // counting the number of whitespaces
 
    remove(s.begin(), s.end(),' '); // removing all the whitespaces
    
    s.resize(l - c); // resizing the string to l-c
    
	return s;
}
 

int main()
{
	int n = 1000;
	int one_thousand_string_length = 11; // One Thousand -> 11 letters excluding the space
	int sum_of_names = 0;
	for(int i=1; i<n; i++){
		string number_name_no_space = removeSpaces(numberName(i));
		sum_of_names += number_name_no_space.length();
	}
	cout<<sum_of_names+one_thousand_string_length<<endl; // Add length of 1000 to get final answer
    
    return 0;
}
