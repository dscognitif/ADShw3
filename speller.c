// Algorithms and Data Structures in AI
// Assigment 3: Spell Checker
// s4017765 & s3897605

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "dictionary.h"

// remove non-alphabetic characters and convert to lower case
void trimWord(char *word) {
  int k = 0;
  for (int i = 0; i < (int) strlen(word); i++) {
    if (isalpha(word[i])) {
      word[k] = tolower(word[i]);
      k++;
    }
  }
  word[k] = '\0';
}

// Driver code
int main(int argc, char *argv[]) {

  char word[N + 1] = "";

  //construct trie
  struct TrieNode *root = getNode(); 

  // add words to the trie and but convert to lower case
  while (scanf("%45s",word) && word[0] != '!') {
    trimWord(word);
    addWord(root, word);
  }
  
  // number of unknown words
  int counter = 0;
  
  // the index to keep store the characters in the string
  int i = 0;

  // end of file
  int c = EOF;

  while ((c = getchar()) && c != EOF) {
    
    // Conditional to accept when the character is alphabetical
    if (isalpha(c)) {

      // use string to store the word scanned
      char string[N + 1] = "";

      // while the character is alphabetical allocate the characters into the string
      while (isalpha(c)) {
        string[i] = c;
        i++;
        c = getchar();
      }
      i= 0; // Reset the index

      // copy the string into word 
      strcpy(word, string);

      // convert to lower case
      trimWord(word);
      
      /* conditional when the word is not the trie dictionary then print the word 
      and count how many words are not in the dictionary */
      if (!search(root, word)) {
        counter++;
        printf("%s\n", word);
      }
    }
  }
  
  // print number of unknown words that are not in the dictionary
  printf("%d\n", counter);

  // deallocate the memory previously assigned to the trie
  freeTrie(root);
  
  return 0;
}