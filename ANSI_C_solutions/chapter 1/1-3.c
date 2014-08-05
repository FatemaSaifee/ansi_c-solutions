/*modify temp conversion program to print heading above table*/
#include <stdio.h>
/*print farenhite to celsius table for fare = 0,20,...300*/
main()
{
    float f,c;
    int lower, upper, step;
    
    lower=0;
    upper=300;
    step=20;
    
    printf("Fahr Celsius");
    f=lower;
    while(f<=upper){
        c = (5.0/9.0)*(f-32.0);
        printf("%3.0f %6.1f\n",f,c);
        f+=step;
    }
}
