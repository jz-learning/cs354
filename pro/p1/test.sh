#!/bin/bash

echo hello $1;


if [ $1 = "user" ] 
then
echo hello
TEST=tests/userTests
REST=results/userResult
elif [ $1 = "pass" ] 
then
	TEST=tests/passTests
	REST=results/passResult
elif [ $1 = "email" ]
then
	TEST=tests/emailTests
	REST=results/emailResult
fi

for i in `seq 1 25`; 
	do echo $i ; 
	rm -f $REST/r$i.txt
	./verify < $TEST/t$i >> $REST/r$i.txt; 
	diff $REST/r$i.txt $TEST/o$i ; 
	echo ; 
done