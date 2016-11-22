lab21.exe : lab21.o MyClass.o
	g++ -Wall -g -o lab21.exe lab21.o MyClass.o

lab21.o : lab21.cpp lab21.h MyClass.cpp MyClass.h
	g++ -Wall -g -c lab21.cpp

MyClass.o : MyClass.cpp MyClass.h
	g++ -Wall -g -c MyClass.cpp

clean :
	rm *.o lab21.exe