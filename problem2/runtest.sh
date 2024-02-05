#!/bin/bash

# USAGE: 
# To run all the tests 
#   ./runtest.sh 
# To run a single test, e.g., 05
#   ./runtest.sh 05

TESTS="05 06 07 08 09"
EXE=problem2

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
