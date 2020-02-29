/*
// declares a dictionary

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// maximum length for a word
#define LENGTH 45

// a dictionary is an array
typedef struct dict {
  int numWords;
  int maxWords;
  char **words;
} dict;

dict *newEmptyDict();
void addWord(char word[LENGTH + 1], dict *d);
bool check(const char *word, dict *d);
void freeDict(dict *n);

#endif // DICTIONARY_H
*/

// declares a dictionary
#define DICTIONARY_H

#include <stdbool.h>

// size of the alphabet is the number of children
#define N 26

// a trie 
typedef struct trie {
	bool is_word;
	struct trie *children[N];
} trie;

// trie node 
typedef struct TrieNode { 
    struct TrieNode *children[N]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool is_word; 
} TrieNode;

// functions
bool search(struct TrieNode *root, const char *key);
void addWord(struct TrieNode *root, const char *key);
