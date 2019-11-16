#include<cstdio>

const int MOD = 1000000007;
typedef long long ll;

typedef struct matriz
{
    ll mat[4][4];
}mat;

mat mult(mat a, mat b)
{
    mat aux;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            aux.mat[i][j]=0;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            for(int k=0; k<4; k++)
                aux.mat[i][j]=(aux.mat[i][j]+(a.mat[i][k]*b.mat[k][j])%MOD)%MOD;
    return aux;
}

mat eleva(mat a, int n)
{
    mat sol = a;
    while(n)
    {
        if(n&1)sol=mult(sol,a);
        a=mult(a,a);
        n>>=1;
    }
    return sol;
}

int n;

int main()
{
    mat x,ans;
    for(int i=0; i<4; i++)
        for(int j=0; j<4; j++)
            x.mat[i][j]=(i!=j);

    scanf("%d",&n);
    printf("%lld\n",eleva(x,n-1).mat[3][3]);
    return 0;
}
