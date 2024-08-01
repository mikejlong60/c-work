struct Tnode {
    char *word;
    int count;
    struct Tnode *left;
    struct Tnode *right;
};

#include <ctype.h>
#include "../getch.h"
#include "keywords.h"
#include "../chapter5/mystring.h"
#include <stdlib.h>


#define MAXWORD 10
struct Tnode *addtree(struct Tnode *, char *);
void treeprint(struct Tnode *);
int getword(char *, int);

main() {
    struct Tnode *root;
    char word[MAXWORD];

    root = NULL;
    while (getword(word, MAXWORD) != EOF) {
        if (isalpha(word[0])) {
            root = addtree(root, word);
        }
    }
    treeprint(root);
    return 0;
}


struct Tnode *talloc(void);

//add a node with w, at or below p
struct Tnode *addtree(struct Tnode *p, char *w)  {
    int cond;

    if (p == NULL) { //a new word has arrived
        p = talloc(); //make a new node
        p->word = strdup(w); 
        p->count = 1;
        p->left = p->right = NULL;
    } else if ((cond = strcmp3(w, p->word)) == 0)
        p->count++; //repeated word
    else if (cond < 0)  //less than. go into left subtree
        p->left = addtree(p->left, w);
    else // go into right subtree
        p->right = addtree(p->right, w);
    
    return p;
}

//talloc - make a Tnode
struct Tnode *talloc(void) {
    return (struct Tnode *) malloc(sizeof(struct Tnode));
}

//treeprint - in-order print of tree p *
void treeprint(struct Tnode *p) {
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

