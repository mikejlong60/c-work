#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

main() {

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                printf("duuh0 pushing %s\n", s);
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case '%':
                printf("duuh1 %s\n", s);
                int a = pop();
                int b = pop();
                //result = a % b
                printf("duuh2 %d\n", a);
                printf("duuh3 %d\n", b);
                //printf("duuh4 %s\n", b % a);
                push(a % b);
                break;
            case '\n':
                printf("\t%.8g\n", pop());
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
