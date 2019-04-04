clean:
	del *.a*
	del *.exe
	del *.o*
	del *.lib

library: clean
	cl /c BinarySearchTree.cpp
	lib /out:BinarySearchTree.lib BinarySearchTree.obj
	del BinarySearchTree.obj

build: library
	cl /c test.cpp
	link test.obj BinarySearchTree.lib
	del test.obj
	test
