#include<cstdio>
#include<cmath>

int n,a[30][2],x,y,dm=1000000,p;

int main(){
    scanf("%d",&n);
    for(int i=0; i<n; i++){
            scanf("%d%d",&a[i][0],&a[i][1]);
            x+=a[i][0];y+=a[i][1];
            }
    for(int i=0; i<n; i++){
            if( (x-a[i][0])*(x-a[i][0])+(y-a[i][1])*(y-a[i][1])<dm ){
                dm=(x-a[i][0])*(x-a[i][0])+(y-a[i][1])*(y-a[i][1]);
                p=i;
                }
            }
    printf("%d %d\n%.2f\n",x,y,sqrt(dm));
    return 0;
    }
