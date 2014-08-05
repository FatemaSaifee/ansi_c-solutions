#include <stdio.h>

#include <conio.h>
#define IN 1
#define OUT 0

/*input one word per line*/
main()
{
    int c,state;
    
    state = OUT;
    while ((c = getchar()) != EOF){
        if (c == ' ' || c == '\n' ||c == '\t'){
            putchar('\n');
            state = OUT;
            
        }
        else if (state == OUT){
            state = IN;
            putchar(c);
        }
    }
    getch();
}
