# Bash script to run code irrespective of code being
# written in C++ or Python. Precedence given to C++
# if both files are present. It exits after executing
# 1 either of the Codes.

# All that needs to be done is type :
# bash run.sh XXXX

# where XXXX is diretory where .py or .exe(c++ executable)
# is stored

# e.g. : bash run.sh 0069
# would look for file.exe and execute it if present
# else it would look for file.py and execute that.

if [ $# -ne 1 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

cd $1
CPP_FILE=$(find . -type f -name "*.exe")

if [ ${CPP_FILE} ]
  then
    FILE_NAME="${CPP_FILE%.*}"
    ${FILE_NAME}
    cd ..
    exit 1
  else
    PY_FILE=$(find . -type f -name "*.py" | sed "s|^\./||")
    FILE_NAME="${PY_FILE%.*}.py"
    python ${FILE_NAME}
    cd ..
    exit 1
fi