#include <stdio.h>
#include <assert.h>
#include "mystring.h"


void test_strncpy2_n_gt_from_size() {
    char buffer[9];
    char hello[6] = "hello";
    char *result = strncpy2(buffer, hello, 8);
    assert(strcmp3(buffer, "hello") == 0);
    assert(strcmp3(result, "hello") == 0);
}

void test_strncpy2_n_lt_from_size() {
    char buffer[8] = "";
    char hello[6] = "hello";
    char* result = strncpy2(buffer, hello, 3);
    assert(strcmp3(buffer, "hel") == 0);
    assert(strcmp3(result, "hel") == 0);
}

void test_strcat3() {
    char s[3] = "he";    
    char t[4] = "llo";
    char* result = strcat3(s, t);
    char expected[6] = "hello";
    assert(strcmp3(s, expected) == 0);
    assert(strcmp3(result, expected) == 0);
}

void test_strncat3_concat_all_giant_n() {
    char s[3] = "he";    
    char t[4] = "llo";
    char* result = strncat3(s, t, 800);
    char expected[6] = "hello";
    assert(strcmp3(s, expected) == 0);
    assert(strcmp3(result, expected) == 0);
}

void test_strncat3_concat_all() {
    char s[3] = "he";    
    char t[4] = "llo";
    char* result = strncat3(s, t, 3);
    char expected[6] = "hello";
    assert(strcmp3(s, expected) == 0);
    assert(strcmp3(result, expected) == 0);
}

void test_strncat3_concat_2() {
    char s[3] = "he";    
    char t[4] = "llo";
    char* result = strncat3(s, t, 2);
    char expected[6] = "hell";
    assert(strcmp3(s, expected) == 0);
    assert(strcmp3(result, expected) == 0);
}


void test_strncat3_concat_1() {
    char s[3] = "he";    
    char t[4] = "llo";
    char* result = strncat3(s, t, 1);
    char expected[6] = "hel";
    assert(strcmp3(s, expected) == 0);
    assert(strcmp3(result, expected) == 0);
}

void test_strlen2() {
    char expected[] = {'h','e','l','l','o', '\0'};
    int a = strlen2(expected);
    assert(strlen2(expected) == 5);
}

void test_strend_true1() {
    //test returns 1 if string s2 occurs at the end of string t2. 0 otherwise
    char t2[] = {'l','l','o','\0'};
    char s3[] = {'o', '\0'};
    assert(strend2(t2, s3) == 1);
}

void test_strend_true2() {
   //This should return true
    char t4[] = {'h','e','l','l','o','\0'};
    char s4[] = {'l','l','o','\0'};
    assert(strend2(t4, s4) == 1);
}

void test_strend_false1() {
    char s3[] = {'o', '\0'};
    char t3[] = {'l','l','\0'};
    assert(strend2(t3, s3) == 0);
}

void test_strend_false2() {
   //This should return false
    char t5[] = {'h','o','\0'};
    char s5[] = {'l','l','o','\0'};
    assert(strend2(t5, s5) == 0);
}

void test_strend_true3() {
   //This should return true
    char t6[] = {'o','\0'};
    char s6[] = {'o','\0'};
    assert(strend2(t6, s6) == 1);
}


void test_strcpy2_true() {
    //test strcpy2 -- This should return true
    char buffer[5];
    char *result = strcpy2(buffer, "hello");
    assert(strcmp3(buffer, "hello") == 0);
    assert(strcmp3(result, "hello") == 0);
}

int main() {
    test_strcat3();
    test_strncat3_concat_all_giant_n();
    test_strncat3_concat_all();
    test_strncat3_concat_1();
    test_strncat3_concat_2();

    test_strncpy2_n_gt_from_size();
    test_strncpy2_n_lt_from_size();

    test_strlen2();
    test_strend_true1();
    test_strend_false1();
    test_strend_true2();
    test_strend_true3();
    test_strend_false2();

     test_strcpy2_true();
}
