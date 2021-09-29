/*
Problem 54
In the card game poker, a hand consists of five cards and are ranked,
from lowest to highest, in the following way:

* High Card: Highest value card.
* One Pair: Two cards of the same value.
* Two Pairs: Two different pairs.
* Three of a Kind: Three cards of the same value.
* Straight: All cards are consecutive values.
* Flush: All cards of the same suit.
* Full House: Three of a kind and a pair.
* Four of a Kind: Four cards of the same value.
* Straight Flush: All cards are consecutive values of same suit.
* Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.

The cards are valued in the order:
2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.

If two players have the same ranked hands then the rank made up of the
highest value wins; for example, a pair of eights beats a pair of fives (see example 1 below).
But if two ranks tie, for example, both players have a pair of queens,
then highest cards in each hand are compared (see example 4 below); if
the highest cards tie then the next highest cards are compared, and so on.

Consider the following five hands dealt to two players:

Hand    Player 1            Player 2               Winner
1       5H 5C 6S 7S KD      2C 3S 8S 8D TD         Player 2
        Pair of Fives       Pair of Eights

2       5D 8C 9S JS AC      2C 5C 7D 8S QH         Player 1
        Highest card Ace    Highest card Queen

3       2D 9C AS AH AC      3D 6D 7D TD QD         Player 2
        Three Aces          Flush with Diamonds

4       4D 6S 9H QH QC      3D 6D 7H QD QS         Player 1
        Pair of Queens      Pair of Queens
        Highest card Nine   Highest card Seven

5       2H 2D 4C 4D 4S      3C 3D 3S 9S 9D         Player 1
        Full House          Full House
        With Three Fours    With Three Threes

The file, p054_poker.txt, contains one-thousand random hands dealt to two players.
Each line of the file contains ten cards (separated by a single space): the
first five are Player 1's cards and the last five are Player 2's cards.

You can assume that all hands are valid (no invalid characters or repeated cards),
each player's hand is in no specific order, and in each hand there is a clear winner.

How many hands does Player 1 win?

Answer : 
*/

/*
TIPS:

NOTE : Comparing both players hands can also be done while
       reading line from p054_poker.txt but I have kept 
       reading data from file and writing data from file
       as separate operations.

Awesome article about splitting strings
Ref. : https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/

Some more info on splitting strings
Ref. : https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c

*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int value(char str){
    switch(str){
        case '2':
                return 2;
        case '3':
                return 3;
        case '4':
                return 4;
        case '5':
                return 5;
        case '6':
                return 6;
        case '7':
                return 7;
        case '8':
                return 8;
        case '9':
                return 9;
        case '10':
                return 10;
        case 'J': // Jack
                return 11;
        case 'Q': // Queen
                return 12;
        case 'K': // King
                return 13;
        case 'A': // Ace
                return 14;
        case 'C': // Club
                return 15;
        case 'S': // Spade
                return 16;
        case 'H': // Heart
                return 17;
        case 'D': // Diamond
                return 18;
        }
}

// Checking Rank of Hand


// Split String based on delimiter
vector<string> split(const string& s, char delimiter)
{
   vector<string> tokens;
   string token;
   istringstream tokenStream(s);
   while (getline(tokenStream, token, delimiter))
   {
      tokens.push_back(token);
   }
   return tokens;
}

// Utility function to print Vectors
void printVector(vector<string> v){
        cout<<"< ";
        for(auto &itr : v){
                cout<<itr<<" "; 
        }
        cout<<">"<<endl;
}

// Compares both hands to see if Player 1 won
// returns true if Player 1 won 
//         false if Player 1 lost (i.e. Player 2 won) 
bool isP1Winner(vector<string> both_hands, vector<string> p1_hand, vector<string> p2_hand){
    // 
    p1_hand = {both_hands[0], both_hands[1], both_hands[2], both_hands[3], both_hands[4]};
    p2_hand = {both_hands[5], both_hands[6], both_hands[7], both_hands[8], both_hands[9]};

    printVector(p1_hand);
    printVector(p2_hand);
    return true;
}

int main() {
    fstream newfile;
    vector<vector<string>> all_hands;
    vector<string> p1, p2;
    int res;

//     newfile.open("p054_poker.txt", ios::in);

//     // Read from file and put into 2D Vector
//     if(newfile.is_open()){
//         string p1_p2_hands;
//         while(getline(newfile, p1_p2_hands)){
//                 //cout<<p1_p2_hands<<endl;
//                 vector<string> str = split(p1_p2_hands, ' ');
//                 all_hands.push_back(str);
//             }
//             newfile.close();
//     }

//     int n = all_hands.size();
//     cout<<n<<endl;
//     for(int i = 0; i<n; i++){
//         if(isP1Winner(all_hands[i], p1, p2)){
//                 res++;
//         }
//     }

//    cout<<res<<endl;

    //Testing
    vector<string> hands1 = split("5H 5C 6S 7S KD 2C 3S 8S 8D TD", ' ');
    //  5H 5C 6S 7S KD      2C 3S 8S 8D TD         Player 2 Wins
    //  Pair of Fives       Pair of Eights

    vector<string> hands2 = split("2H 2D 4C 4D 4S 3C 3D 3S 9S 9D", ' ');
    //  2H 2D 4C 4D 4S      3C 3D 3S 9S 9D         Player 1 Wins
    //  Full House          Full House
    //  With Three Fours    With Three Threes
    bool a = isP1Winner(hands1, p1, p2);
    bool b = isP1Winner(hands2, p1, p2);
    return 0;
}
