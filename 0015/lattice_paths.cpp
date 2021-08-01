/*
Problem 15
Starting in the top left corner of a 2x2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

O--->O--->O    O--->O----O    O--->O----O
|    |    |    |    |    |    |    |    |
|    |    v    |    v    |    |    v    |
O----O----O    O----O--->O    O----O----O
|    |    |    |    |    |    |    |    |
|    |    v    |    |    v    |    v    |
O----O----O    O----O----O    O----O--->O


O----O----O    O----O----O    O----O----O
|    |    |    |    |    |    |    |    |
v    |    |    v    |    |    v    |    |
O--->O--->O    O--->O----O    O----O----O
|    |    |    |    |    |    |    |    |
|    |    v    |    v    |    v    |    |
O----O----O    O----O--->O    O--->O--->O

How many such routes are there through a 20x20 grid?

Answer : 137846528820
*/

/*
TIPS:
1) Dynamic Programming (Easier approach, sort-of brute force)

2) Combinatronics :
This problem can be easily solved with comninatronics.
In order to pose the question as a combinatorics question,
we must realise a few things. I have generalised the observations
to an NxN grid.

All paths can be described as a series of directions. And since
we can only go down and right, we could describe the paths as a
series of Ds and Rs. In a 2×2 grid all paths are : 
1) DDRR
2) DRDR
3) DRRD
4) RDRD
5) RDDR
6) RRDD.

Based on the example we can see that all paths have exactly size 2N
of which there are N Rs and N Ds.

If we have 2N empty spaces and place all Rs, then the placement of
the Ds are given
Once we have made these realisations, we can repose the question as:
"In how many ways can we choose N out of 2N possible places if the order does not matter?"

And combinatorics gives us an easy answer to that. The Binomial Coefficient gives us
exactly the tool we need to answer the above question. The question is usually posed as

combinations of 'k' in 'n' = ((2n)Cn) = (nCk) , which can be expanded as :
     n!
-----------
 k!*(n-k)!
 
which can be further written as :
 n*(n-1)*(n-2)...(n-k+1)
------------------------
   k*(k-1)*(k-2)...1

This solution has a smaller implementation and will be significantly smaller
in memory usage than the first approach. However both works really fast.
*/

#include <bits/stdc++.h>
using namespace std;

long long int Dynamic(int grid_size){
	long long int grid[grid_size+1][grid_size+1] ;
 
	//Initialise the grid with boundary conditions
	for (int i = 0; i < grid_size; i++) { 
    	grid[i][grid_size] = 1;
		grid[grid_size][i] = 1; 
	}
 
	for (int i = grid_size - 1; i >= 0; i--) {
    	for (int j = grid_size - 1; j >= 0; j--) {
        	grid[i][j] = grid[i+1][j] + grid[i][j+1];
    	}
	}
	
	return grid[0][0];
}

long long int Combinatronics(int grid_size){
	long long int paths = 1;
 
	for (int i = 0; i < grid_size; i++) {
		paths *= ((2 * grid_size) - i);
    	paths /= (i + 1);
	}
	return paths;
}


int main()
{
	int grid_size = 20;
	cout<<"Using Dynamic Programming : "<<Dynamic(grid_size)<<endl;
	cout<<"Using Combinatronics : "<<Combinatronics(grid_size)<<endl;
	
    return 0;
}
