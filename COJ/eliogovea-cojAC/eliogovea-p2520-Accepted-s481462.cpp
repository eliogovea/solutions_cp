#include<cstdio>
#include<vector>

using namespace std;

int t,n,p,j,f,x,t1,t2;
bool rec[501],rel[501];

vector<int> fail;
vector<int> del;

int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&n,&p,&j,&f);
        for(int i=0; i<j; i++)
        {
            scanf("%d",&x);
            rec[x]=1;
        }
        for(int i=0; i<f; i++)
        {
            scanf("%d",&x);
            rel[x]=1;
        }
        for(int i=p+1; i<=n; i++)
        {
            if(rec[i]==0 && rel[i]==0)
            {
                t1++;
                fail.push_back(i);
            }
        }
        for(int i=1; i<=n; i++)
        {
            if((rec[i] && i<=p) || (rec[i] && rel[i]))
            {
                t2++;
                del.push_back(i);
            }
        }

        if(fail.size()==0)printf("0\n");
        else
        {
            printf("%d ",fail.size());
            for(int i=0; i<fail.size()-1; i++)printf("%d ",fail[i]);
            printf("%d\n",fail[fail.size()-1]);
        }

        if(del.size()==0)printf("0\n");
        else
        {
            printf("%d ",del.size());
            for(int i=0; i<del.size()-1; i++)printf("%d ",del[i]);
            printf("%d\n",del[del.size()-1]);
        }
        fail.clear();
        del.clear();
        for(int i=0; i<=n; i++){rec[i]=rel[i]=0;}
    }
return 0;
}
