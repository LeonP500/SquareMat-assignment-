# leonandsani@gmail.com

CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Werror


SRC_MAIN = SquareMat.cpp Main.cpp

SRC_TEST = SquareMat.cpp Test.cpp

Main: $(SRC_MAIN)
	$(CXX) $(CXXFLAGS) $(SRC_MAIN) -o Main

run: Main
	./Main

Test: $(SRC_TEST)
	$(CXX) $(CXXFLAGS) $(SRC_TEST) -o Test

test: Test
	./Test

valgrind: Main
	valgrind --leak-check=full ./Main

clean:
	rm -f Main Test *.o
