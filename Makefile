.PHONY: all clean install uninstall

CC=g++ -Wall -Werror
PP=~/test/src/
SE=

all: start

$(SE)start: polygon.o triangle.o circle.o Str.o geo.o SectPC.o SectPT.o SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o
	$(CC) -o $(SE)start $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)geo.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o

$(SE)polygon.o: $(PP)polygon.c
	$(CC) -c -o $(SE)polygon.o $(PP)polygon.c
$(SE)triangle.o: $(PP)triangle.c
	$(CC) -c -o $(SE)triangle.o $(PP)triangle.c
$(SE)circle.o: $(PP)circle.c
	$(CC) -c -o $(SE)circle.o $(PP)circle.c
$(SE)Str.o: $(PP)Str.c
	$(CC) -c -o $(SE)Str.o $(PP)Str.c
$(SE)geo.o: $(PP)geo.c
	$(CC) -c -o $(SE)geo.o $(PP)geo.c
$(SE)SectPC.o: $(PP)SectPC.c
	$(CC) -c -o $(SE)SectPC.o $(PP)SectPC.c
$(SE)SectPP.o: $(PP)SectPP.c
	$(CC) -c -o $(SE)SectPP.o $(PP)SectPP.c
$(SE)SectPT.o: $(PP)SectPT.c
	$(CC) -c -o $(SE)SectPT.o $(PP)SectPT.c
$(SE)SectCC.o: $(PP)SectCC.c
	$(CC) -c -o $(SE)SectCC.o $(PP)SectCC.c
$(SE)SectTT.o: $(PP)SectTT.c
	$(CC) -c -o $(SE)SectTT.o $(PP)SectTT.c
$(SE)SectTC.o: $(PP)SectTC.c
	$(CC) -c -o $(SE)SectTC.o $(PP)SectTC.c
clean:
	rm -rf $(SE)start $(SE)*.o
