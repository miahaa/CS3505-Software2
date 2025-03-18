/*
Name: Thu Ha
Course: CS 3505
Assigment: A5 - Refactoring and testing
Description: Practice GoogleTest and refactor the Trie class to make use of map
*/

#include "Trie.h"
#include <map>

// default constructor
Trie::Trie() 
{
    Trie::root = Node();
}

// default destructor
Trie::~Trie() {}

// copy constructor
Trie::Trie(const Trie& other) {
    root = other.root;
}

// Assignment operator
Trie& Trie::operator=(Trie other) {
    std::swap(root, other.root);
    return *this;
}

// Add a word to the trie
void Trie::addWord(string word) {
    Node* currNode = &root;
    for (unsigned int i = 0; i < word.size(); i++)
    {
        // Add a new character node if it does not exist.
        if (!(currNode->hasCharacter(word[i])))
            currNode = currNode->addCharacter(word[i]);
        else
            // Move to the child node corresponding to the character.   
            currNode = currNode->getChildNode(word[i]);

        // Mark the node as the end of a word on the last character.
        if (i == (word.size() - 1))
            currNode->setEndOfWordFlag();
    }
}

// check to see if the string is a word in the trie 
bool Trie::isWord(string word) {
    Node* currNode = &root;
    if (word.size() == 0)
        return false;
    for (unsigned int i = 0; i < word.size(); i++)
    {
        // Move to the next node only if the character exists.
        if (currNode->hasCharacter(word[i]))
        {
            currNode = currNode->getChildNode(word[i]);

            // Check the flag if this is the last character.
            if (i == (word.size() - 1))
            {
                return currNode->getEndOfWordFlag();
            }
        }
    }
    return false;
}

// search for all words start with the prefix
// if prefix is an empty string return all words in the trie
vector<string> Trie::allWordsStartingWithPrefix(string prefix) {
    vector<string> wordList;
    if (prefix == "")
    {
        allWordsByEmptyPrefix(prefix, &wordList, "", &root);
    }
    else
    {
        // Validate prefix characters.
        for (unsigned int i = 0; i < prefix.size(); i++)
        {
            if (prefix[i] < 'a' || prefix[i] > 'z')
                return vector<string>();
        }

        // Retrieve words starting with the given non-empty prefix.
        findAllWordsByPrefix(prefix, &wordList, "", &root);
    }
    return wordList;
}

// a recursive hepler method to find all words start with the empty prefix
void Trie::allWordsByEmptyPrefix(string prefix, vector<string>* wordList, string word, Node* currNode) {
    for (auto const &node : currNode->getChildrenList())
    {
        char currChar = node.first;

        string newWord = word + currChar;

        Node *newNode = new Node(node.second);

        if ((*newNode).getEndOfWordFlag())
        {
            wordList->push_back(newWord);
        }

        // Recursion
        allWordsByEmptyPrefix(prefix, wordList, newWord, newNode);
    }
}

// a recursive hepler method to search for all words start with the prefix
void Trie::findAllWordsByPrefix(string prefix, vector<string> *wordList, string word, Node *currNode)
{
    if (currNode->hasCharacter(prefix[0]))
    {
        string newWord = word + prefix[0];

        currNode = currNode->getChildNode(prefix[0]);

         // Continue searching the rest of the prefix.
        findAllWordsByPrefix(prefix.substr(1), wordList, newWord, currNode);
    }
    else
    {
        // If the end of the word is reached and no more prefix to search.
        if (currNode->getEndOfWordFlag())
        {
            wordList->push_back(word);
        }
        // If prefix is not empty, terminate the search.
        if (prefix != "") 
        {
            return;   
        }  
        // Otherwise, search for all words starting with an empty prefix.      
        else allWordsByEmptyPrefix(prefix, wordList, word, currNode);
    }
}