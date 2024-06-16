# Tal Malka 315734616 Tal.coder@gmail.com
#!make -f

CXX=clang++
CXXFLAGS=-std=c++11 -Werror
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

SOURCESDemo=catan.cpp board.cpp player.cpp
OBJECTSDemo=$(subst .cpp,.o,$(SOURCESDemo))

SOURCESTest=catan.cpp board.cpp player.cpp
OBJECTSTest=$(subst .cpp,.o,$(SOURCESTest))

run: demo
	./$^

demo: Demo.o $(OBJECTSDemo)
	$(CXX) $(CXXFLAGS) $^ -o demo

test: Test.o $(OBJECTSTest)
	$(CXX) $(CXXFLAGS) $^ -o test

main: main.o $(OBJECTSTest)
	clear
	$(CXX) $(CXXFLAGS) $^ -o main
	./main

tidy:
	clang-tidy $(SOURCES) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=-* --

valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o test demo
remake:
	clear
	make clean
	make