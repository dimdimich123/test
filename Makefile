.PHONY: all clean install uninstall

CC=g++ -Wall -Werror -c -o
PP=~/test/src/
SE=~/test/bin/

all: $(SE)start

$(SE)start: $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)geo.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o
	g++ -Wall -Werror -o $(SE)start $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)geo.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o

$(SE)polygon.o: $(PP)polygon.c
	$(CC) $(SE)polygon.o $(PP)polygon.c
$(SE)triangle.o: $(PP)triangle.c
	$(CC) $(SE)triangle.o $(PP)triangle.c
$(SE)circle.o: $(PP)circle.c
	$(CC) $(SE)circle.o $(PP)circle.c
$(SE)Str.o: $(PP)Str.c
	$(CC) $(SE)Str.o $(PP)Str.c
$(SE)geo.o: $(PP)geo.c
	$(CC) $(SE)geo.o $(PP)geo.c
$(SE)SectPC.o: $(PP)SectPC.c
	$(CC) $(SE)SectPC.o $(PP)SectPC.c
$(SE)SectPP.o: $(PP)SectPP.c
	$(CC) $(SE)SectPP.o $(PP)SectPP.c
$(SE)SectPT.o: $(PP)SectPT.c
	$(CC) $(SE)SectPT.o $(PP)SectPT.c
$(SE)SectCC.o: $(PP)SectCC.c
	$(CC) $(SE)SectCC.o $(PP)SectCC.c
$(SE)SectTT.o: $(PP)SectTT.c
	$(CC) $(SE)SectTT.o $(PP)SectTT.c
$(SE)SectTC.o: $(PP)SectTC.c
	$(CC) $(SE)SectTC.o $(PP)SectTC.c
clean:
	rm -rf $(SE)start $(SE)*.o
