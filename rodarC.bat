@echo off

chcp 65001

cls

gcc -o main main.c && main

del main.exe