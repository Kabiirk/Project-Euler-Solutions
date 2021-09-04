/*
Problem 42
The nth term of the sequence of triangle numbers is given by, tn = ½n(n+1);
so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical
position and adding these values we form a word value. For example, the word value
for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a triangle number then we
shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing
nearly two-thousand common English words, how many are triangle words?

Answer : 162
*/

/*
TIPS:
If n is the mth triangular number, then n = m*(m+1)/2.

Solving for m using the quadratic formula:
m = (sqrt(8n+1) - 1) / 2

So n is triangular if and only if 8n+1 (modified_n) is a perfect square.

Ref : https://stackoverflow.com/questions/2913215/fastest-method-to-define-whether-a-number-is-a-triangular-number
Ref 2 : https://stackoverflow.com/questions/295579/fastest-way-to-determine-if-an-integers-square-root-is-an-integer
*/

#include <iostream>
#include <fstream>
#include <string> // for getline()
#include <math.h> // for ceil() & floor()

using namespace std;

int nameSum(string name){
    int sum=0;
    for(int j=0; j<name.length(); j++){
        sum += name[j] - 'A' + 1;
        // In ASCII, 'A' -> 65
        // for e.g. we want value of 'C'
        // now ASCII value of 'C' is 67,
        // but we want it's alphabetical value (3).
        // so what we did was :
        // [LETTER] - 'A' + 1 = Alphabetical value of LETTER
        // here  67 - 65 + 1 = 3 (for our 'C' example)
        // i.e. 'C' - 'A' + 1 = 3
        //      'D' - 'A' + 1 = 4
        //      'I' - 'A' + 1 = 9 and so on..
    }
    
    return sum;	
}

// essentially checking if a number is perfect square
bool isTriangleNum(int n){

    int modified_n = 8*n + 1;

    // check if n is perfect square
    bool is_perf_square;
    if (ceil((double)sqrt(modified_n)) == floor((double)sqrt(modified_n))) {
        is_perf_square = true;
    }
    else {
        is_perf_square = false;
    }

    return is_perf_square;
}

int main()
{
    fstream newfile;
    int name_sum, triangle_word_count = 0;
    
    newfile.open("p042_words.txt", ios::in);

    if(newfile.is_open()){
        string str;

        while(getline(newfile, str, ',')){
            string sub_str = str.substr(1,str.length()-2);//remove double-quotes
            name_sum = nameSum(sub_str);

            if(isTriangleNum(name_sum)){
                triangle_word_count += 1;
            }
        }
    newfile.close();
    }

    cout<<triangle_word_count<<endl;

    return 0;
}