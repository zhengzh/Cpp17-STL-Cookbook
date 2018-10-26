CXX = /home/zh/shengyi/build/bin/zapcc++
# CXX = g++
CXXFLAGS = -std=c++17 -Wall

SOURCES=$(wildcard *.cpp)
BINARIES=$(patsubst %.cpp,bin/%,$(SOURCES))

default: $(BINARIES)

bin/%: %.cpp
	$(CXX) $(CXXFLAGS) -g -o $@ $<

clean:
	rm -f $(BINARIES)
