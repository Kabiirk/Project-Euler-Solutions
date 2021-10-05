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

Answer : 376
*/

/*
TIPS:
cardNumArray -> Stored sorted numbers (including equivalents of Ten, Ace, Jack, King & Queen)
                e.g. for hand "AS KD 3D JD 8H", cardNumArray would be [ 3, 8, 11, 13, 14 ]

Straightforward approach, while comparing each hand, we keep track of all numbers (incl. Ten(10), 
Jack(11), Queen(12), King(K), Ace(14)) with cardNumArray and highest Card of each hand(highcard1 & highcard2).

Our main workhorse is determineRank() which checks for rank of a hand based on conditions given in the
question .

in P1Winner(), we compare rank of both hands and in case rank is same, we check which hand has higher
card in that rank (i.e. say hands of Player 2 and Player 2 are :

Player 1            Player 2      
5H 5C 6S 7S KD      2C 3S 8S 8D TD
Pair of Fives       Pair of Eights

if both hands have 1 pair which is same rank, but  pair of 8s beats pair of 5s, hence Player 2 Wins this round)

In this case highcard1 = 13(K) & highcard2 = 10(T) while handhigh1 = 5 and handhigh2 = 8.

In case of same rank, we execute tiebreaker() where first handhigh1 & handhigh2 are compared.
In case handhigh1 & handhigh2 are both same (say if, both hands have a pair of 5s or similar ties)
We compare highcard of each hand.

NOTE : I have Compared both players hands while
       reading line from p054_poker.txt but in
       case if it needs to be done separately,
       Store string in array/vector and use P1Winner()
       while iterating through that loop.

Awesome article about splitting strings
Ref. : https://www.fluentcpp.com/2017/04/21/how-to-split-a-string-in-c/

Some more info on splitting strings
Ref. : https://stackoverflow.com/questions/53849/how-do-i-tokenize-a-string-in-c
*/
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> // for remove_if()

using namespace std;

// cardNumArray = Store numbers in an array
// (To be sorted Later)
// handHigh = Highest card in a hand for a rank.
// totalHigh = highest card in a rank (irrespective wether it is a part of any card combo or not.)
int cardNumArray[5]={}, handHigh=0, totalHigh=0;

// Utility funtion
void printCardNumArray(){
        cout<<"[ ";
        for(int i = 0; i<5; i++){
                cout<<cardNumArray[i]<<" ";
        }
        cout<<"]"<<endl;
}

// converts all T,J,Q,K,A into number equivalents
// E.g. : Converts "AS KD 3D JD 8H" to "14S 13D 3D 11D 8H"
string convertHand(string hand){
        char cArray[5] = {'T','J','Q','K','A'};
        string sArray[5] = {"10","11","12","13","14"};
        for(int i=0; i<=hand.length()-2; i++){
                for(int j=0; j<=4; j++){
                        if(hand[i] == cArray[j]){
                                hand.replace(i,1, sArray[j]);
                        }
                }
        }
        return hand;
}

// collects all numbers from hand and puts them into cardNumArray
void collectNumbers(string hand){
        string subHand;
        int j=0, index=0;
        totalHigh=0;
        for(int i=0; i<=hand.length()-1; i++){
                if(hand[i]==' '){
                        continue;
                }
                if(hand[i]=='D'||hand[i]=='C'||hand[i]=='H'||hand[i]=='S'){
                        cardNumArray[index]=j;
                        subHand = "";
                        index++;
                        continue;
                }
                subHand += (std::to_string(hand[i]-'0'));
                j = stoi(subHand);
        }
        for(int i=0; i<=4; i++){
        if(cardNumArray[i]>totalHigh)
                totalHigh=cardNumArray[i];
    }
}

// bubble sort cardNumArray into ascending numerical order
void organizeCards(){
        int temp=0;
        for(int i=0; i<=4; i++){
                for(int j=i+1; j<=4; j++){
                        if(cardNumArray[j]<cardNumArray[i]){
                                temp = cardNumArray[i];
                                cardNumArray[i]=cardNumArray[j];
                                cardNumArray[j]=temp;
                        }
                }
        }
}

// If three of a kind, replace 3 repeating cards in cardNumArray with zeros
// remaining non-zero cards can then be checked for additional pair, making full house
void removeCards(){
        for(int i=0; i<=3; i++){
                if(cardNumArray[i] == cardNumArray[i+1] && cardNumArray[i+1] == cardNumArray[i+2]){
                        cardNumArray[i] = 0; 
                        cardNumArray[i+1] = 0;
                        cardNumArray[i+2] = 0;
                }
        }
}

