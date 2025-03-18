/*
Name: Thu Ha
Course: CS 3505
Assigment: A5 - Refactoring and Testing
Description: Practice GoogleTest and refactor the Trie class to make use of map
*/

#include "Node.h"

// Default constructor
Node::Node(): branches(), endOfWord(false){}

// Copy constructor
Node::Node(const Node& other)
{
    endOfWord = other.endOfWord;
    branches = other.branches;
}

// Destructor
Node::~Node() {}

// Assignment operator
Node &Node::operator=(Node other) 
{
    std::swap(endOfWord, other.endOfWord);
    std::swap(branches, other.branches);
    return *this;
}

//Checks if the current node has a child 
// corresponding to the given character.
bool Node::hasCharacter(char ch) 
{
    if (branches.count(ch) > 0)
    {
        return true;
    }
    return false;
}

// Adds a child node corresponding to the given character 
// if it doesn't already exist.
Node *Node::addCharacter(char ch) {
    branches[ch] = Node();
    return &branches[ch];
}

// Retrieves the child node corresponding to the given character.
Node *Node::getChildNode(char ch) 
{
    if (branches.count(ch) > 0)
    {
        return &branches[ch];
    }
    return new Node();
}

// Returns true if the node marks the end of a word in the Trie.
bool Node::getEndOfWordFlag() 
{
    return endOfWord;
}

// Marks the node as representing the end of a word by setting the 
// endOfWord flag to true.
void Node::setEndOfWordFlag() {
    endOfWord = true;
}

// Returns the array of pointers to the child nodes.
map<char, Node> Node::getChildrenList() {
    return branches;
}