app : src/main.cpp postfix delimitator
	g++ -o bin/app src/main.cpp obj/delimitators.o

postfix : src/examples/stack/postfix.cpp
	g++ -c src/examples/stack/postfix.cpp -o obj/postfix.o

delimitator : src/examples/stack/delimitators.cpp
	g++ -c src/examples/stack/delimitators.cpp -o obj/delimitators.o