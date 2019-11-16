#include<cstdio>
#define MAXL 30

double sum,aux;

int main(){

	for(int i=1; i<=30; i++){
		scanf("%lf",&aux);
		sum+=aux;
	}

	printf("%.3lf\n",sum+sum/30.0);
}
