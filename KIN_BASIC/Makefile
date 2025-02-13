# Compiler and flags
CXX = g++
CXXFLAGS = -I/usr/local/include -I/usr/include/eigen3 -I/usr/local/include/kdl
LDFLAGS = -L/usr/local/lib
LIBS = -lorocos-kdl

# Source and output file
SRC = main.cpp
OUT = test_orocos_kdl

# Default target
all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LDFLAGS) $(LIBS)

# Clean the build
clean:
	rm -f $(OUT)

