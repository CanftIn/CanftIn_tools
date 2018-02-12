CXX = g++
CXXFLAGS=-std=c++1y -Wall

DIR=./

SOURCES=$(wildcard *.cpp)
dir=$(notdir $(SOURCES))
BINARIES=$(patsubst %.cpp, $(DIR)bin/%, $(dir))

default: $(BINARIES)

bin/%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(BINARIES)

