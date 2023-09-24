all: compile link run

compile:
	g++ -c ../../src/*.cpp

link:
	g++ *.o -o program.out -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o

run:
	./program.out
