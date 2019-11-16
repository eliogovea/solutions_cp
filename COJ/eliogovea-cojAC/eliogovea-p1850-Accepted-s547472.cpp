#include<cstdio>
#define MAXN 1000010
#define MOD 10000

int n,q,u,tip,a,b;
int tree[MAXN];

inline void update(int pos, int val)
{
    for(int i=pos; i<=n; i+= i&-i)
        tree[i]=(tree[i]+val)%MOD;
}

inline int query(int pos)
{
    int ret=0;
    for(int i=pos; i; i -= i&-i)
        ret=(ret+tree[i])%MOD;
    return ret;
}


int main()
{
    scanf("%d%d%d",&n,&u,&q);
    u+=q;
    while(u--)
    {
        scanf("%d%d%d",&tip,&a,&b);
        if(tip==1)
        {
            if(a-1>0)update(a-1,b);
            update(a,2*b);
            update(a+1,b);
        }
        else printf("%d\n",(query(b)-query(a-1)+MOD)%MOD);
    }
}
