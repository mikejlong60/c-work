#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../getch.h"
#include "keywords.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct Key))

int getword(char *, int);
struct Key *binsearch(char *, struct Key *, int);

int main() {
    char word[MAXWORD];
    struct Key *p;
    
    while (getword(word, MAXWORD) != EOF) 
        if (isalpha(word[0])) 
            if ((p=binsearch(word, keytab, NKEYS)) != NULL) 
                p->count++;
            
        
    
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s\n", p->count, p->word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
struct Key *
binsearch(char *word, struct Key *tab, int n) {
    int cond;
    struct Key *low = &tab[0];
    struct Key *mid;
    struct Key *high = &tab[n];
    
    while (low < high) {
        mid = low + (high-low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}
