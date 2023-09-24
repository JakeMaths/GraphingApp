all: compile link run

compile:
	g++ -c *.cpp
	mv *.o ../build

link:
	g++ ../build/*.o -o program.out -lsfml-graphics -lsfml-window -lsfml-system
	mv program.out ../build

clean:
	rm ../build/*.o

run:
	../build/program.out
