CXX = g++
CXXFLAGS = `pkg-config opencv --cflags`
LDLIBS = -Wall -std=c++11 -lglut -lGL -lGLU `pkg-config opencv --libs`
SOURCE := $(shell ls *.cpp)
HEADER := $(shell ls *.h)
OBJS := $(SOURCE:.cpp=.o)
TARGET = CausalNetwork

all: clean $(TARGET)

$(TARGET):$(OBJS)
	$(CXX) -o $@ $(OBJS) $(LDLIBS)

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $^

clean:
	rm -f *.o
