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

	if(*root == nullptr)
	{
		*root = new Node;
		*(root->word) = word;
		*(root->left) = nullptr;
		*(root->right) = nullptr;
	} else if(word < *(root->word)){
		if(*(root->left) != nullptr) insert_helper(&*(root->left), word);
	} else if (word > *(root->word)){
		if(*(root->right) != nullptr) insert_helper(&*(root->right), word);
	}
}

// **Methods**
void BinarySearchTree::insert(std::string word)
{
	Node **n = new Node;
	
	insert_helper(n, word);
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
