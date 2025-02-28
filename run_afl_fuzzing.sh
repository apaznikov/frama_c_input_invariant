#!/bin/bash

PROG=$1

AFL_IN="${PROG}_afl_in"
AFL_OUT="${PROG}_afl_out"

[ ! -d "$AFL_IN" ] && mkdir $AFL_IN
[ ! -d "$AFL_OUT" ] && mkdir $AFL_OUT

echo "123" >$AFL_IN/seed

afl-fuzz -i $AFL_IN -o $AFL_OUT -- ./${PROG}_instr