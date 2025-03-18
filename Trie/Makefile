
CC = g++
CFLAGS = -Wall -g -fsanitize=address

TARGET = TrieTest

OBJS = Trie.o TrieTest.o Node.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

TrieTest.o: TrieTest.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -c TrieTest.cpp

clean:
	 rm -f $(OBJS) $(TARGET)
