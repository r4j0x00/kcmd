# Do all
all: jimulator kcmd


kcmd: src/kcmdSrc/kcmd.cpp
	g++ src/kcmdSrc/kcmd.cpp -o bin/kcmd -std=c++17 -pthread

# Compile the jimulator binary.
jimulator: src/jimulatorSrc/jimulator.cpp
	g++ -w -o bin/jimulator src/jimulatorSrc/jimulator.cpp -Wall -Wextra -O3 -std=c++17
