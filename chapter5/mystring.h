//Pointer version of string comparison
//Returns < 0 is s < t, o if s == t, >0 is s > t
int strcmp3(char *s, char *t) {
    
    for (; *s == *t; s++, t++)
        if (*s  == '\0')
            return 0;
    return *s - *t;
}

//Pointer version of string copy
//copy string 'from', to string 'to', including '\0'; return to
char *strcpy2(char *to, char *from) {
    char *t = to;
    char *f = from;
    while ((*t++ = *f++) != '\0')
        ;
    return to;
}

char *strcat3(char *dest, const char *from) {
    char *to = dest;
    
    while (*to != '\0') to++;
        
    while ((*to++ = *from++) != '\0') //copy
        ;
    *to = '\0';
    return dest;
}

// NOTE This is your safest function!!!!!!!  Others may cause seg faults!!!!!
//concatenate at most n characters of string 'from' to string 'to'.
//Pad with '\0's if 'from' has fewer than n characters.
char *strncat3(char *to, char *from, int n) {
    int i = 0;
    for (; to[i] != '\0'; i++);//move index to end of to
     
    int j = 0;
    while ((from[j] != '\0') && (j < n)) {
        to[i] = from[j];
        j++;
        i++;
    } 
    
    while (j <= n && from[j] != '\0') { //Pad if neccessary
        to[i] = '\0';
        j++;
        i++;
    }        
    return to;
}



//Pointer version of string copy
//copy at most n characters of string 'from' to string 'to'. 
// return 'to'.  Pad with '\0's if from has fewer than n characters.
char *strncpy2(char *to, const char *from, int n) {
    int i = 0;
    for (; i < n && from[i] != '\0'; i++) {
        to[i] = from[i];
    }
    for (; i < n; i++) {
        to[i] = '\0';
    }
    return to;
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
