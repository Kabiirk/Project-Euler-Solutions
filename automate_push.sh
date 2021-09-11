# Run the srcipt with commit message as command line argument :
# bash automate_push.sh "Some commit message"

if [ $# -ne 1 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

git add .
git commit -m "$1"
git push
echo "Changes Pushed Successfully !!"