#include <stdio.h>
#include <assert.h>
#include "mystring.h"

int divide(int numerator, int denominator) {
    assert(denominator != 0); // Ensure the denominator is not zero
    return numerator / denominator;
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


    char s2[] = {'h','e','\0'};    
    strcat3(s2, t);
    printf("string comparison of s:%s to expected:%s is %d\n", s2, expected, strcmp3(s2, expected));
    printf("t:%s --- %d\n", s2, strcmp3(s2, expected));
    assert(strcmp3(s2, expected) == 0);


}