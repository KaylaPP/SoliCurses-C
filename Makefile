CC=clang
CFLAGS=-pthread -c -g
LDFLAGS=-lncurses
EXECUTABLE=SoliCurses-C.out
OBJDIR=./obj
SRCDIR=./src

SOURCES=$(wildcard ${SRCDIR}/*.c)

OBJECTS=$(SOURCES:${SRCDIR}/%.c=$(OBJDIR)/%.o)

all : $(EXECUTABLE)
	rm -rf $(OBJDIR)
	mkdir $(OBJDIR)

$(EXECUTABLE) : ${OBJECTS}
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -o $@ $<

clean : 
	rm -rf $(OBJDIR)/*.o ${EXECUTABLE}

run :
	./$(EXECUTABLE)