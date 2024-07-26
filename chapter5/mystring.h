//Array version of string comparison
//Returns < 0 is s < t, o if s == t, >0 is s > t
int strcmp2(char *s, char *t) {
    int i;
    for (i = 0; s[i] == t[i]; i++)
        if (s[i]  == '\0')
            return 0;
    return s[i] - t[i];
}

//Pointer version of string comparison
//Returns < 0 is s < t, o if s == t, >0 is s > t
int strcmp3(char *s, char *t) {
    
    for (; *s == *t; s++, t++)
        if (*s  == '\0')
            return 0;
    return *s - *t;
}

//
void strcat2(char s[], char t[]) {
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
        i++;
    while ((s[i++] = t[j++]) != '\0') //copy
        ;
}

void strcat3(char *s, char *t) {
    while (*s != '\0') s++;
    while ((*s++ = *t++) != '\0') //copy
        ;
}

int strlen2(char *s) {
    char *p = s;

    while (*++p != '\0') 
        ;
    return p - s;
}

//Returns 1 if string t occurs at the end of string s. 0 otherwise
int strend2(char *s, char *t) {
    int ls = strlen2(s) -1;
    int lt = strlen2(t) -1;
    int result = 1;
    if (ls < lt) {
        result = 0;
    } else {
        //start counting backwards from end of s
        for (; ls >= 0; ls--, lt--) {
            if (s[ls] == t[lt])  {
                result = 1;
            } else if (lt < 0) {
                break;
            } else {
                result = 0;
            }
        }
    }
    return result;
}
