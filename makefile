CC=g++
CFLAGS=-c -Wall -ggdb
LDFLAGS=
SOURCES=Project2Main.cpp HouseQueue.cpp HouseStack.cpp House.cpp 
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=project2

all: $(SOURCES) $(EXECUTABLE)
    
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
