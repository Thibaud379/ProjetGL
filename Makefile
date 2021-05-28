GCC = g++ 
DEBUG =-g -Wall
CFLAGS=-I. -std=c++11 -c
MAIN = AirWatcher.exe
TEST = Test.exe
CONTROL = Control.o AirWatcherIO.o
MODEL =  Sensor.o User.o PrivateUser.o Admin.o Provider.o Cleaner.o Coords.o
VIEW = Console.o
OBJS = $(MODEL:%.o=src/Model/%.o) $(CONTROL:%.o=src/Control/%.o) $(VUE:%.o=src/Vue/%.o) 
LIBRAIRIES = -lm
.PHONY = clean

$(MAIN): echo $(OBJS) $(MAIN:%.exe=src/%.o)
	@echo "Link edition"
	$(GCC) -o $(MAIN) $(OBJS) $(MAIN:%.exe=src/%.o) $(LIBRAIRIES)

$(TEST): $(OBJS) $(TEST:%.exe=src/%.o)
	@echo "Link edition"
	$(GCC) -o $(TEST) $(OBJS) $(TEST:%.exe=src/%.o) $(LIBRAIRIES)

%.o: %.cpp
	$(GCC) $(CFLAGS) $< -o $@

debug: CFLAGS += $(DEBUG)
debug: $(MAIN)

opti: CFLAGS += -O3
opti: $(MAIN)

test: CFLAGS += $(DEBUG)
test: $(TEST)

echo:
	@echo "Compiling"
clean:
	@find . -name "*.o" -delete
