#include<cstdio>

#define MAX 100000

int arr[MAX+1][6],n,a,b,mx,pos;

int main()
{
    scanf("%d",&n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d%d",&a,&b);

        if(a!=b)
        {
            arr[i][a]=arr[i-1][a]+1;
            arr[i][b]=arr[i-1][b]+1;
        }
        else arr[i][a]=arr[i-1][a]+1;

        if(arr[i][a]>mx || (arr[i][a]==mx && a<pos))
            mx=arr[i][a],pos=a;
        if(arr[i][b]>mx || (arr[i][b]==mx && b<pos))
            mx=arr[i][b],pos=b;
    }

    printf("%d %d\n",mx,pos);
}
