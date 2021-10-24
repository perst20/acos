#!/usr/bin/env sh

SCRIPT_PATH=$(dirname "$(realpath -s "$0")")
cd "$SCRIPT_PATH"

printf "Run help\n";
time cmake-build-debug/hw2;

printf "\nRun test #0\n"
time cmake-build-debug/hw2 -f tests/test0.txt results/test0.out.txt

printf "\nRun test #1\n"
time cmake-build-debug/hw2 -f tests/test1.txt results/test1.out.txt

printf "\nRun test #2\n"
time cmake-build-debug/hw2 -f tests/test2.txt results/test2.out.txt

printf "\nRun test #3\n"
time cmake-build-debug/hw2 -f tests/test3.txt results/test3.out.txt

printf "\nRun test #4\n"
time cmake-build-debug/hw2 -f tests/test4.txt results/test4.out.txt

printf "\nRun test #5\n"
time cmake-build-debug/hw2 -f tests/test5.txt results/test5.out.txt

printf "\nRun test #6 (random)\n"
time cmake-build-debug/hw2 -n 10000 results/test1.out.txt