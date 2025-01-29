#!/usr/bin/env bash

g++ -c -Wall -Werror -fpic -I /opt/codac/include fail_instruction.cpp
g++ -shared -o libfail.so -L/opt/codac/lib -loac-tree fail_instruction.o
