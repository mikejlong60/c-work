#include <stdio.h>
#include <assert.h>
#include "mystring.h"

int divide(int numerator, int denominator) {
    assert(denominator != 0); // Ensure the denominator is not zero
    return numerator / denominator;
}

void strcat2(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0') //copy
        ;
}

int main() {
    char s[] = {'h','e','\0'};
    char t[] = {'l','l','o','\0'};
    strcat2(s, t);
  
    char expected[] = {'h','e','l','l','o', '\0'};
    printf("string comparison of s:%s to expected:%s is %d\n", s, expected, strcmp3(s, expected));
    printf("t:%s --- %d\n", s, strcmp3(s, expected));
    assert(strcmp3(s, expected) == 0);
    


    ////////////////////
    printf("string comparison of s:%s to expected:%s is %d\n", s, expected, strcmp2(s, expected));
    printf("t:%s --- %d\n", s, strcmp2(s, expected));
    assert(strcmp2(s, expected) == 0);



}