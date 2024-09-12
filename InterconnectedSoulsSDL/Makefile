CXX = g++
CXXFLAGS = -Wall
INCLUDE_DIRS = -Iinclude/SDL2/ -Iinclude/headers/
LIB_DIR = -Lbuild/lib/
LIBS = -lSDL2main -lSDL2_image -lSDL2 

SRCS = src/Main.cpp src/Game.cpp src/Player.cpp
OBJS = $(patsubst src/%.cpp, %.o, $(SRCS))

all: GameEXE

GameEXE: $(OBJS)
	$(CXX) $^ -o $@ $(LIB_DIR) $(LIBS) 

%.o: src/%.cpp
	$(CXX) $(INCLUDE_DIRS) -c $< -o $@ $(CXXFLAGS)

clean:
	rm -f GameEXE $(OBJS)

.PHONY: all clean
