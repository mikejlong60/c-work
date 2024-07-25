#include <stdio.h>

#define ALLOCSIZE 10000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf; /* next free position */

char *alloc(int n) /* return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) { /* it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else /* not enough room */
        return 0;
}

void afree(char *p) /* free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}


void printArray(char *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%c", arr[i]);
    }
    printf("\n");
}

int main() {
    char *p = alloc(1000);
    p = "moike";
    //printf("%s ", p);
    //char p1[] = "mike";
    //printf("%c ", p1[3]);
    //char *p2 = "mike";
    //printf("%s ", p2);
    //allocp[1] = "i";
    //allocp[2] = '/0';

    printArray(p, 5);
}
