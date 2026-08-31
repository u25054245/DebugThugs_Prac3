#u25420314 - Christian Khalid
#u25054245 - Nathan Spavins

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O0

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
TARGET = EventFlow

.PHONY: all clean valgrind run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)