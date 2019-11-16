#include<cstring>
#include<iostream>
using namespace std;

string aux="",mpal;

char a[75];
bool dp[75][75];
int MAX=1,l;

bool c(string s1, string s2)
{
    if(s1.size()>s2.size())return 1;
    else if(s1.size()==s2.size())
    {
        int i=0;
        while(s1[i]==s2[i])i++;
        if(s1[i]>s2[i])return 1;
    }
    return 0;
}

int main()
{
    cin >> a;
    l=strlen(a);
    for(int i=0; i<l; i++)
    {
        dp[i][i]=1;
        aux+=a[i];
        if(c(aux,mpal))mpal=aux;
        aux="";
    }

    for(int i=0; i<l-1; i++)
    {
        dp[i][i+1]=(a[i]==a[i+1]);
        if(dp[i][i+1])
        {
            MAX=2;
            aux+=a[i];
            aux+=a[i+1];
            if(c(aux,mpal))mpal=aux;
            aux="";
        }
    }

    for(int k=3; k<=l; k++)
        for(int i=0; i<l-k+1; i++)
        {
            int j=i+k-1;
            if(dp[i+1][j-1] && a[i]==a[j])
            {
                dp[i][j]=1;
                if(k>MAX)
                {
                    MAX=k;
                    for(int r=i; r<=j; r++)aux+=a[r];
                    if(c(aux,mpal))mpal=aux;
                    aux="";
                }
            }
        }
    cout << mpal << endl;
    return 0;
}
