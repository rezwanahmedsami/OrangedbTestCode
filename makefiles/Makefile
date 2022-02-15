

compilemain: object1.o object2.o object3.o
	g++ object1.o object2.o object3.o -o compilemain

object1.o: object1.cpp include1.h include2.h
	g++ -c -wall object1.cpp

object2.o: object2.cpp include1.h include2.h
	g++ -c -wall object2.cpp

object3.o: object3.cpp include1.h include2.h
	g++ -c -wall object3.cpp