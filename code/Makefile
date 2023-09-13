all: compile link run

compile:
	g++ -c src/*.cpp
	mv *.o build

link:
	g++ build/*.o -o program -lsfml-graphics -lsfml-window -lsfml-system
	mv program build

clean:
	rm build/*.o

run:
	./build/program
