TARGET    = hirocc
OBJS      = main.o

CXX       = clang++
CXXFLAGS  = -std=c++20 -O3 -Wall
LDFLAGS   = -lm

${TARGET}: ${OBJS}
	${CXX} ${OBJS} -o $@

.PHONY: all clean

all: ${TARGET}

clean:
	${RM} ${TARGET} ${OBJS}
