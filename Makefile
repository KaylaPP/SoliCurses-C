CC=clang
CFLAGS=-pthread -c -g
LDFLAGS=-lncurses
EXECUTABLE=SoliCurses-C.out
SRCDIR=./src

SOURCES=$(wildcard ${SRCDIR}/*.c)

OBJECTS=$(SOURCES:${SRCDIR}/%.c=%.o)

all : $(EXECUTABLE)

$(EXECUTABLE) : ${OBJECTS}
	$(CC) -o $@ $^ $(LDFLAGS)

%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean : 
	rm -rf *.o ${EXECUTABLE}

run :
	./$(EXECUTABLE)