gen:
	g++-9 -std=c++17 test.cpp -o EXECUTABLE

test:
	make gen
	./EXECUTABLE