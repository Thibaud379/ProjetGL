ECHO = echo
GCC = g++ 
DEBUG =-g -Wall
CFLAGS=-I. -std=c++11 -c
EXE = AirWatcher.exe
CONTROL = Control.o AirWatcherIO.o
MODEL =  Sensor.o User.o PrivateUser.o Admin.o Provider.o Cleaner.o Coords.o
VIEW = Console.o
OBJS = $(MODEL:%.o=src/Model/%.o) $(CONTROL:%.o=src/Control/%.o) $(VUE:%.o=src/Vue/%.o) src/AirWatcher.o
LIBRAIRIES = -lm
.PHONY = clean

$(EXE) :  $(OBJS)
	$(GCC) -o $(EXE) $(OBJS) $(LIBRAIRIES)

%.o: %.cpp
	$(GCC) $(CFLAGS) $< -o $@

debug: CFLAGS += $(DEBUG)
debug: $(EXE)

opti: CFLAGS += -O3
opti: $(EXE)

clean:
	find . -name "*.o" -delete
