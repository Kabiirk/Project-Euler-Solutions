# Makefile to compile filename.cpp
# Outputs filename.exe
# run file by typing the following in terminal :
# make -f Compile.mk DIR=0069
#
# Where your directory structure is :
# 0069/
# filename.cpp
#
# or 
# 0069/
# filename.cpp    filename.exe

COMPILEDIR = C:/MinGW/bin/g++
DIR = 0001
CPPFILENAME = $(wildcard $(DIR)/*.cpp)
EXEFILENAME = $(basename $(notdir $(CPPFILENAME)))

all:
	$(COMPILEDIR) $(CPPFILENAME) -o $(DIR)/$(EXEFILENAME).exe