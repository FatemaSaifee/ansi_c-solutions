#include <stdio.h>
void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

//remove all comments
main()
{
    int c,d;
    while ((c= getchar()) != EOF)
        rcomment(c);
    return 0;
}

//rcoment: read each character ,remove comments
void rcomment(int c){
    int d;
    
    if (c == '/')
        if ((d=getchar()) == '*')
            in_comment();
        else if (d == '/'){
            putchar(c);
            putchar(d);
        }
        else if (c == '\'' || c == '"')
            echo_quote(c);  //qoute begins
        else
            putchar(c); //not a comment
        
}
 
/* in_comment : inside of a valid comment*/
void in_comment(void)
{
    int c, d;
    
    c = getchar();
    d = getchar();
    while (c != '*' || d != '/'){
        c = d;
        d=getch();
    }
}
    
    
    
    
    
/*echo character with*/   
void echo_quotes(int c)
{
    int d;
    while((d = getchar()) !=c){
        putchar(d);
        if (d == '\\')
            putchar(getch());
        
    }
    putchar(d);
}