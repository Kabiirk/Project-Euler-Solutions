/*
Problem 15
Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.



How many such routes are there through a 20×20 grid?

Answer : 137846528820
*/

/*
TIPS:
This can be solved using combinatronics
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int gridSize = 20;
	long long int paths = 1;
 
	for (int i = 0; i < gridSize; i++) {
		paths *= ((2 * gridSize) - i);
    	paths /= (i + 1);
	}
	cout<<paths<<endl;
    
    return 0;
}
