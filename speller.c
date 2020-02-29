// a SLOW spell checker

#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int main(int argc, char *argv[]) {

  char word[N + 1] = "";

  struct TrieNode *root = getNode();

  // step 1: add words to the trie
  while (scanf("%45s",word) && word[0] != '!') {
    trimWord(word);
    addWord(root, word);
  }

  // step 2: read in text
  int counter = 0; // number of unknown words

  // TODO: Replace the above while loop with a correct solution.
  // Hints:
  // - you should read one character at a time, using getchar()
  // - alphabetical characters should be appended to the current word
  // - any other symbol should terminate the word
  // this code might be useful:

  
  int c = EOF;
  int i = 0;
  char clear[N+1] = " ";
  char string[N+1] = " ";

  // while accept character and not end of file
  while ((c = getchar()) && c != EOF) {
  	
  	// conditional that accepts when the character is alphabetical
    if (isalpha(c)) {
    	
    	// while character is alphabetical allocate character to string
      	while (isalpha(c)) {
        	string[i] = c;
        	i++;
       		c = getchar();
       	}
		
       	// converts string to lower case
		trimWord(string);

		/* conditional to check whether the string is in the dictionary 
		if not then print the strong and count how many */
   		if (search(root, word)) {
      		counter++;
      		printf("%s\n",string);
    	}

    	// clears the string so it is empty to store a new word
    	for (int x = 0; x < i; x++){
			string[x] = clear[0];
		}
		i = 0;
    }
    else {
    	continue;
    }
  }


  // step 3: print number of unknown words
  printf("%d\n", counter);

  return 0;
}