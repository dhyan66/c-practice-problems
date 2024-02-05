#!/bin/bash

# USAGE: 
# To run all the tests 
#   ./runtest.sh 
# To run a single test, e.g., 11
#   ./runtest.sh 11

TESTS="10 11 12 13 14"
EXE=problem3

if [ -x $EXE ]; then
	EXECDIR=.
elif [ -x  cmake-build-debug/$EXE ]; then
	EXECDIR=cmake-build-debug
else
	echo Cannot find $EXE
	exit
fi

if [ $1"X" == "X" ]; then
	for i in $TESTS; do
		./tests/test.sh $i $EXECDIR $EXE
	done
else
	./tests/test.sh $1 $EXECDIR $EXE
fi
