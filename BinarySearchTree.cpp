#include "BinarySearchTree.h"

// **Constructors **
BinarySearchTree::BinarySearchTree()
{

}


BinarySearchTree::BinarySearchTree(std::string word)
{

}


BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{

}


BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{

}
//destructor
BinarySearchTree::~BinarySearchTree()
{

}

// **Methods**
void BinarySearchTree::insert(std::string word)
{

}

bool BinarySearchTree::exists(std::string word) const
{
	return false; // change this to implement the method, returning true if word exists
}


std::string BinarySearchTree::inorder() const
{
	return std::string(""); // change this to return a string representation of the words
	// in the tree inorder.
}


std::string BinarySearchTree::preorder() const
{
	return std::string(""); // change this to return a string representation of the words
	// in the tree preorder.
}


std::string BinarySearchTree::postorder() const
{
	return std::string(""); // change this to return a string representation of the words
	// in the tree postorder.
}
    
// **Operator overloads**
    

BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	return *this; // returns a reference to the modified tree
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	return *this;
}


