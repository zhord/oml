#compiler
CC=g++

#compiler flags:
#  -g		adds debugging information to the executable file
#  -Wall	turn on compiler warnings
#  -std=c++11	turn on support c++11
CFLAGS=-c -Wall -std=c++11

#linker flags:
LDFLAGS=

#directories containing header files
INCLUDES=-I../_src/agent/

#source files
SRCS=../_src/agent/agent.cpp ../_src/agent/config/base_config.cpp

#object files
OBJS=$(SRCS:.cpp=.o)

#executable file
MAIN=oml

all: $(MAIN)
	@echo

$(MAIN): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm $(OBJS) $(MAIN)
