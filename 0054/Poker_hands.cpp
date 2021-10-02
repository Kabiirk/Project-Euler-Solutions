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
vector check = < A(Ace), 2, 3, 4, 5, 6, 7, 8, 9, T(Ten), J(Jack), Q(Queen), K(King), C(Club), S(Spade), H(Heart), D(Diamond) >

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
#include <algorithm>

using namespace std;

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
void printVector(vector<int> v){
        cout<<"< ";
        for(auto &itr : v){
                cout<<itr<<" "; 
        }
        cout<<">"<<endl;
}

// Card Value
int value(char str){
    switch (str){
        case 'A':
                return 1;
                break;
        case '2':
                return 2;
                break;
        case '3':
                return 3;
                break;
        case '4':
                return 4;
                break;
        case '5':
                return 5;
                break;
        case '6':
                return 6;
                break;
        case '7':
                return 7;
                break;
        case '8':
                return 8;
                break;
        case '9':
                return 9;
                break;
        case 'T':
                return 10;
                break;
        case 'J':
                return 11;
                break;
        case 'Q':
                return 12;
                break;
        case 'K':
                return 13;
                break;
        case 'C': // CLUBS
                return 14;
                break;
        case 'S': // SPADES
                return 15;
                break;
        case 'H': // HEARTS
                return 16;
                break;
        case 'D': // DIAMONDS
                return 17;
                break;
        default:
                return 0;
                break;
    }
    return 0;
}

// Checking if hand is a Royal Flush
// Ten, Jack, Queen, King, Ace, in same suit
int RoyalFlush(string hand){
        vector<int> check(18, 0);
        for(int i = 0; i<10; i++){
                check[value(hand.at(i))]++;
        }

        if(check[10] && check[11] && check[12] && check[13] && check[1] && (check[14]==5 || check[15]==5 || check[16]==5 || check[17]==5) ){
                return 1;
        }
        else{
                return 0;
        }
}

// Checking if hand is a Straight Flush
// All cards are consecutive values of same suit
int straightFlush(string hand){
        vector<int> check(18, 0);
  
        for(int i = 0; i<10; i++){
                check[value(hand.at(i))]++;
        }
        
        for(int j=0; j+4<13; j++){

                if(check[j] && check[j+1] && check[j+2] && check[j+3] && check[j+4] && (check[14]==5 || check[15]==5 || check[16]==5 || check[17]==5) ){
                        return j+4;
                }
        }
        return 0;
}

// Checking if hand is a Four of a Kind
// Four cards of the same value
int fourOfAKind(string hand){
        vector<int> check(18, 0);
        for(int i = 0; i<10; i+=2){
                check[value(hand.at(i))]++;
        }

        for(int j = 0; j<13; j++){
                if(check[j]==4){
                        return j;
                }
        }
        return 0;
}

// Checking if hand is a Flush
// All cards of the same suit
int flush(string hand){
        vector<int> check(18, 0);
        
        for(int i = 1; i<10; i+=2){
                check[value(hand.at(i))]++;
        }

        if (check[14]==5||check[15]==5||check[16]==5||check[17]==5){
                return 1;
        }
        else{
                return 0;
        }
}

// Checking if hand is a Straight
// All cards are consecutive values
int straight(string hand){
        vector<int> check(18, false);
        for(int a=0; a<10; a+=2){
                check[value(hand.at(a))]++;
        }
        for (int i=0;i+4<=13;i++){
                if (check[i]==true&&check[i+1]==true&&check[i+2]==true&&check[i+3]==true&&check[i+4]==true){
                        return i+4;
                }
        }
        return 0;
}

// Checking if hand is a Three of a Kind
// Three cards of the same value
int threeOfAKind(string hand){
        vector<int> check(18, 0);
        for(int i = 0; i<10; i+=2){
                check[value(hand.at(i))]++;
        }

        for(int j = 0; j<13; j++){
                if(check[j]==3){
                        return j;
                }
        }
        return 0;
}

// Checking if hand is a Two Pairs
// Two different pairs
int twoPair(string hand){
        vector<int> check(18, 0);
        int count = 0;
        for(int i=0; i<10; i+=2){
                check[value(hand.at(i))]++;
        }

        vector<int> pairs;
        for(int j=0; j<=13; j++){
                if(check[j] == 2){
                        count++;
                        pairs.push_back(j);
                }
                if(pairs.size() == 2){
                        if(pairs[0] > pairs[1]){
                                return pairs[0];
                        }
                        else{
                                return pairs[1];
                        }
                }
        }
        return 0;
}

// Checking if hand is a One Pair
// Two cards of the same value
int onePair(string hand){
        vector<int> check(18, 0);
        for (int i=0;i<10;i+=2){
                check[value(hand.at(i))]++;
        }
        //printVector(check);
        for(int j=0; j<=13; j++){
                if(check[j] == 2){
                        return j;
                }
        }

        return 0;
}

// Checking if hand is a Full House
// Three of a kind and a pair
int fullHouse(string hand){
        if(onePair(hand)!=0 && threeOfAKind(hand)>0){
                return threeOfAKind(hand);
        }
        else{
                return 0;
        }
}

// Checking if hand is a High Card
// Highest value card
int highCard(string str,int rank){
    vector<int> max;
    for (int i=0;i<9;i+=2){
        if (value(str.at(i))==1){
                max.push_back(14);
        }
        else{
            max.push_back(value(str.at(i)));
        }
    }
    sort(max.begin(), max.end());
    return max[max.size()-1-rank+1];
}

