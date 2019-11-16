#include<cstdio>
#include<cmath>

int cant;
double r;
char sol[1000];
const double PI = 2.0*asin(1);
int main()
{
    scanf("%lf",&r);

    sprintf(sol,"%.5lf",PI*r*r);

    for(int i=0; cant<=5; i++)
    {
        char c=sol[i];
        if(c=='.')cant=1;
        if(cant)cant++;
        printf("%c",c);
    }
    printf("\n");
    sprintf(sol,"%.5lf",2.0*r*r);
    cant=0;

    for(int i=0; cant<=5; i++)
    {
        char c=sol[i];
        if(c=='.')cant=1;
        if(cant)cant++;
        printf("%c",c);
    }
    printf("\n");
}
