#include <stdio.h>

#define TABINC 8

//replace strings of blanks with tabs and blanks

main()
{
    int c,nb,nt,pos;
    
    nb=0;
    nt=0;
    for (pos = 1; (c=getchar()) != EOF; ++pos)
        if(c==' '){
            if ( pos % TABINC != 0)
                ++nb;
            else {
                nb=0;
                ++nt;
            }
        }else {
                for ( ;nt>0;--nt)
                    putchar('\t');
                if  ( c=='\t')
                    nb=0;
                else 
                    for( ;nb>0;--nb)
                            putchar('\t');
                            
                
            }
        
}
