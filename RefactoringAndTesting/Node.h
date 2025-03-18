/*
Name: Thu Ha
Course: CS 3505
Assigment: A5 - Refactoring and testing
Description: Practice GoogleTest and refactor the Trie class to make use of map
*/
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class Node {
public:
    /// @brief constructor
    Node();
    /// @brief Copy constructor
    Node(const Node& other);
    /// @brief Destructor
    ~Node();
    /// @brief Assignment operator
    Node& operator=(Node other);
    /// @brief check if the character is in the trie
    /// @param ch 
    /// @return 
    bool hasCharacter(char ch);
    /// @brief create a new node at this index
    /// @param ch 
    /// @return 
    Node* addCharacter(char ch);
    /// @brief get the node of the character
    /// @param ch 
    /// @return 
    Node* getChildNode(char ch);
    /// @brief get the end of word flag
    /// @return 
    bool getEndOfWordFlag();
    /// @brief set the end of word flag
    void setEndOfWordFlag();
    /// @brief get the children list
    /// @return 
    map<char, Node> getChildrenList();
private:
    map<char, Node> branches =  map<char,Node>();
    bool endOfWord;
};

#endif // NODE_H