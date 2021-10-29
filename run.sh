if [ $# -ne 1 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

if [ ${CPP_FILE} ]
  then
    echo "File exists"
    echo $PWD
    CPP_FILE=$(find . -type f -name "*.exe")
    FILE_NAME="${CPP_FILE%.*}"
    ${FILE_NAME}
    cd ..
    exit 1
  else
    echo $PWD
    PY_FILE=$(find . -type f -name "*.py" | sed "s|^\./||")
    FILE_NAME="${PY_FILE%.*}.py"
    echo ${FILE_NAME}
    python ${FILE_NAME}
    cd ..
    exit 1
fi