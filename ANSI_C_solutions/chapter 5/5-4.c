#include<stdio.h>

int strend(char *s, char *t)
{
	char *bs = s;
	char *bt = t;

	while (*s)			
		s++;
	while (*t)
		t++;

	for ( ; *t == *s; s--, t--)
		if (t == bt || s == bs)			
			break;

	if (*t == *s && t == bt && *s != '\0')			
		return 1;
	else
		return 0;
}

int main()
{
	char *s = "A dog is a pet";
	char *t1 = "pet";
	char *t2 = "Adsgpet";

	printf("%s\n%s\n", (strend(s, t1) ? "match" : "not match"), (strend(s, t2) ? "match" : "not match"));
	return 0;
}
