/*
Problem 19
You are given the following information, but you may prefer to do some research for yourself.

1 Jan 1900 was a Monday.
Thirty days has September,
April, June and November.
All the rest have thirty-one,
Saving February alone,
Which has twenty-eight, rain or shine.
And on leap years, twenty-nine.

A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

Answer : 171
*/

/*
TIPS:
say day 1 -> monday
day 2 -> tuesday
day 7 -> sunday
day 8 -> monday
day 9 -> tuesday
.
.
day 14 -> sunday
.
.
day 21 -> sunday
day 28 -> day 35 (feb 4) -> Sunday

From this, we notice that when cummulative day count is divisible by 7
that day is a sunday, so we start from day 2 since 1 Jan 1901 was a tuesday
and start adding days by the month (taking leap years etc. into consideration)
i.e. 2 + 28(or 29) + 31 + 30 ... and checking if sum is divisible by 7 therefore
the series looks like this for us :
day 2 -> Tuesday (Jan 1 1901)
day 2 + 31 (Jan) = 33 -> Friday (Feb 1 1901)
day 33 + 28(Feb) = 61 -> Friday (Mar 1 1901)
day 61 + 31(Mar) = 92 -> Monday (Apr 1 1901)
day 92 + 30(Apr) = 122 -> Wednesday (May 1 1901)
day 122 + 31(May) = 153 -> Saturday (Jun 1 1901)
day 153 + 30(Jun) = 183 -> Monday (Jul 1 1901)
day 183 + 31(Jul) = 214 -> Thursday (Aug 1 1901)
day 214 + 31(Aug) = 245 -> Sunday (Sep 1 1901) (also 245 % 7 == 0)
day 245 + 30(Sep) = 275 -> Tuesday (Oct 1 1901)
day 275 + 31(Oct) = 306 -> Friday (Nov 1 1901)
day 306 + 30(Nov) = 336 -> Sunday (Dec 1 1901) (also 336 % 7 == 0)
day 336 + 31(Dev) = 367 -> Wednesday (Jan 1 1902)

The idea behind adding days by the month is we dont check day for each date
rather jump straight to the 1st of each month and divide by 7 to
figure out wether it's a sunday or not.

Alternate approaches -> 
1) Brute Force : https://en.wikipedia.org/wiki/Determination_of_the_day_of_the_week
2) Zeller's Congruence : https://en.wikipedia.org/wiki/Zeller%27s_congruence
*/

#include <iostream>

using namespace std;

int main()
{
	int month[12] = {31,0,31,30,31,30,31,31,30,31,30,31};
	int day = 2; // 1 Jan 1901 is a Tuesday
	int sunday_count = 0;
	
	for(int i=1901; i<=2000; i++){
		if(i%4==0){
			month[1] = 29;
		}
		else{
			month[1] = 28;
		}
		for(int j=0; j<12; j++){
			if(day%7==0){
				sunday_count++;
			}
			day+=month[j];
		}
	}
	cout<<sunday_count<<endl;
    
    return 0;
}
