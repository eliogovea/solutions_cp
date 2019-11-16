#include <cstdio>
#include <cmath>

const int m[5][2] = {{1, 4}, {3, 4}, {3, 5}, {2, 6}, {1, 5}};
double a[10], b[10], c[10], x[10], y[10];

int main()
{
	for (int i = 1; i <= 6; i++)
		scanf("%lf%lf%lf", a + i, b + i, c + i);
	for (int i = 0; i < 5; i++)
		x[i] = ( c[m[i][1]] * b[m[i][0]] - c[m[i][0]] * b[m[i][1]] ) / ( a[m[i][0]] * b[m[i][1]] - a[m[i][1]] * b[m[i][0]] ),
		y[i] = ( a[m[i][1]] * c[m[i][0]] - a[m[i][0]] * c[m[i][1]] ) / ( a[m[i][0]] * b[m[i][1]] - a[m[i][1]] * b[m[i][0]] );
	x[5] = x[0];
	y[5] = y[0];
	double sol = 0;
	for (int i = 1; i <= 5; i++)
		sol += sqrt( (x[i] - x[i - 1]) * (x[i] - x[i - 1]) + (y[i] - y[i - 1]) * (y[i] - y[i - 1]) );
	printf("%.2lf\n", sol);
}
