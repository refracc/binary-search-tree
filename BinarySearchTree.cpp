#include "BinarySearchTree.h"

using namespace std;

// **Constructors **
BinarySearchTree::BinarySearchTree()
{

}


BinarySearchTree::BinarySearchTree(std::string word)
{
	Node *root = new Node;
	root->word = word;
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

void insert_helper(Node **root, std::string word)
{
	/*
	if the root node is a nullpointer
		insert at root
	if the thing is less than the root value
		put it in the left value
		call insert_helper on left
	else
		"" replace left w/ right
		call insert_helper on right.
	*/
}

// **Methods**
void BinarySearchTree::insert(std::string word)
{
}

bool BinarySearchTree::exists(std::string word) const
{
	return false; // change this to implement the method, returning true if word exists
}

/* 
 * Prints the words in a tree in alphabetical order.
 * Parameters: *root, a pointer to the root node of the tree to print.
 */
string inorder_helper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}
	else
	{
		return inorder_helper(root->left) + root->word + " " + inorder_helper(root->right);	
	}
}

/*
 * Prints the words in this BinarySearchTree in order.
 */
std::string BinarySearchTree::inorder() const
{
	string words = inorder_helper(root);
	if(words.length() > 1)
	{
		words.pop_back(); // Remove final space.
	}
	return words; 
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
