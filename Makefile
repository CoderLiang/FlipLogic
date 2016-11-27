all: flipLogicTests

flipLogicTests: flipLogicTests.cpp flipLogic.cpp
	g++ -Wall -Werror -pedantic -O2 \
	flipLogicTests.cpp flipLogic.cpp -o flipLogicTests

clean:
	rm -vf flipLogicTests


