#include<cstdio>

int n;
float d,v1,v2,f,s;

int main(){
    scanf("%d",&n);
    while(n--){
               scanf("%f%f%f%f",&d,&v1,&v2,&f);
               s=f*d/(v1+v2);
               printf("%.2f\n",s);
               }
    return 0;
    }
