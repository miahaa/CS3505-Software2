/*
Name: Thu Ha
Course: CS 3505
Assigment: A4 - A Trie and Rule-of-Three
Description: Implement a trie to practice Rule of Three
and apply data structure in C++
*/

#include "Trie.h"

/// @brief default constructor
Trie::Trie() : root() {}

/// @brief default destructor
Trie::~Trie() {
    // No need to explicitly delete `root`, it is managed automatically
}

/// @brief copy constructor
Trie::Trie(const Trie& other) : root(other.root) {
    // Rely on the Node copy constructor to handle deep copying
}

/// @brief Assignment operator
/// @param other 
/// @return 
Trie& Trie::operator=(const Trie& other) {
    if (this != &other) {
        root = other.root; // Node assignment operator handles deep copy
    }
    return *this;
}

/// @brief Add a word to the trie
/// @param word 
void Trie::addWord(const string& word) {
    Node* currNode = &root;
    for (char ch : word) {
        if (!currNode) {
            cerr << "Error: Null node encountered in addWord.\n";
            return;
        }
        currNode = currNode->addCharacter(ch);
    }
    if (currNode) {
        currNode->setEndOfWordFlag();
    }
}

/// @brief check to see if the string is a word in the trie 
/// @param word 
/// @return 
bool Trie::isWord(const string& word) {
    Node* currNode = &root;
    for (char ch : word) {
        if (!currNode->hasCharacter(ch)) {
            return false;
        }
        currNode = currNode->getChildNode(ch);
    }
    return currNode->getEndOfWordFlag();
}

/// @brief search for all words start with the prefix
/// if prefix is an empty string return all words in the trie
/// @param prefix 
/// @return 
vector<string> Trie::allWordsStartingWithPrefix(const string& prefix) {
    vector<string> wordList;
    Node* currNode = &root;

    for (char ch : prefix) {
        if (!currNode->hasCharacter(ch)) {
            return {}; // Prefix not found
        }
        currNode = currNode->getChildNode(ch);
    }
    allWordsByEmptyPrefix(prefix, &wordList, prefix, currNode);
    return wordList;
}

/// @brief a recursive hepler method to find all words start with the empty prefix
/// @param prefix 
/// @param wordList 
/// @param word 
/// @param currNode 
void Trie::allWordsByEmptyPrefix(const string& prefix, vector<string>* wordList, const string& word, Node* currNode) {
    if (currNode->getEndOfWordFlag()) {
        wordList->push_back(word);
    }
    for (int i = 0; i < 26; ++i) {
        Node* nextNode = currNode->getChildrenList()[i];
        if (nextNode) {
            char ch = 'a' + i;
            allWordsByEmptyPrefix(prefix, wordList, word + ch, nextNode);
        }
    }
}