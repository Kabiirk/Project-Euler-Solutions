/*
Problem 31
In the United Kingdom the currency is made up of pound (£) and pence (p).
There are eight coins in general circulation:

1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
It is possible to make £2 in the following way:

1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p
How many different ways can £2 be made using any number of coins?

Answer : 73682
*/

/*
TIPS:
Using dynamic programming, calculate all possible coin
combinations to add upto the given value (£2 taken as 200p
for ease of calculation)
*/

#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

int coinCombos(int coins[], int len, int amount){
    //int table[amount+1];
    // The code runs fine even with this line,
    // but VS Code gives this warning : 
    // expression must have a constant value
    // -- the value of parameter "amount" (declared at line 28)
    // cannot be used as a constant
    // Possible "solutions" : https://stackoverflow.com/questions/9219712/c-array-expression-must-have-a-constant-value

    int table[200+1];
    // amount is 200p i.e. £2 which is
    // required as per question,
    // change this variable to find
    // solutions for different amounts
    memset(table, 0, sizeof(table));
    table[0] = 1;
    for(int i = 0; i<len; i++){
        for(int j = coins[i]; j<=amount; j++){
            table[j] += table[j-coins[i]];
        }
    }

    return table[amount];
}

int main()
{
    int coins[8] = {1,2,5,10,20,50,100,200};
    int len = sizeof(coins)/sizeof(coins[0]);
    int amount = 200;
    cout<<coinCombos(coins, len, amount)<<endl;
    return 0;
}
