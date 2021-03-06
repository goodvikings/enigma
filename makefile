# Makefile generated by genmake.pl
# Written by Ramo

CC=g++
BUILD=build
DIST=dist
CCFLAGS=-c -g -Wall --std=c++11 #-DDEBUG
LDFLAGS=-o $(DIST)/prog 

all:	$(DIST)/prog
$(DIST)/prog:	$(BUILD) $(DIST) $(BUILD)/rotor.o $(BUILD)/main.o $(BUILD)/reflector.o $(BUILD)/plug.o $(BUILD)/enigma.o 
	$(CC) $(BUILD)/*.o $(LDFLAGS)
$(BUILD)/rotor.o:	rotor.cpp rotor.h
	$(CC) rotor.cpp $(CCFLAGS) -o $(BUILD)/rotor.o
$(BUILD)/main.o:	main.cpp enigma.h plug.h reflector.h rotor.h
	$(CC) main.cpp $(CCFLAGS) -o $(BUILD)/main.o
$(BUILD)/reflector.o:	reflector.cpp reflector.h
	$(CC) reflector.cpp $(CCFLAGS) -o $(BUILD)/reflector.o
$(BUILD)/plug.o:	plug.cpp plug.h
	$(CC) plug.cpp $(CCFLAGS) -o $(BUILD)/plug.o
$(BUILD)/enigma.o:	enigma.cpp enigma.h
	$(CC) enigma.cpp $(CCFLAGS) -o $(BUILD)/enigma.o
$(BUILD):
	@mkdir $(BUILD)
$(DIST):
	@mkdir $(DIST)
clean:
	rm -rf $(BUILD) $(DIST)
install:
	install $(DIST)/prog /usr/local/bin/
love:
	@echo Not war
