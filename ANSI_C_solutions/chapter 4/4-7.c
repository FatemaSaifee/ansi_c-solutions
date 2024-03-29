#include<stdio.h>
#include<stdlib.h>		// for atof()
#include<ctype.h>
#include<string.h>
#include<math.h>


#define MAXOP	100
#define NUMBER	'0'
#define MAXVAL	100
#define BUFSIZE 100

int sp = 0;
char buf[BUFSIZE];
int bufp = 0;

int getch(void);
void ungetch(int);
void ungets(char s[]);

int main()
{
	char *s = "hello, world.  this is a test.";
	int c;
	ungets(s);
	while ((c = getch()) != EOF)		
	   putchar(c); 
	return 0;
}

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();			// s 中压回到 buf 中的字符返回出去
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}

void ungets(char s[])
{
	int len = strlen(s);
	while(len > 0)
		ungetch(s[--len]);		
}
