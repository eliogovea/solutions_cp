#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const double PI = 3.141592653589793116;

int n;
double sol,r[1001];

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++)scanf("%lf",&r[i]);
    sort(r+1,r+n+1);
    for(int i=1; i<=n; i++)
    {
        if(i&1)sol+=r[i]*r[i];
        else sol-=r[i]*r[i];
    }
    if(!(n&1))sol*=-1;
    printf("%.4lf\n",PI*sol);
    return 0;
    }
