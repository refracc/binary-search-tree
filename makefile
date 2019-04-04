clean:
	rm -rf *.*o*
	rm -rf *.exe
	rm -rf *.a*
	
build: clean
	clang++ -shared -undefined dynamic_lookup -std=c++11 -o bst.so BinarySearchTree.cpp
	clang++ test.cpp bst.so -std=c++11 -o test
	
exe:
	./test


