/*
Name: Thu Ha
Course: CS 3505
Assigment: A4 - A Trie and Rule-of-Three
Description: Implement a trie to practice Rule of Three
and apply data structure in C++
*/

#ifndef TRIE_H
#define TRIE_H

#include "Node.h"
#include <iostream>
#include <vector>
using namespace std;

class Trie {
    Node root;
public: 
    /// @brief Default constructor
    Trie();
    /// @brief Destructor
    ~Trie();
    /// @brief Copy constructor
    /// @param other 
    Trie(const Trie& other);
    /// @brief Assignment operator
    /// @param other 
    /// @return 
    Trie& operator=(const Trie& other);
    /// @brief Add word to the trie
    /// @param word 
    void addWord(const string& word);
    /// @brief Check if the string is a word in the trie
    /// @param word 
    /// @return 
    bool isWord(const string& word);
    /// @brief Search for all words start with prefix
    /// @param prefix 
    /// @return 
    vector<string> allWordsStartingWithPrefix(const string& prefix);
private:
    /// @brief find all words with empty prefix
    /// @param prefix 
    /// @param wordList 
    /// @param word 
    /// @param currNode 
    void allWordsByEmptyPrefix(const string& prefix, vector<string>* wordList, const string& word, Node* currNode);
};
#endif