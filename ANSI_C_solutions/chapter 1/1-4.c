#include <stdio.h>
/*celsius to fahrenhite table*/
main()
{
    float f,c;
    int lower, upper, step;
    
    lower=0;
    upper=300;
    step=20;
    
    printf("Fahr Celsius");
    c=lower;
    while(c<=upper){
        f=(9.0*c)/5.0 + 32.0;
        printf("%3.0f %6.1f\n",c,f);
        f+=step;
    }
}
