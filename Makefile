app : src/main.cpp postfix
	g++ -o bin/app src/main.cpp

postfix : src/examples/stack/postfix.cpp
	g++ -c src/examples/stack/postfix.cpp -o obj/postfix.o

delimitator : src/examples/stack/delimitators.cpp
	g++ -c src/examples/stack/delimitators.cpp -o obj/delimitators.o

airplane : src/examples/queue/airplane.cpp
	g++ -c src/examples/queue/airplane.cpp -o obj/airplane.o