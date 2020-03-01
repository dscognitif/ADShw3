// implements a dictionary in the data structure of a trie

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"


struct TrieNode *getNode(void) {
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
}

// If not present, inserts letter into trie 
// If the letter is prefix of trie node, just marks leaf node 
void addWord(struct TrieNode *root, const char *letter) { 
    int level; 
    int length = strlen(letter); 
    int index; 
  
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(letter[level]); 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    /* mark last node as true for the boolean function is_word so that 
    the trie recognises that this is a word */
    pCrawl->is_word = true; 
} 

// Returns true if letter presents in trie, else false 
bool search(struct TrieNode *root, const char *letter) { 
    int level; 
    int length = strlen(letter); 
    int index; 
    struct TrieNode *pCrawl = root; 
  
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(letter[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->is_word); 
} 

// this function deallocates the memory assigned to the trie   
void freeTrie(TrieNode *root) {
    if (root == NULL) {
        return ;
    }
        
    for (int i = 0; i < N; i++) {
        freeTrie(root->children[i]);
    }
    free(root);
}
    
    