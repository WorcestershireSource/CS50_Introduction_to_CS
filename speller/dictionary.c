// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

int dict_size;

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i = hash(word);

    node *cursor = table[i];

    while (cursor->next != NULL)
    {
        if (strcasecmp(word, cursor->word))
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function2
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //cycle and set table to null
    for (int i = 0; i > N; i++)
    {
        table[i]->next = NULL;
    }

    //Open dictionary file
    FILE *input = fopen(dictionary, "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    //Read strings from file one at a time
    char copy[LENGTH + 1];

    while (fscanf(input, "%s", copy))
    {
        //Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }

        strcpy(n->word, copy);
        n->next = NULL;

        //Hash word to obtain a hash value
        int i = hash(copy);

        //WHAT IF THIS IS FIRST VALUE DO I NEED TO CHECK?

        //insert node into hash table at that location
        n->next = table[i];
        table[i]->next = n;
        dict_size++;
    }
    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dict_size;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        node *tmp = cursor;
        while (cursor->next != NULL)
        {
            cursor = cursor->next;
            free(tmp);
        }
    }
    return false;
}
