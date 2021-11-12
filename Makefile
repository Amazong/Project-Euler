# LIBS  = -lkernel32 -luser32 -lgdi32 -lopengl32
CC=gcc
CPP=g++

C_FLAGS = -Wall
CPP_FLAGS = -std=c++11 -Wall

SOURCES_C=$(shell find . -type f -name '*.c')
SOURCES_CPP=$(shell find . -type f -name '*.cpp')

TARGETS_C=$(patsubst %.c,%.exe,$(SOURCES_C))
TARGETS_CPP=$(patsubst %.cpp,%.exe,$(SOURCES_CPP))

all: $(TARGETS_C) $(TARGETS_CPP)

$(TARGETS_C): %.exe: %.c
	$(CC) $< $(C_FLAGS) -o $@

$(TARGETS_CPP): %.exe: %.cpp
	$(CPP) $< $(CPP_FLAGS) -o $@

clean:
	rm -f $(TARGETS_C) $(TARGETS_CPP)