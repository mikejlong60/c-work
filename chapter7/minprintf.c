#include <stdarg.h>
#include <stdio.h>

typedef char String;

//minimal printf with variable argument list
void minprintf(String *fmt, ...) {
    va_list ap;//points to each unnamed arg in turn
    String *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);  //Make ap print to first unnamed arg
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch(*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d\n", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("fff %f\n", dval);
                break;
            case 's':
                for (sval = va_arg(ap, String *); *sval; sval++)
                    putchar(*sval);
                break;
            case 'i':
                ival = va_arg(ap, int);
                printf("%i\n", ival);
                break;
            default: 
                putchar(*p);
                break;
        }
    }
    va_end(ap); //clean up when done
}

main() {
    minprintf("Integer: %d\n", 431, "String: %s\n", "dude");
    minprintf("String: %s\n", "dude");
    minprintf("Double: %f\n", 3.141);
    minprintf("Integer2: %i\n", 3);


}