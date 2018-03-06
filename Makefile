run:compile
	clear
	./program

compile:clean
	g++ src/*.cpp -o program

clean:
	rm -f program
	clear

cleanSave:
	rm -f saveFile.txt
	clear
