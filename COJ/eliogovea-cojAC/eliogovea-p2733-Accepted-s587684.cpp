#include <cstdio>
#include <cmath>

char str[1000];

int main()
{
	int n;
	for (scanf("%d", &n); n--;)
	{
		int cant = 0;
		scanf("%s", str);
		int a = 0;
		bool b = true;
		
		for (char *p = str; *p; p++)
		{
			if (*p != '.' &&( *p < '0' || *p > '9') ) {b = false; break;}
			if( *p == '.' && *(p+1) == '.' ) {b = false; break;}
			if (*p == '.')
			{
				if (a > 255) {b = false; break;}
				cant++;
				//printf("---%d\n", a);
				a = 0;

			}
			else a = 10 * a  + *p - '0';

		}
		if (a > 255) {b = false;}
		cant++;
		if (b && (cant == 4 || cant == 6)) printf("SI\n");
		else printf("NO\n");
	}
}