// checks numbers of cardNumArray for straight
bool isStraight(){
        for(int i=0; i<=2; i++){
                if(cardNumArray[i] == cardNumArray[i+1]-1)
                        continue;
                else 
                        return false;
        }
        if(cardNumArray[3]==5 && cardNumArray[4]==14){
                return true;
        }
        else if(cardNumArray[3] == cardNumArray[4]-1){
                return true;
        }
        else{
                return false;
        }
}

// removes everything but suits from hand to see if flush
bool isFlush(string hand){
        string temp = hand;
        temp.erase(remove_if(temp.begin(), temp.end(), ::isspace), temp.end());
        temp.erase(remove_if(temp.begin(), temp.end(), ::isdigit), temp.end());
        for(int i=0; i<=3; i++){
                if(temp[i] == temp[i+1]){
                        continue;
                }
                else{ 
                        return false;
                }	
        }
        return true;
}

// checks numbers of cardNumArray for 3 or 4 of a kind
int nofaKind(){
        int count=0;
        for(int i=0; i<=2; i++){
                if(cardNumArray[i]==cardNumArray[i+1]&&cardNumArray[i+1]==cardNumArray[i+2])
                        count++;
        }
        if(count == 2){
                handHigh = cardNumArray[1];
                return 4;
        } 
        else if(count == 1){
                handHigh = cardNumArray[2];
                removeCards();
                organizeCards();
                return 3;
        }
        return 0;
}

// checks for pairs in cardNumArray
bool isPairs(){
        int count=0;
        for(int i=0; i<=3; i++){
                if(cardNumArray[i] == 0){
                        count++;
                        continue;
                }
                if(cardNumArray[i] == cardNumArray[i+1]){
                        if(count < 3){
                                handHigh = cardNumArray[i];
                        }
                        cardNumArray[i] = 0; 
                        cardNumArray[i+1] = 0;
                        return true;
                }
        }
        return false;
}

// associates a hand with its rank against other hands
int determineRank(string hand){
        bool flushTrue = isFlush(hand);
        //check for straight, straight flush, or royal flush
        if(isStraight()){
                if(flushTrue){
                        if(cardNumArray[0]==10)
                        	return 9;
                        else
                        	return 8;
                }
                else
                        return 4;
        } 
        //check for only flush
        else if(flushTrue)
                return 5;
        //check for 3 of a kind, 4 of a kind, and full house
        int kind = nofaKind();
        if(kind == 4)
                return 7;
        else if(kind == 3){
                if(isPairs())
                	return 6;
                else
                	return 3;
        } 
        //check for two pair or single pair;
        else if(isPairs()){
                if(isPairs())
                        return 2;
                else
                        return 1;
        }
        //rank zero, meaning no hand and only a high card
        else
                return 0;
}

// if hands are the same, high cards are compared to determine winner
int tiebreaker(int handHigh1, int highcard1, int handHigh2, int highcard2){
        if(handHigh1 > handHigh2)
                return 1;
        else if(handHigh2 > handHigh1)
                return 2;
        else {
                if(highcard1 > highcard2)
                        return 1;
                else
                        return 2;
        }
}

// tests both hands to determine what they are
int P1Winner(string hand1, string hand2){
        int rank1=0, rank2=0, handHigh1=0, highcard1=0, handHigh2=0, highcard2=0;
        
        hand1 = convertHand(hand1);
        collectNumbers(hand1);
        organizeCards();
        rank1 = determineRank(hand1);
        handHigh1 = handHigh, highcard1 = totalHigh;

        hand2 = convertHand(hand2);
        collectNumbers(hand2);
        organizeCards();
        rank2 = determineRank(hand2);
        handHigh2 = handHigh, highcard2 = totalHigh;

        // cout<<rank1<<" and "<<rank2<<endl;

        // Comparing Rank of Hands
        if(rank1 > rank2){
                return 1;
        }
        else if(rank2 > rank1){
                return 2;
        }
        else{
                return tiebreaker(handHigh1, highcard1, handHigh2, highcard2);
        }
}

int main(){
    fstream newfile;
    int res=0, winner=0;
    string hands, hand1, hand2;

    newfile.open("p054_poker.txt", ios::in);

    // Read from file and put into 1D Vector
    if(newfile.is_open()){
        string s;
        while(getline(newfile, s)){
                hand1 = s.substr(0, 14); // "AS KD 3D JD 8H"
                hand2 = s.substr(15, 14); // "7C 8C 5C QD 6C"
                winner = P1Winner(hand1, hand2);
                if(winner == 1){
                        res++;
                }
            }
            newfile.close();
    }

   cout<<res<<endl;

    return 0;
}