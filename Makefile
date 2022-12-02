# Do all
UNAME := $(shell uname)

CC := gcc
CXX := g++

# Mac uses clang by default, which does not support nested functions and aasm build fails, so install gcc
# brew install gcc
ifeq ($(UNAME), Darwin)
	CC = /opt/homebrew/opt/gcc/bin/gcc-12
endif

all: jimulator kcmd aasm

kcmd: src/kcmdSrc/kcmd.cpp
	$(CXX) $^ -o bin/kcmd -std=c++17 -pthread

jimulator: src/jimulatorSrc/jimulator.cpp
	$(CXX) -w -o bin/jimulator $^ -Wall -Wextra -O3 -std=c++17

aasm: src/aasmSrc/aasm.c
	$(CC) $^ -w -o bin/aasm
