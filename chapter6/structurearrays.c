#include <stdio.h>
#include <ctype.h>
#include "../getch.h"
#include "keywords.h"

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(struct Key))

int getword(char *, int);
int binsearch(char *, struct Key *, int);

int main() {
    int n;
    char word[MAXWORD];
    printf("1\n");
    while (getword(word, MAXWORD) != EOF) {
        printf("2\n");
        if (isalpha(word[0])) {
            printf("3: word[%s] keytab[%d] NKEYS[%d]\n", word, keytab[0].count, NKEYS);
            if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
                printf("4: n[%d], keytab.word[%s], keytab.count[%d]\n", n, keytab[n].word, keytab[n].count);
                keytab[n].count++;
            }
            printf("5\n");
        }
    }
    for (n = 0; n < NKEYS; n++)
        if (keytab[n].count > 0)
            printf("%4d %s\n", keytab[n].count, keytab[n].word);
    return 0;
}

/* binsearch: find word in tab[0]...tab[n-1] */
int binsearch(char *word, struct Key tab[], int n) {
    int cond;
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high) / 2;
        if ((cond = strcmp(word, tab[mid].word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}


