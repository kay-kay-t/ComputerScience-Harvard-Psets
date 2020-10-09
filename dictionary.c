// Implements a dictionary's functionality
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
//represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
// Number of buckets in hash table
const unsigned int N = 65536;
// Initialise positive hash value using unsigned int
unsigned int head;
// Initialise (positive) hash table word count
unsigned int word_count;
// Hash table
node *table[N];
// Loads dict into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Open dictionary
    FILE *file = fopen(dictionary, "r");
// Check if return value is NULL
    if (file == NULL)
    {
        return false;
    }
    // Reading strings from file
    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        // If malloc returns NULL, return false
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
        // Repeat for each word
        word_count++;
    }
// Close file
    fclose(file);
    return true;
}
// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long hash = 5381;
    int k;
    while ((k = toupper(*word++)))
    {
        hash = ((hash << 5) + hash) + k; //hash * 33 + k//
    }
    return hash % N;
}
// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // Check if there are any words
    if (word_count > 0)
    {
        return word_count;
    }
    return 0;
}
// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Hash the word to get hash value
    head = hash(word);
    //Access the linked list, where`s pointer - cursor
    node *pointer = table[head];
    //Go through the linked list
    while (pointer != NULL)
    {
        //Check if the word matches
        if (strcasecmp(word, pointer->word) == 0)
        {
            return true;
        }
        //Move cursor to next node
        pointer = pointer->next;
    }
    return false;
}
// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // Iterate through buckets
    for (int i = 0; i < N; i++)
    {
        // Set cursor to this each bucket location
        node *pointer = table[i];
        while (pointer != NULL)
        {
            node *tmp = pointer;
            // Move cursor to next node
            pointer = pointer->next;
            free(tmp);
        }
        // If cursor is NULL
        if (i == N - 1 && pointer == NULL)
        {
            return true;
        }
    }
    return false;
}