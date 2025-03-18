/*
Name: Thu Ha
Course: CS 3505
Assigment: A4 - A Trie and Rule-of-Three
Description: Implement a trie to practice Rule of Three
and apply data structure in C++
*/

#include "Node.h"

/// @brief Default constructor
Node::Node() : endOfWord(false) {
    for (int i = 0; i < 26; ++i) {
        children[i] = nullptr;
    }
}

/// @brief Copy constructor
/// @param other 
Node::Node(const Node& other) : endOfWord(other.endOfWord) {
    for (int i = 0; i < 26; ++i) {
        if (other.children[i]) {
            children[i] = new Node(*other.children[i]);
        } else {
            children[i] = nullptr;
        }
    }
}

/// @brief Destructor
Node::~Node() {
    for (int i = 0; i < 26; ++i) {
        if (children[i]) {  // Check if the pointer is valid before deleting
            delete children[i];
            children[i] = nullptr;  // Set the pointer to nullptr after deleting
        }
    }
}

/// @brief Assignment operator
/// @param other 
/// @return 
Node& Node::operator=(const Node& other) {
    if (this != &other) {
        endOfWord = other.endOfWord;
        for (int i = 0; i < 26; ++i) {
            if (children[i]) {
                delete children[i];  // Free existing memory
            }
            if (other.children[i]) {
                children[i] = new Node(*other.children[i]);  // Deep copy
            } else {
                children[i] = nullptr;
            }
        }
    }
    return *this;
}

/// @brief Checks if the current node has a child 
/// corresponding to the given character.
/// @param ch 
/// @return 
bool Node::hasCharacter(char ch) const {
    if (ch < 'a' || ch > 'z') {
        return false; // Invalid character
    }
    int index = ch - 'a';
    return children[index] != nullptr;
}

/// @brief Adds a child node corresponding to the given character 
/// if it doesn't already exist.
/// @param ch 
/// @return 
Node* Node::addCharacter(char ch) {
    if (ch < 'a' || ch > 'z') {
        return nullptr; // Invalid character
    }
    int index = ch - 'a';
    if (!children[index]) {
        children[index] = new Node(); // Initialize the new node if it doesn't exist
    }
    return children[index];
}

/// @brief Retrieves the child node corresponding to the given character.
/// @param ch 
/// @return 
Node* Node::getChildNode(char ch) const {
    int index = ch - 'a';
    return children[index];
}

/// @brief Returns true if the node marks the end of a word in the Trie.
/// @return 
bool Node::getEndOfWordFlag() const {
    return endOfWord;
}

/// @brief Marks the node as representing the end of a word by setting the 
// endOfWord flag to true.
void Node::setEndOfWordFlag() {
    endOfWord = true;
}

/// @brief Returns the array of pointers to the child nodes.
/// @return 
Node** Node::getChildrenList() {
    return children;
}