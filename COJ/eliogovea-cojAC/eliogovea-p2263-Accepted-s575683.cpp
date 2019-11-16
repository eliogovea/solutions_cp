#include <cstdio>
using namespace std;

int c;
char s[110];

int main()
{
    for( scanf( "%d", &c ); c--; )
    {
        scanf( "%s", s );
        int i = 0, player = 0, mx[2] = {0, 0};
        while( true )
        {
            if( !s[i] ) break;
            int cont = 0;
            while( s[i] == ':' ) i++, cont++;
            while( s[i] == ')' ) i++, cont++;
            if( cont > mx[player] )
                mx[player] = cont;
            player = 1 - player;
        }

        if( mx[0] > mx[1] ) printf( "Jennifer\n" );
        else printf( "Alan\n" );
    }

}
