
// declares a dictionary
#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

#define ARRAY_SIZE(a) sizeof(a)/sizeof(a[0])

// size of the alphabet is the number of children
#define N 26

// Converts key current character into index
// use only 'a' through 'z' and lower case
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')


// trie node 
typedef struct TrieNode { 
    struct TrieNode *children[N]; 
  
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool is_word; 
} TrieNode;

/*
// Returns new trie node (initialized to NULLs)
typedef struct TrieNode *getNode(void) {
    struct TrieNode *pNode = NULL;
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    if (pNode)
    {
        int i;
        pNode->is_word = false;
        for (i = 0; i < N; i++)
            pNode->children[i] = NULL;
    }
    return pNode;
} TrieNode;
*/


// functions
bool search(struct TrieNode *root, const char *key);
void addWord(struct TrieNode *root, const char *key);
struct TrieNode *getNode(void);
// void trieFreeChildren(struct TrieNode* node);
void freeTrie(struct TrieNode* root);


#endif // DICTIONARY_H