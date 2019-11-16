#include<iostream>
#include<cmath>
#include<algorithm>
#define EPS 1e-6
using namespace std;

struct point{ int x,y; };

bool al( point p1, point p2, point p3 )
{
	return abs( ( p2.x - p1.x ) * ( p3.y - p1.y ) -
				( p2.y - p1.y ) * ( p3.x - p1.x ) ) < EPS;
}

double dist( point p1, point p2 )
{
	return sqrt( ( p1.x - p2.x ) * ( p1.x - p2.x ) +
					( p1.y - p2.y ) * ( p1.y - p2.y ) );
}

int cas;
point p1,p2,p3,p4,p5;

int main()
{
	for( cin >> cas; cas--; )
    {
        cin >> p1.x >> p1.y
	    >> p2.x >> p2.y
		>> p3.x >> p3.y
		>> p4.x >> p4.y
		>> p5.x >> p5.y;

        double per = dist( p1, p2 ) + dist( p2, p3 ) + dist( p3, p1 );
        double sol;

        if( al( p1, p2, p4 ) )
        {
            if( al( p1, p2, p5 ) )
                sol = dist( p4, p5 );
            else if( al( p2, p3, p5 ) )
            {
                double s = dist( p4, p2 ) + dist( p2, p5 );
                sol = min( s, per - s );
            }
            else
            {
                double s = dist( p4, p1 ) + dist( p5, p1 );
                sol = min( s, per - s );
            }
        }
        else if( al( p2, p3, p4 ) )
        {
            if( al( p2, p3, p5 ) )
                sol = dist( p4, p5 );
            else if( al( p1, p3, p5 ) )
            {
                double s = dist( p4, p3 ) + dist( p3, p5 );
                sol = min( s, per - s );
            }
            else
            {
                double s = dist( p4, p2 ) + dist( p5, p2 );
                sol = min( s, per - s );
            }
        }
        else
        {
            if( al( p1, p3, p5 ) )
                sol = dist( p4, p5 );
            else if( al( p1, p2, p5 ) )
            {
                double s = dist( p4, p1 ) + dist( p1, p5 );
                sol = min( s, per - s );
            }
            else
            {
                double s = dist( p4, p3 ) + dist( p5, p3 );
                sol = min( s, per - s );
            }
        }

        cout.precision(10);
        cout << fixed << sol << endl;
    }
}