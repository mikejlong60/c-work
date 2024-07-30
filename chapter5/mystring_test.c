#include <stdio.h>
#include <assert.h>
#include "mystring.h"


void test_strncpy2_n_gt_from_size() {
    char buffer[9];
    char hello[6] = "hello";
    char *result = strncpy2(buffer, hello, 8);
    printf("buffer3[%s] \n", buffer);
    printf("result3[%s] \n", result);
    assert(strcmp3(buffer, "hello") == 0);
    assert(strcmp3(result, "hello") == 0);
}

void test_strncpy2_n_lt_from_size() {
    char buffer[8] = "";
    char hello[6] = "hello";
    char* result = strncpy2(buffer, hello, 3);
    printf("buffer[%s] - comp[%d] \n", buffer, strcmp3(buffer, "hel"));
    printf("result[%s] comp[%d] \n", result, strcmp3(result, "hel"));
    assert(strcmp3(buffer, "hel") == 0);
    assert(strcmp3(result, "hel") == 0);
}

int main() {
    char s[] = {'h','e','\0'};
    char t[] = {'l','l','o', '\0'};
    strcat2(s, t);
  
    char expected[] = {'h','e','l','l','o', '\0'};
    assert(strcmp3(s, expected) == 0);
    


    ////////////////////
    assert(strcmp2(s, expected) == 0);


    char s2[] = {'h','e','\0'};    
    char *ss2;

    ss2 = strcat3(s2, t);

    assert(strcmp3(s2, expected) == 0);

    //test strlen2
    int a = strlen2(expected);
    assert(strlen2(expected) == 5);

    //test returns 1 if string s2 occurs at the end of string t2. 0 otherwise
    char t2[] = {'l','l','o','\0'};
    char s3[] = {'o', '\0'};
    assert(strend2(t2, s3) == 1);
    //This should return false
    char t3[] = {'l','l','\0'};
    assert(strend2(t3, s3) == 0);
    //This should return true
    char t4[] = {'h','e','l','l','o','\0'};
    char s4[] = {'l','l','o','\0'};
    assert(strend2(t4, s4) == 1);
 
    //This should return false
    char t5[] = {'h','o','\0'};
    char s5[] = {'l','l','o','\0'};
    assert(strend2(t5, s5) == 0);
    
   //This should return true
    char t6[] = {'o','\0'};
    char s6[] = {'o','\0'};
    assert(strend2(t6, s6) == 1);
 
   //test strcpy2 -- This should return true
    char buffer[5];
    char *result = strcpy2(buffer, "hello");
    printf("buffer:%s \n", buffer);
    printf("result:%s \n", result);
    assert(strcmp3(buffer, "hello") == 0);
    assert(strcmp3(result, "hello") == 0);


   // test_strncpy2_n_gt_from_size();
    test_strncpy2_n_lt_from_size();
}
