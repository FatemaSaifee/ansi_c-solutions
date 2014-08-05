#include <stdio.h>
/*count blanks tabs and newline*/
main()
{
    int c, nb, nt, nl;
    
    nb=0; /*number of blanks*/
    nt=0;
    nl=0;
    while((c= getchar())!= EOF){
        if (c == ' ')
            ++nb;
        else if (c == '\t')
            ++nt;
        else if (c == '\n')
            ++nb;
    }
    printf("%d %d %d\n", nb, nt, nl);
}
