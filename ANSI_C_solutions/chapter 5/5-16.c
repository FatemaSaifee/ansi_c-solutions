#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINES 1000
#define MAXSTOR 5000
#define TRUE    1
#define FASLE   0
char *lineptr[MAXLINES];

int get_line(char s[], int lim);
double atof(char *s);
int readlines(char *lineptr[], char *linestor, int maxlines);
void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));
int numcmp(char *, char *);
int my_strcmp(char *, char *);

int is_flodcase = FASLE;
int is_reverse = FASLE;
int is_directory = FASLE;

int main(int argc, char *argv[])
{
    int nlines, i;
    int numeric = FASLE;
    char program_name[MAXLINES];
    char linestor[MAXSTOR];

    /*
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
    {
        numeric = TRUE;
    }
    else if (argc > 1 && strcmp(argv[1], "-r") == 0)
    {
        is_reverse = TRUE;
    }
    else if (argc > 1 && strcmp(argv[1], "-f") == 0)
    {
        is_flodcase = TRUE;
    }
    else if (argc > 1)
    {
        printf("error: invalid switch\n");
        return -1;
    }
    */
   
    strcpy(program_name, argv[0]);
    while (--argc > 0)
    {
        ++argv;
        if ((*argv)[0] == '-')
            for (i = 1; (*argv)[i]; i++)
            {
                switch((*argv)[i])
                {
                    case 'n':
                        numeric = TRUE;
                        break;
                    case 'f':
                        is_flodcase = TRUE;
                        break;
                    case 'r':
                        is_reverse = TRUE;
                        break;
                    case 'd':
                        is_directory = TRUE;
                        break;
                    default: 
                        printf("usage: %s -dfnr\n", program_name);
                        return 1;
                }
            }
        else
        {
            printf("usage: %s -dfnr\n", program_name);
            return 1;
        }
    }

    if ((nlines = readlines(lineptr, linestor,  MAXLINES)) >= 0)
    {
        printf("\n\n-----------------\nI am Dividing lines\n-----------------\n");
        qsort((void **) lineptr, 0, nlines-1, (int (*)(void*, void*))(numeric ? numcmp : my_strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("input too big to sort\n");
        return 1;
    }
}

int get_line(char s[], int lim)
{
    int c;
    int i;
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], char *linestor, int maxlines)
{
    int len, nlines;
    char line[MAXLINES];
    char *p = linestor;
    char *linestop = linestor + MAXSTOR;

    nlines = 0;
    while((len = get_line(line, MAXLINES)) > 0)
    {
        if (nlines >= maxlines || p + len > linestop)       
            return -1;
        else {
            line[len - 1] = '\0';       // delete newline
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i = 0;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right)
        return ;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (is_reverse == TRUE)
        {
            if ((*comp)(v[i], v[left]) > 0)
                swap(v, ++last, i);
        }
        else
        {
            if ((*comp)(v[i], v[left]) < 0)
                swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }
    return sign * val / power;
}

void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int my_strcmp(char *v1, char *v2)
{
    if (is_directory == TRUE)
    {
        while (!isdigit(*v1) && !isalpha(*v1) && !isspace(*v1) && *v1)
            v1++;
        while (!isdigit(*v2) && !isalpha(*v2) && !isspace(*v2) && *v2)
            v2++;
    }
    while (is_flodcase ? (toupper(*v1) == toupper(*v2)) : (*v1 == *v2))
    {
        if (*v1 == '\0')
            return 0;
        ++v1;
        ++v2;
        if (is_directory)
        {
            while (!isdigit(*v1) && !isalpha(*v1) && !isspace(*v1) && *v1)
                v1++;
            while (!isdigit(*v2) && !isalpha(*v2) && !isspace(*v2) && *v2)
                v2++;
        }
    }
    return is_directory ? (tolower(*v1) - tolower(*v2)) : (*v1 - *v2);
}
