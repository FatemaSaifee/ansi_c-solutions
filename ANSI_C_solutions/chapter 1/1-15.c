#include <stdio.h>

float celsius(float);

/*print Fahereenhite-Celsius table*/

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
       
        printf("%3.0f %6.1f\n",f,celsius(f));
        f+=step;
    }
}
float celsius(float f)
{
    return  (5.0/9.0)*(f-32.0);
}