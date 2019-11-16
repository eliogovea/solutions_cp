#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;

const double PI = 3.14159;

char c;
int cant;
double r,h,v,mx;



int main()
{
    cin >> cant;
    for(int i=0; i<cant; i++)
    {
        cin >> c;
        if(c=='S')
        {
            cin >> r;
            v=4.0*PI*r*r*r/3.0;
        }
        else if(c=='L')
        {
            cin >> r >> h;
            v=PI*r*r*h;
        }
        else if(c=='C')
        {
            cin >> r >> h;
            v=PI*r*r*h/3.0;
        }
        //printf("%c %.3lf\n",c,v);
        mx=max(mx,v);
    }

    printf("%.3lf\n",mx);
    return 0;
}
