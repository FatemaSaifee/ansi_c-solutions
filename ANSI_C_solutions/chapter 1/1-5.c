/*print fahrenhite-celsius table in reverse order*/
#include <stdio.h>
main()
{
    int f;
    for (f = 300; f>=0; f-=20)
        printf("%3.0f %6.1f\n",f,(5.0/9.0)*(f-32.0));
}
