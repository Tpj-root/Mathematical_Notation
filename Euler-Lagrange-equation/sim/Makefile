CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall
TARGET = lagrange_sim

all: $(TARGET)

$(TARGET): lagrange_sim.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) lagrange_sim.cpp

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) motion.txt

