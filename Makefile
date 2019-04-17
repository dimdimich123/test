.PHONY: all clean install uninstall

CC=g++ -Wall -Werror
PP=~/test/src/
SE=~/test/bin/

all: start

start: $(SE)geo.o $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o
	g++ $(SE)geo.o $(SE)polygon.o $(SE)triangle.o $(SE)circle.o $(SE)Str.o $(SE)SectPC.o $(SE)SectPT.o $(SE)SectPP.o $(SE)SectTT.o $(SE)SectCC.o $(SE)SectTC.o -o start

$(SE)SectTC.o: $(PP)SectTC.cpp
	$(CC) -c -o $(SE)SectTC.o $(PP)SectTC.cpp
$(SE)SectCC.o: $(PP)SectCC.cpp
	$(CC) -c -o $(SE)SectCC.o $(PP)SectCC.cpp
$(SE)SectTT.o: $(PP)SectTT.cpp
	$(CC) -c -o $(SE)SectTT.o $(PP)SectTT.cpp
$(SE)SectPP.o: $(PP)SectPP.cpp
	$(CC) -c -o $(SE)SectPP.o $(PP)SectPP.cpp
$(SE)SectPT.o: $(PP)SectPT.cpp
	$(CC) -c -o $(SE)SectPT.o $(PP)SectPT.cpp
$(SE)SectPC.o: $(PP)SectPC.cpp
	$(CC) -c -o $(SE)SectPC.o $(PP)SectPC.cpp
$(SE)geo.o: $(PP)geo.cpp
	$(CC) -c -o $(SE)geo.o $(PP)geo.cpp
$(SE)Str.o: $(PP)Str.cpp
	$(CC) -c -o $(SE)Str.o $(PP)Str.cpp
$(SE)circle.o: $(PP)circle.cpp
	$(CC) -c -o $(SE)circle.o $(PP)circle.cpp
$(SE)triangle.o: $(PP)triangle.cpp
	$(CC) -c -o $(SE)triangle.o $(PP)triangle.cpp
$(SE)polygon.o: $(PP)polygon.cpp
	$(CC) -c -o $(SE)polygon.o $(PP)polygon.cpp

clean:
	rm -rf start $(SE)*.o
