/*
Name: Thu Ha
Course: CS 3505
Assigment: A5 - Refactoring and testing
Description: Practice GoogleTest and refactor the Trie class to make use of map
*/

#ifndef TRIE_H
#define TRIE_H

#include "Node.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Trie {
    Node root;
public: 
    /// @brief Default constructor
    Trie();
    /// @brief Destructor
    ~Trie();
    /// @brief Copy constructor
    Trie(const Trie& other);
    /// @brief Assignment operator
    /// @return 
    Trie& operator=(Trie other);
    /// @brief Add word to the trie
    /// @param word 
    void addWord(string word);
    /// @brief Check if the string is a word in the trie
    /// @param word 
    /// @return 
    bool isWord(string word);
    /// @brief Search for all words start with prefix
    /// @param prefix 
    /// @return 
    vector<string> allWordsStartingWithPrefix(string prefix);
private:
    /// @brief find all words with empty prefix
    /// @param prefix 
    /// @param wordList 
    /// @param word 
    /// @param currNode 
    void allWordsByEmptyPrefix(string prefix, vector<string>* wordList, string word, Node* currNode);

    /// @brief Find all words by prefix
    /// @param prefix 
    /// @param wordList 
    /// @param word 
    /// @param currNode 
    void findAllWordsByPrefix(string prefix, vector<string>* wordList, string word, Node* currNode);
};
#endif