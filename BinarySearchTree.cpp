/*
	Author: Stewart A.
	Matric: 40345422
	Last Modified: 05.04.2019

*/

/*
	This is a file to create a binary search tree and is dependant on the node.h and BinarySearchTree.h files.
	This is also being used in conjunciton with the test.cpp file. Please see the README.TXT for more information.
*/

#include "BinarySearchTree.h"

using namespace std;

// insert_helper is used for the single word constructor too. Hence why it's at the top of the file.
// I realise I could've used a function prototype, but this worked just as well.

// Takes in a pointer to a pointer to the root node, and the word being passed in.
void insert_helper(Node **root, std::string word)
{

	if(*root == nullptr) // Where there isn't a word
	{
		*root = new Node; // Creates a new node
		(*root)->word = word; // Have the root be set to the word
		(*root)->left = (*root)->right = nullptr; // Set left & right nodes to null pointer
	} else if(word < (*root)->word) // If the word is less than the current value
	{
		insert_helper(&(*root)->left, word); // Set the word in the left node to the word being passed in.
	} else
	{
		insert_helper(&(*root)->right, word); // Set the word in the right node to the word being passed in.
	}
}

// Helper function to copy a tree over to another tree.
// Takes in a pointer to a node. Not modifying the tree.
Node* cpy_help(const Node* current)
{
	if (current != nullptr)
	{
		Node* neW = new Node; // "new" is a keyword.
		neW->word = current->word;
		neW->left = cpy_help(current->left);
		neW->right = cpy_help(current->right);

		return neW;
		delete neW;
	}else
	{
		return NULL;
	}
}


// **Constructors **
BinarySearchTree::BinarySearchTree()
{
	// Empty constructor
}

// Adds in a single word to the tree.
BinarySearchTree::BinarySearchTree(std::string word)
{
	insert(word); // Use the insert function to add the new word
}

 // Takes in a tree to copy over.
BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	root = cpy_help(rhs.root);

}


BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	for(int i = 0; i < words.size(); i++) // Iterate over the vector of words.
	{
		insert(words[i]); // Put the current word into the tree.
	}
}

// This is a function to remove the tree
// The function name "remove" didn't work for me at all.. This is why it's called "rem".
// Takes in a pointer to a node.
void rem(Node* tree)
{
	if (tree != nullptr)
	{
		rem(tree->left);
		rem(tree->right);

		delete tree;
	}
}

//destructor
BinarySearchTree::~BinarySearchTree()
{
	// Activate the removing function on the root node.
	rem(root);
}


// **Methods**
void BinarySearchTree::insert(std::string word)
{
	insert_helper(&root, word); // Use the helper function to pass the word in.
}

bool BinarySearchTree::exists(std::string word) const
{
	Node *foo = root; // This is just a temporary variable.

	while (foo != nullptr)
	{
		if (foo->word == word) // If the node's word matches the word being passed in
		{
			return true;
		} else if (word > foo->word) // If the word is greater than the current node's
		{
			foo = foo->right; // Change to the right node.
		} else if (word < foo->word) // If the word is less than the current node's
		{
			foo = foo->left; // Change to the left node.
		}
	}

	delete foo;
	return false;
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
		return inorder_helper(root->left) + root->word + " " + inorder_helper(root->right);	// Prints left word, root word, then right word.
	}
}

string preorder_helper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}else
	{
		return root->word + " " + preorder_helper(root->left) + preorder_helper(root->right); // Prints root word, left word, then right word.
	}
}

string postorder_helper(Node *root)
{
	if(root == nullptr)
	{
		return "";
	}else
	{
		return postorder_helper(root->left) + postorder_helper(root->right) + root->word + " "; // Prints left word, right word, then root word.
	}
}

/*
 * Prints the words in this BinarySearchTree in order.
 */
std::string BinarySearchTree::inorder() const
{
	string words = inorder_helper(root);
	if(words.length() > 0) // Check it's not empty.
	{
		words.pop_back(); // Remove final space from the string.
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
	// Save for both inorder & preorder functions. See comments.
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
	insert(word); // Adds the word that is being used in conjunction with the overloaded operator.
	return *this; // Returns a reference to the modified tree
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	if (this != &rhs)
	{
		rem(this->root); // Delete and free up the current node from memory.
		this->root = cpy_help(rhs.root); // The new root node is equal to the copied tree's root.
		return *this; // Returns a reference to the modified tree.
	}
	else {
		return *this; // Returns a reference to the modified tree.
	}
}
