if [ $# -ne 1 ]
  then
    echo "Improper number of arguments supplied"
    exit 1
fi

COMPILER_PATH=C:/MinGW/bin/g++ 
cd $1
CPP_FILE=$(find . -type f -name "*.cpp" | sed "s|^\./||")

if [ ${CPP_FILE} ]
  then
    FILE_NAME="${CPP_FILE%.*}.cpp"
    EXE_NAME="${CPP_FILE%.*}.exe"
    echo ${FILE_NAME}
    echo ${EXE_NAME}
    ${COMPILER_PATH}  ${FILE_NAME} -o ${EXE_NAME}
    cd ..
    exit 1
  else
    echo "No Such File in Directory."
    exit 1
fi