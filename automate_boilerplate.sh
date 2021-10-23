# Makes new file_name.cpp  or file_name.py with given arguments
# Run the srcipt with commit message as command line argument :
# bash automate_copy_rename.sh XXXX file_name c++/py
#
# Put 3rd argument either as 'c++' if working with file.cpp
# or put it as py if you want to work with a file.py script
# XXXX - Problem Number with leading zeros if it is less
# than 4 digits
# e.g. : If problem number is 69, command used would be 
# bash automate_copy_rename.sh 0069 file_name

if [ $# -ne 3 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

if [ -d  "$1" ]
  then
    echo "Folder by this name exists"
    echo "Choose a different name"
    exit 1
fi

mkdir $1/

# File creation
if [ "$3" = "c++" ]
  then
    echo "/*
Problem x

Answer : 
*/

/*
TIPS:

*/

#include <iostream>

using namespace std;

int main() {
    cout<<\"Hello Euler !!\"<<endl;

    return 0;
}" > $1/$2.cpp;
  else
    echo "'''
Problem X

Answer :
'''

'''
TIPS:

'''

print(\"Hello Euler !!\")" > $1/$2.py;
fi
cd ..

echo "Boilerlpate Directory created !!";