bool tiebreaker(string hand1, string hand2){
        for(int i=1;; i++){
                if(highCard(hand1, i) > highCard(hand2, i)){
                        return 1;
                }
                else if(highCard(hand1, i) < highCard(hand2, i)){
                        return 0;
                }
        }
        return 0;
}

int determineRank(string hand){
        int rank;
        if(RoyalFlush(hand)){
            rank=9;
        }
        else if (straightFlush(hand)>0){
            rank=8;
        }
        else if (fourOfAKind(hand)>0){
            rank=7;
        }
        else if (fullHouse(hand)>0){
            rank=6;
        }
        else if (flush(hand)>0){
            rank=5;
        }
        else if (straight(hand)>0){
            rank=4;
        }
        else if (threeOfAKind(hand)>0){
            rank=3;
        }
        else if (twoPair(hand)>0){
            rank=2;
        }
        else if (onePair(hand)>0){
            rank=1;
        }
        else{
            rank=0;
        }
        return rank;
}

// Compares both hands to see if Player 1 won
// returns true if Player 1 won 
//         false if Player 1 lost (i.e. Player 2 won) 
bool isP1Winner(string hands){
    // 
    string p1_hand = hands.substr(0,10);
    string p2_hand = hands.substr(10,20);
    int rank1 = determineRank(p1_hand);
    int rank2 = determineRank(p2_hand);
    cout<<rank1<<" "<<rank2<<endl;
    if(rank1 > rank2){
            return 1;
    }
    else if(rank1 < rank2){
            return 0;
    }
    // Tiebreaking conditions
    else if(rank1 == rank2){
            if(rank1 == 8){
                if (straightFlush(p1_hand)>straightFlush(p2_hand)){
                        return 1;
                }
                else if (straightFlush(p1_hand)<straightFlush(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 7){
                if (fourOfAKind(p1_hand)>fourOfAKind(p2_hand)){
                        return 1;
                }
                else if (fourOfAKind(p1_hand)<fourOfAKind(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 6){
                if (fullHouse(p1_hand)>fullHouse(p2_hand)){
                        return 1;
                }
                else if (fullHouse(p1_hand)<fullHouse(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 5){
                    return tiebreaker(p1_hand, p2_hand);
            }
            else if(rank1 == 4){
                if (straight(p1_hand)>straight(p2_hand)){
                        return 1;
                }
                else if (straight(p1_hand)<straight(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 3){
                if (onePair(p1_hand)>onePair(p2_hand)){
                        return 1;
                }
                else if (onePair(p1_hand)<onePair(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 2){
                if (twoPair(p1_hand)>twoPair(p2_hand)){
                        return 1;
                }
                else if (twoPair(p1_hand)<twoPair(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 1){
                if (onePair(p1_hand)>onePair(p2_hand)){
                        return 1;
                }
                else if (onePair(p1_hand)<onePair(p2_hand)){
                        return 0;
                }
                else{
                        return tiebreaker(p1_hand, p2_hand);
                }
            }
            else if(rank1 == 0){
                    return tiebreaker(p1_hand, p2_hand);
            }
    }

    return 0;
}

void testOutput(string hand){
        cout<< "RoyalFlush : " << RoyalFlush(hand)<<endl;
        cout<< "straightFlush : " << straightFlush(hand)<<endl;
        cout<< "fourOfAKind : " << fourOfAKind(hand)<<endl;
        cout<< "flush : " << flush(hand)<<endl;
        cout<< "straight : " << straight(hand)<<endl;
        cout<< "threeOfAKind : " << threeOfAKind(hand)<<endl;
        cout<< "twoPair : " << twoPair(hand)<<endl;
        cout<< "onePair : " << onePair(hand)<<endl;
        cout<< "fullHouse : " << fullHouse(hand)<<endl;
        cout<< "highCard : " << highCard(hand, 1)<<endl;
}

int main() {
//     fstream newfile;
//     vector<string> all_hands;
//     int res = 0;

//     newfile.open("p054_poker.txt", ios::in);

//     // Read from file and put into 2D Vector
//     if(newfile.is_open()){
//         string s;
//         while(getline(newfile, s)){
//                 //cout<<s<<endl;
//                 s.erase(remove(s.begin(), s.end(), ' '), s.end());
//                 all_hands.push_back(s);
//             }
//             newfile.close();
//     }

//     int n = all_hands.size();
//     for(int i = 0; i<n; i++){
//             if(isP1Winner(all_hands[i])){
//                     res++;
//             }
//     }

//     cout<<res<<endl;

    //Testing
    string h1 = "5H5C6S7SKD2C3S8S8DTD";
    string h2 = "4D6S9HQHQC3D6D7HQDQS";
    //bool a = isP1Winner(h1); // No
        // Pair of Fives       Pair of Eights


    //bool b = isP1Winner(h2); // Yes
        // Full House          Full House
        // With Three Fours    With Three Threes
    string p1_hand = h2.substr(0,10);
    string p2_hand = h2.substr(10,20);

    cout<<p1_hand<<endl;
    testOutput(p1_hand);
    cout<<"\n"<<endl;
    cout<<p2_hand<<endl;
    testOutput(p2_hand);
    bool a = isP1Winner(h2);
    cout<<a<<endl;
    
    //cout<< "< A 2 3 4 5 6 7 8 9 T J Q K C S H D >" <<endl;
    return 0;
}
