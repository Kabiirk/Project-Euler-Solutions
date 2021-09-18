# !!!!!!!!!!!!!!!!!! ATTENTION !!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
# RUN THIS AFTER RUNNING Compile.mk
# SINCE THIS REQUIRES THE .exe file TO BE CREATED
# FIRST OTHERWISE IT WILL SHOW THIS ERROR :
#
# process_begin: CreateProcess(NULL, 0069/file1, ...) failed.
# make (e=2): The system cannot find the file specified.
# make: *** [all] Error 2
#
# !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
#
# Makefile to run the compiled filename.exe
# run file by typing the following in terminal :
# make -f Run.mk DIR=0069
#
# Where your directory structure is :
# 0069/
# filename.cpp    filename.exe

DIR = 0001
CPPFILENAME = $(wildcard $(DIR)/*.cpp)
EXEFILENAME = $(basename $(notdir $(CPPFILENAME)))

all:
	@$(DIR)/$(EXEFILENAME)