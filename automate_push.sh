# Run the srcipt with commit message as command line argument :
# bash automate_push.sh "Some commit message"

git add .
git commit -m "'$1'"
git push
echo "Changes Pushed Successfully !!"