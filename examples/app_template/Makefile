all: compile link

compile:
	g++ -c *.cpp

link:
	g++ *.o -o program -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm *.o

run:
	./program
