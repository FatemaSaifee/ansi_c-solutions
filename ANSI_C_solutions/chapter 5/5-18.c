#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXTOKEN    100

enum { NAME, PARENS, BRACKETS };
enum { NO, YES };

void dcl(void);
void dirdcl(void);
int gettoken(void);
int tokentype;                              
char token[MAXTOKEN];                       
char name[MAXTOKEN];                        
char datatype[MAXTOKEN];                    
char out[1000];

void errmsg(char *);
int prevtoken = NO;

int main()
{
    while (gettoken() != EOF)
    {
        strcpy(datatype, token);
        out[0] = '\0';
        dcl();                              
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void)          
{
    int c, getch(void);
    void ungetch(int);
    char *p = token;

    if (prevtoken == YES)
    {
        prevtoken = NO;
        return tokentype;
    }
    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token, "()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    }
    else
        return tokentype = c;
}
