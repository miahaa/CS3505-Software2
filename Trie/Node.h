/*
Name: Thu Ha
Course: CS 3505
Assigment: A4 - A Trie and Rule-of-Three
Description: Implement a trie to practice Rule of Three
and apply data structure in C++
*/
#ifndef NODE_H
#define NODE_H
class Node {
public:
    /// @brief constructor
    Node();
    /// @brief Copy constructor
    /// @param other 
    Node(const Node& other);
    /// @brief Destructor
    ~Node();
    /// @brief Assignment operator
    /// @param other 
    /// @return 
    Node& operator=(const Node& other);
    /// @brief check if the character is in the trie
    /// @param ch 
    /// @return 
    bool hasCharacter(char ch) const;
    /// @brief create a new node at this index
    /// @param ch 
    /// @return 
    Node* addCharacter(char ch);
    /// @brief get the node of the character
    /// @param ch 
    /// @return 
    Node* getChildNode(char ch) const;
    /// @brief get the end of word flag
    /// @return 
    bool getEndOfWordFlag() const;
    /// @brief set the end of word flag
    void setEndOfWordFlag();
    /// @brief get the children list
    /// @return 
    Node** getChildrenList();
private:
    Node* children[26]; /// Array of pointers to child nodes
    bool endOfWord;
};

#endif // NODE_H