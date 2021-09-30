# /bin/bash

as main.s -o main.o
ld main.o -o run
objdump -S run > dump.s
rm main.o
