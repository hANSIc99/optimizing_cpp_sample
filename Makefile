#gcc flags:
# -c assemble but do not link
#  # -g include debug information
# -o output
#  # -s make stripped libray

# uncomment the last part in line 9 to compile with debug symbold 

CFLAGS =-Wall -Werror -std=c++11 #-g 


all: main.o
	c++ -o memory_sample main.o $(CFLAGS)

main.o: main.cpp MyType.h MyObject.h
	c++ -c main.cpp $(CFLAGS)

.PHONY: clean
clean:
	rm *.o
