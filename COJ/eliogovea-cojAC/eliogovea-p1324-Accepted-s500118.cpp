#include<cstdio>
#include<algorithm>
using namespace std;
int a[9],s;
bool b[9];

int main()
{
    for(int i=0; i<9; i++)
    {
        scanf("%d",&a[i]);
        s+=a[i];
    }
    sort(a,a+9);
    for(int i=0; i<8; i++)
        for(int j=i+1; j<9; j++)
            if(a[i]+a[j]==s-100)
            {
                b[i]=b[j]=1;
                break;
            }
    for(int i=0; i<9; i++)
        if(!b[i])printf("%d\n",a[i]);
    return 0;
}
