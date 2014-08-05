
#include <stdio.h>
#define MAXLINE 1000 /* max line size*/

int getline(char line[],int maxline);
int remove1(char s[]);

/*remove trailing blnk sand tabs, and delete blak lines*/

main()
{
    char line(MAXLINE);
    
    while (getline(line, MAXLINE) > 0)
        if(remove1(line) > 0 )
            printf("%s", line);
    return 0;
}

/*remove trailing lnes and blanks form character string s*/
int remove1(char s[])
{
    int i;
    i=0;
    while(s[i]!='\n') //find newline character
        ++i;
    --i; //back off from '\n'
    
    while(i>=0&&(s[i]==' ' || s[i]=='\t'))
        --i;
    
    if(i>=0) { //is it a non-blank line?
        ++i;
        s[i]='\n'; //put newline character back
        ++i;
        s[i]='\0'; //terminate the string
    }
    return i;
    
}

    
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