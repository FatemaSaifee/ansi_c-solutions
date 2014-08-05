#include <stdio.h>
/*replace tabs and backspaces with visible character*/
main()
{
    int c;
    
    while((c = getchar()) != EOF)
        if (c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
}