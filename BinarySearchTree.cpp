#include "BinarySearchTree.h"

using namespace std;

void insert_helper(Node **root, std::string word)
{

	if(*root == nullptr)
	{
		*root = new Node;
		(*root)->word = word;
		(*root)->left = (*root)->right = nullptr;
	} else if(word < (*root)->word)
	{
		insert_helper(&(*root)->left, word);
	} else
	{
		insert_helper(&(*root)->right, word);
	}
}


// **Constructors **
BinarySearchTree::BinarySearchTree()
{

}


BinarySearchTree::BinarySearchTree(std::string word)
{
	insert_helper(&root, word);
}


BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{

}


BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for(int i = 0; i < words.size(); i++)
	{
		insert(words[i]);
	}
}
//destructor
BinarySearchTree::~BinarySearchTree()
{

}


// **Methods**
void BinarySearchTree::insert(std::string word)
{
	insert_helper(&root, word);
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

string preorder_helper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}else
	{
		return root->word + " " + preorder_helper(root->left) + preorder_helper(root->right);
	}  
}

string postorder_helper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}else
	{
		return postorder_helper(root->left) + postorder_helper(root->right) + root->word + " ";
	}
}

/*
 * Prints the words in this BinarySearchTree in order.
 */
std::string BinarySearchTree::inorder() const
{
	string words = inorder_helper(root);
	if(words.length() > 0)
	{
		words.pop_back(); // Remove final space.
	}
	return words; 
}


std::string BinarySearchTree::preorder() const
{
	// Creates a string using the function
	string words = preorder_helper(root);
	if(words.length() > 0) // If the string is longer than one
	{
		words.pop_back(); // Remove the space from the back of the string.
	}
	return words;
}


std::string BinarySearchTree::postorder() const
{
	string words = postorder_helper(root);
	if(words.length() > 0)
	{
		words.pop_back();
	}
	return words;
}
    
// **Operator overloads**
    

BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	insert(word);
	return *this; // returns a reference to the modified tree
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	return *this;
}
