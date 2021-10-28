if [ $# -ne 1 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

for entry in `ls $1`; do
    python $1/$entry
done