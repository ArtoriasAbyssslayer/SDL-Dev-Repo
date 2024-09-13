# Define the link target
linkTarget = qbRay

#Define the libraries
LIBS = -lSDL2 

#Define compilation flags
CFLAGS = -std=c++17

#Define the object files that we need to use
objects = main.o \
					CApp.o \
					$(patsubst %.cpp, %.o, $(wildcard ./qbRayTrace/*.cpp))

#Define the rebuildables
rebuildables = $(objects) $(linkTarget)

# Rule to actually perform the build

$(linkTarget): $(objects)
	g++ -g -o $(linkTarget) $(objects) $(LIBS) $(CFLAGS)

# Rule to create the object files
%.o: %.cpp
	g++ -o $@ -c $< $(CFLAGS)

.PHONEY:
clean:
	rm $(rebuildables)


