/*
Name: Thu Ha
Course: CS 3505
Assigment: A4 - A Trie and Rule-of-Three
Description: Test class for Trie.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Trie.h"

using namespace std;

void testRuleOfThree(Trie& originalTrie) {
    Trie firstTrie;
    firstTrie.addWord("aba");
    firstTrie.addWord("abb");
    firstTrie.addWord("abc");
    firstTrie.addWord("apple");

    // Testing the Rule of Three
    Trie otherTrie = firstTrie; // Copy constructor
    firstTrie.addWord("ant"); // This should not appear in otherTrie

    cout << "Checking if 'ant' is in otherTrie after adding to firstTrie (should be no): ";
    cout << (otherTrie.isWord("ant") ? "Yes" : "No") << endl;

    Trie anotherTrie; // Assignment operator
    anotherTrie = firstTrie; // Assign from firstTrie which includes 'ant'
    firstTrie.addWord("buy"); // Add 'buy' which should not affect anotherTrie

    cout << "Checking if 'buy' is in anotherTrie after adding to firstTrie (should be no): ";
    cout << (anotherTrie.isWord("buy") ? "Yes" : "No") << endl;
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <word file> <query file>\n";
        return 1;
    }

    Trie trie;
    string line;

    ifstream myWordFile(argv[1]);
    if (!myWordFile.is_open()) {
        cerr << "Unable to open word file: " << argv[1] << endl;
        return 1;
    }

    while (getline(myWordFile, line)) {
        trie.addWord(line);
    }
    myWordFile.close();

    ifstream myQueryFile(argv[2]);
    if (!myQueryFile.is_open()) {
        cerr << "Unable to open query file: " << argv[2] << endl;
        return 1;
    }

    while (getline(myQueryFile, line)) {
        cout << "Checking text: " << line << endl;
        if (trie.isWord(line)) {
            cout << "Word found" << endl;
        } else {
            cout << "Word not found" << endl;
        }

        vector<string> results = trie.allWordsStartingWithPrefix(line); // Changed to the new method
        cout << "Words starting with '" << line << "': ";
        for (const auto &word : results) {
            cout << word << " ";
        }
        cout << endl;
    }
    myQueryFile.close();

    testRuleOfThree(trie); // Test Rule of Three

    return 0;
}