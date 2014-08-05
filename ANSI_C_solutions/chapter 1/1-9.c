#include <stdio.h>
#define NOBLANK 'a'
/* replace strings of blank with a single blank*/
main()
{
    int c, lastc;
    
    lastc = NOBLANK;
    while((c = getchar()) != EOF){
        if (c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
