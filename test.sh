#!/bin/bash

export HOSTTYPE=$(uname -m)_$(uname -s)

make -s all

gcc -w -gdwarf-2 -g3 -I./include -L. testing/test$1.c -lft_malloc_$HOSTTYPE -o test
gcc -w -gdwarf-2 -g3 -I./include testing/test$1.c -o test_true_malloc

if [ "$2" = "gdb" ]; then
    LD_LIBRARY_PATH=. gdb ./test
else
    LD_LIBRARY_PATH=. ./test
fi