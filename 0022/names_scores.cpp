/*
Problem 22
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file
containing over five-thousand first names,begin by sorting it into alphabetical
order. Then working out the alphabetical value for each name, multiply this
value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is
worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list.
So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?

Answer : 871198282
*/

/*
TIPS:
1) Read names from file & store them in a vector.
2) Sort the vector alphabetically
3) Iterate over the vector for final Score.
	3.1) Calculate sum of alphabets in each name( nameSum does it with ASCII values).
	3.2) Multiply it with the name's index (after sorting).
	3.3) Keep adding iteratively to variable name_score.

*/

#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

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

bool stringComparison(string a, string b){
	//returns 1 if string a is alphabetically 
	//less than string b
	//quite similar to strcmp operation
	return a<b;
}

int main()
{
	vector<string> container;
	fstream newfile;
	
	newfile.open("p022_names.txt", ios::in);
	
	if(newfile.is_open()){
		string str;
		while(getline(newfile, str, ',')){
			string sub_str = str.substr(1,str.length()-2);
			//cout<<sub_str<<"\n";
			// Populate vector with only names
			container.push_back(sub_str);
		}
		newfile.close();
	}
	
	// Sort the vector Alphabetically
	sort(container.begin(),container.end(),stringComparison);
	
	// Name Score Calculation
	unsigned long long int name_score = 0;
	int temp_name_score;
	for(int i=0; i<container.size(); i++){
			//cout<<i+1<<") "<<container[i]<<endl;
			temp_name_score = nameSum(container[i])*(i+1);
			name_score+=temp_name_score;
		}
	
	cout<<name_score<<endl;
	
    return 0;
}
