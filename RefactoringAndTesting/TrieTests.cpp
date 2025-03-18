/*
Author: Thu Ha
Course: CS 3505
Github: https://github.com/miahaa
Repo: https://github.com/University-of-Utah-CS3505/a5-refactor-and-test-miahaa.git
Assignment: A5 - Testing and refactoring
Description: Unit tests for Trie class
*/
#include <gtest/gtest.h>
#include "Trie.h"

// Tests basic functionality of adding and verifying a single word in the Trie.
TEST(TrieTest, BasicTest) {
    Trie trie;
    trie.addWord("Thu");
    EXPECT_TRUE(trie.isWord("Thu"));
    EXPECT_FALSE(trie.isWord("Ha"));
}

// Test edge case empty string
TEST(TrieTest, EmptyString) {
    Trie trie;
    trie.addWord("");  // Testing empty string
    EXPECT_FALSE(trie.isWord(""));  
}

// Test edge case adding duplicate words
TEST(TrieTest, DuplicateWords) {
    Trie trie;
    trie.addWord("thu");
    trie.addWord("thu");

    EXPECT_TRUE(trie.isWord("thu"));
}

// Test words with common prefix
TEST(TrieTest, WordsWithCommonPrefix) {
    Trie trie;
    trie.addWord("cat");
    trie.addWord("cater");
    trie.addWord("cattle");

    // Check each word is individually recognized.
    EXPECT_TRUE(trie.isWord("cat"));
    EXPECT_TRUE(trie.isWord("cater"));
    EXPECT_TRUE(trie.isWord("cattle"));
    EXPECT_FALSE(trie.isWord("ca"));
    EXPECT_FALSE(trie.isWord("cats"));
}

// Test copying a trie
TEST(TrieTest, CopyTrie) {
    Trie trie;
    trie.addWord("thu");
    trie.addWord("ha");

    // Copy constructor
    Trie copiedTrie = trie;
    EXPECT_TRUE(copiedTrie.isWord("thu"));
    EXPECT_TRUE(copiedTrie.isWord("ha"));
}

// Test assignment operator for the trie 
TEST(TrieTest, AssignmentOperator) {
    Trie trie;
    trie.addWord("thu");
    trie.addWord("ha");

    Trie assignedTrie;
    // Assignment operator
    assignedTrie = trie;
    EXPECT_TRUE(assignedTrie.isWord("thu"));
    EXPECT_TRUE(assignedTrie.isWord("ha"));
}

// Stress test for the Trie
TEST(TrieTest, StressTest) {
    Trie firstTrie;
    firstTrie.addWord("aba");
    firstTrie.addWord("abb");
    firstTrie.addWord("abc");
    firstTrie.addWord("apple");
    
    // Check correct retrieval of words by prefix.
    vector<string> expected = {"aba", "abb", "abc"};
    EXPECT_EQ(expected, firstTrie.allWordsStartingWithPrefix("ab"));

    expected = {"apple"};
    EXPECT_EQ(expected, firstTrie.allWordsStartingWithPrefix("ap"));

    // Retrieve all words when no prefix is provided.
    expected = {"aba", "abb", "abc", "apple"};
    EXPECT_EQ(expected, firstTrie.allWordsStartingWithPrefix(""));
 
    Trie otherTrie = firstTrie;
    firstTrie.addWord("hello");
    expected = {};
    EXPECT_EQ(expected, otherTrie.allWordsStartingWithPrefix("hello"));

    // Testing pointer operations and ensuring changes reflect through pointers.
    Trie* secondTrie = &firstTrie;
    Trie* anotherTrie = new Trie();
    anotherTrie = secondTrie;
    firstTrie.addWord("hello");
    secondTrie->addWord("world");
    expected = {"world"};
    EXPECT_EQ(expected, anotherTrie->allWordsStartingWithPrefix("world"));

    expected = {"hello"};
    EXPECT_EQ(expected, anotherTrie->allWordsStartingWithPrefix("hello"));
    EXPECT_EQ(expected, secondTrie->allWordsStartingWithPrefix("hello"));
}