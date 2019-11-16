#include<cstdio>

float a,x;

int main()
{
    for(int i=1; i<=12; i++)
    {
        scanf("%f",&x);
        a+=x;
    }
    printf("$%.2f",a/12.0);
    return 0;
}
