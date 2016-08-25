CC=g++
CFLAGS=-I. -g
DEPS=constants.h
ODIR=obj

_OBJ=Vertex.o Graph.o Edge.o
OBJ=$(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.cpp %.h $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ) main.cpp
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY=clean
clean:
	rm $(ODIR)/*.o main
