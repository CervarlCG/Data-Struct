app : src/main.cpp postfix
	g++ -o bin/app src/main.cpp obj/postfix.o

postfix : src/examples/stack/postfix.cpp
	g++ -c src/examples/stack/postfix.cpp -o obj/postfix.o