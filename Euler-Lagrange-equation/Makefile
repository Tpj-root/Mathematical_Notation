# Simple Makefile for Euler-Lagrange example

CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = lagrange

all: $(TARGET)

$(TARGET): lagrange.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) lagrange.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)

