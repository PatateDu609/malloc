#!/bin/bash

export HOSTTYPE=$(uname -m)_$(uname -s)

make -s all

rm -f test test_true_malloc

gcc -w -gdwarf-2 -g3 -I./include -L. testing/test$1.c -lft_malloc_$HOSTTYPE -o test
res=$?

if [ $res != 0 ]; then
    echo -e "\e[31mBuild failed...\e[0m"
    exit 1
fi

gcc -w -gdwarf-2 -g3 -DTRUE_MALLOC -I./include testing/test$1.c -o test_true_malloc

if [ "$2" = "gdb" ]; then
    LD_LIBRARY_PATH=. gdb ./test
elif [ "$2" = "time" ]; then
    echo -e "\e[31;1mMy malloc\e[0m"
    LD_LIBRARY_PATH=. /usr/bin/time -v ./test
    echo
    echo -e "\e[31;1mOriginal malloc\e[0m"
    /usr/bin/time -v ./test_true_malloc
else
    LD_LIBRARY_PATH=. ./test
fi