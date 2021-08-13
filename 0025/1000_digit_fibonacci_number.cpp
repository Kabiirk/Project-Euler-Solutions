/*
Problem 25
The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn-1 + Fn-2, where F1 = 1 and F2 = 1.
Hence the first 12 terms will be:

F1 = 1
F2 = 1
F3 = 2
F4 = 3
F5 = 5
F6 = 8
F7 = 13
F8 = 21
F9 = 34
F10 = 55
F11 = 89
F12 = 144
The 12th term, F12, is the first term to contain three digits.

What is the index of the first term in the Fibonacci sequence to contain 1000 digits?contain 1000 digits?

Answer : 4782
*/

/*
TIPS:
Instead of standard data types, we need to hold our numbers in vectors. (vector<unsigned int> Fib_terms)
1) We define a 'result' vector to keep the current fibonacci term
2) We define 2 vectors as initial 2 terms F1 & F2.
   (which we later consider as Fn-1 and Fn-2 terms),
3) Add them as per Fibonacci formula. (Through a custom function to add vectors with element-wise addition)
4) Repeat 2) & 3) till size result vector is >=1000.
   While keeping track of index value as that is the req. answer.

Note: These vectors hold the number in reverse, where vector[0] = Least Significant digit
and vector[n] = Most Significant Digit (n being index coming after 0 i.e 100th, 121st digit etc.)

Ref. to this website for an interesting approach (Principle of convergence of large fibonacci numbers) :
https://www.mathblog.dk/project-euler-25-fibonacci-sequence-1000-digits/
*/

#include <vector>
#include <iostream>

using namespace std;

typedef vector<unsigned int> Fib_term;

Fib_term addVect(const Fib_term a, const Fib_term b){
	Fib_term sum = b;
	
	unsigned int carry = 0;
	for(unsigned int i = 0; i < sum.size(); i++){
		if(i<a.size()){
			sum[i] += a[i];
		}
		sum[i] += carry;
		
		// handle overflow
		if(sum[i] >= 10){
			carry = 1;
			sum[i] -= 10;
		}
		else{
			carry = 0;
		}
	}
	
	// If Largest Digit overflowing
	if(carry != 0){
			sum.push_back(carry);
	}
	
	return sum;
}

int main()
{
	Fib_term result = {0, 1};
	// f(1)
	Fib_term f1 = {1};
	// f(2)
	Fib_term f2 = {1};
	unsigned int index = 2;
	
	while(result.size()<=1000){
		index++;
		auto next_fib_term = addVect(f1, f2);
		f1 = move(f2);
		f2 = move(next_fib_term);
		
		// digits in current fibonacci number
		auto num_digits = f2.size();
		// digits of previouly largest fibonacci number
		auto prev_digits = result.size() - 1;
		
		if(prev_digits < num_digits){
			result.push_back(index);
		}
		
	}
	cout<<index<<endl;
	
    return 0;
}
