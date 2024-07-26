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
