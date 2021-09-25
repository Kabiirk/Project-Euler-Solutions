# Makes new file_name.cpp with given content
# Run the srcipt with commit message as command line argument :
# bash automate_copy_rename.sh XXXX file_name
#
# XXXX - Problem Number with leading zeros if it is less
# than 4 digits
# e.g. : If problem number is 69, command used would be 
# bash automate_copy_rename.sh 0069 file_name

if [ $# -ne 2 ]
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
}" > $1/$2.cpp

cd ..

echo "Boilerlpate Directory created !!"