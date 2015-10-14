# The c++ compiler
CC = g++

# Compiler flags:
CFLAGS = -c -std=c++0x -pthread

all: timer

timer: main.o timer.o playsound.o stringUtil.o
	   $(CC) -o  timer timer.o main.o playsound.o stringUtil.o -I /Library/Frameworks/SDL2.Framework -I /Library/Frameworks/SDL2_mixer.Framework -framework SDL2 -framework SDL2_mixer
timer.o:
	$(CC) $(CFLAGS) -c timer.cpp

main.o:
	$(CC) $(CFLAGS) -c main.cpp

playsound.o:
	$(CC) $(CFLAGS) -c playsound.cpp 

stringUtil.o:
	$(CC) $(CFLAGS) -c stringUtil.cpp

clean:
	$(RM) *.o timer

SUFFIXES = .cpp