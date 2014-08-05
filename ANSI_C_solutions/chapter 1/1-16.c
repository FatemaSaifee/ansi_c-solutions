#include <stdio.h>
#define MAXLINE 1000 /* max line size*/

int getline(char line[],int maxline);
void copy(char to[],char from[]);

/* print thr longest line*/
main()
{
    int len;    /* current line length */
    int max;    /* max length seeen so far */
    char line[MAXLINE]; /*current input line*/
    char longest[MAXLINE];
    
    max=0;
    while((len = getline(line, MAXLINE))>0){
        printf("%d, %s", len, line);
        if (len>max){
            max=len;
            copy(longest,line);
        }
    }
    if (max>0)
        printf("%s",longest);
    return 0;
    
}

/*getline: read a line into s,return length */
int getline(char s[],int lim)
{
    int c,i,j;
    
    j=0;
    for (i=0; (c=getchar())!= EOF && c!='\n'; ++i)
        if (i<lim-2){
            s[j] = c;       /* line still in boundaries */
            ++j;
        }
    if (c =='\n'){
        s[j]=c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

/*copy: copy 'from' to 'to'  */
void copy (char to[],char from[])
{
    int i;
    i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
