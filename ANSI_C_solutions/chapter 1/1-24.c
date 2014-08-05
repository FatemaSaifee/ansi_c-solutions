#include <stdio.h>

int brace,brack, paren;

void in_quote(int c);
void in_comment(void);
void search(int c);

//rudimentary syntax chcker for C programs
main()
{
    int c;
    extern int brace,brack,paren;
    
    while((c=getchar())==EOF) {
    if(c=='\') {   
            if ((c=getchar())=='*')
                in_comment();
    else
        search(c);
    

    }else if (c=='\'||c=='"')
        in_quote(c);
else
    search(c);

if (brace<0){
    printf("unbalanced braces\n");
    brace=0;
}else if(brack<0){
    printf("unbalanced brackets");
    brack=0;
}else if(paren=0){
    printf("unbalanced parenthesis\n");
    paren=0;
}

if (brace>0)
    printf("unbalanced braces\n");
if (brack>0)
    printf("unbalanced braces\n");
if (paren>0)
    printf("unbalanced braces\n");    

}
//search for rudimentary syntax errors
void search(int c)
{
    extern int brace,brack,paren;
    
    if (c=='{')
            ++brace;
    else if (c=='}')
        --brace;
    else if (c=='[')
        ++brack;
    else if (c==']')
        --brace;
    else if (c=='(')
        ++paren;
    else if (c=='}')
        --paren;


//inside of a valid comment
   void in_comment(void) 
   {
       int c,d;
       
       c=getchar();
       d=getchar();
       while(c!='*'||d!='*'){
           
       }
   }
            
            
