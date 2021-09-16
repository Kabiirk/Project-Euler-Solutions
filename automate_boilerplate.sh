# Copies 0003/ files for boilerplate creation & deletes 0003/file_name.exe
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

cp -R 0003/ $1/
rm $1/*.exe
mv $1/*.cpp $1/$2.cpp
cd ..

echo "Boilerlpate Directory created !!"