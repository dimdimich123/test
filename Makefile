.PHONY: all clean install uninstall

CC=g++ -Wall -Werror
PP=~/test/src/
SE=~/test/bin/

all: $(SE)start

$(SE)start: $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)geo.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o
	$(CC) -o $(SE)start $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)geo.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o

$(SE)SectTC.o: $(PP)SectTC.c
	$(CC) -c -o $(SE)SectTC.o $(PP)SectTC.c
$(SE)SectCC.o: $(PP)SectCC.c
	$(CC) -c -o $(SE)SectCC.o $(PP)SectCC.c
$(SE)SectTT.o: $(PP)SectTT.c
	$(CC) -c -o $(SE)SectTT.o $(PP)SectTT.c
$(SE)SectPP.o: $(PP)SectPP.c
	$(CC) -c -o $(SE)SectPP.o $(PP)SectPP.c
$(SE)SectPT.o: $(PP)SectPT.c
	$(CC) -c -o $(SE)SectPT.o $(PP)SectPT.c
$(SE)SectPC.o: $(PP)SectPC.c
	$(CC) -c -o $(SE)SectPC.o $(PP)SectPC.c
$(SE)geo.o: $(PP)geo.c
	$(CC) -c -o $(SE)geo.o $(PP)geo.c
$(SE)Str.o: $(PP)Str.c
	$(CC) -c -o $(SE)Str.o $(PP)Str.c
$(SE)circle.o: $(PP)circle.c
	$(CC) -c -o $(SE)circle.o $(PP)circle.c
$(SE)triangle.o: $(PP)triangle.c
	$(CC) -c -o $(SE)triangle.o $(PP)triangle.c
$(SE)polygon.o: $(PP)polygon.c
	$(CC) -c -o $(SE)polygon.o $(PP)polygon.c

clean:
	rm -rf $(SE)start $(SE)*.o
