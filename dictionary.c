// Implements a dictionary's functionality
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;
// Initialise positive hash value using unsigned int 
unsigned int head;
// Initialise (positive) hash table word count 
unsigned int word_count;
// Hash table
node *table[N];

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO ------ right
    // Open dictionary
    FILE *file = fopen ("dictionary.h", "r");
    // Check if return value is NULL
    if (file == NULL)
    {
       return false; 
    }
    // Reading strings from file
    char word[LENGTH + 1];
    while (fscanf (file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        // Pointer to next node and word itself
        strcpy(new_node->word, word);
        // Hash the word to get hash value
        head = hash(word);
        // Set new pointer
        new_node->next = table[head];
        // Set head to new pointer
        table[head] = new_node;
        // Repeating it for each word 
        word_count++;
    }
    fclose (file);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO ---- right
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
        }
        else
        {
            n = 27;
        }

        hash = ((hash << 3) + n) % N;
    }
    return hash;
}
// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    // Cheking if there are any words
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO ---- mb right
    // Hash the word to get hash value
    head = hash(word);
    // Access linked list, seting a pointer(cursor) to the first node in linked list (head), cheking if its not null and moving it to next node
    for (node *pointer = table[head]; pointer != NULL; pointer = pointer -> next)
    {
        //check if the word matches
        if (strcasecmp(word, pointer->word) == 0)
        {
            return true;
        }
    }
    return false;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
   // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
    // Set pointer(cursor) to this each bucket location  
        node *pointer = table[i];
        if (pointer != NULL)
        {
            node *tmp = pointer;
            pointer = pointer->next;
            free (tmp);
        }
        else 
        {
            return true;
        }
    }    
    return false;
}
