@echo off

chcp 65001

cls

rem gcc -Wall -fstack-protector-all -fsanitize=address -g -o main main.c 

gcc -Wall -fstack-protector-all -g -o main main.c 

gdb main
  
del main.exe