CC = g++
CFLAGS = -Wall -g -std=c++2a
GOOGLETEST ?= ./googletest

TARGET = TrieTests

OBJS = Trie.o TrieTests.o Node.o

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) $(GOOGLETEST)/lib/libgtest.a $(GOOGLETEST)/lib/libgtest_main.a

Trie.o: Trie.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -c Trie.cpp

Node.o: Node.cpp Node.h
	$(CC) $(CFLAGS) -c Node.cpp

TrieTests.o: TrieTests.cpp Trie.h Node.h
	$(CC) $(CFLAGS) -I$(GOOGLETEST)/googletest/include -c TrieTests.cpp

clean:
	rm -f $(OBJS) $(TARGET)
