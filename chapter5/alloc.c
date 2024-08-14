#include <stdio.h>
#include "mystring.h"

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else {/* not enough room */
        printf("no room\n");
        return 0;
    }
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


void printArray(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("hegidge:%c\n", arr[i]);
    }
    printf("||\n");
}


//final version. copy t to s which continues the loop until the expression evaluates to false(0).
void strcpy3(char *s, char *t) {
    while ((*s++ = *t++))
        ;
}

int main() {
    char *p = alloc(3);
    p = "michael";
    printArray(p, 7);
    afree(p);
    printArray(p, 7);

    char *f = p;
    printArray(f, 7);
    
    char *p1 = alloc(100);
    printf("dang:%p\n", p1);

    printf("length of p:%d\n",strlen2(p));

    char *t = NULL;
    strcpy3(t, p);
    printArray(t, 7);
    
    char t2[70];
    strcpy2(t2, p);
    printArray(t2, 7);
 
    char s1[] = {'H', 's','e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};
    char s2[] = {'H', 'e', 'l', 'l', 'o', ',', ' ', 'W', 'o', 'r', 'l', 'd', '!', '\0'};

    printf("String array comparison:%d\n",strcmp3(s1, s2));

    char *s3;
    char *s4;
    s3 = "qmichael";
    s4 = "michael";
    printf("String pointer comparison:%d\n",strcmp3(s3, s4));
   
 

}



