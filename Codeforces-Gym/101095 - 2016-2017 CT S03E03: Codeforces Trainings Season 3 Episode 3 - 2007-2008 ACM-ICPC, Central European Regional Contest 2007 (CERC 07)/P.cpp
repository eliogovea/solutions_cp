// 2016-2017 CT S03E03: Codeforces Trainings Season 3 Episode 3 - 2007-2008 ACM-ICPC, Central European Regional Contest 2007 (CERC 07)
// 101095P

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MAXN = 1100;
int n;
struct pt{
    int x,y;
    int id;
};
bool cmpX( const pt&a, const pt&b ){
    if( a.x != b.x )
        return a.x < b.x;
    return a.y  < b.y;
}
bool cmpY( const pt&a, const pt&b ){
    if( a.y != b.y )
        return a.y < b.y;
    return a.x < b.x;
}
pt p[MAXN],org[MAXN];
vector<int> neig[MAXN];
void Join( int a, int b ){
    int id1 = p[a].id,
        id2 = p[b].id;
    neig[ id1 ].push_back( id2 );
    neig[ id2 ].push_back( id1 );
}
bool mk[MAXN];

char getdir( pt a, pt b ){
    if( a.x == b.x ){
        if( a.y > b.y )
            return 'S';
        else
            return 'N';
    }
    if( a.y == b.y ){
        if( a.x > b.x )
            return 'W';
        else
            return 'E';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    while( cin >> n, n ){
        for( int i = 0; i < n; i++ ){
            cin >> p[i].x>> p[i].y ;
            org[i] = p[i];
            p[i].id = i;
            neig[i].clear();
            mk[i] = false;
        }
        sort( p, p+n, cmpX );
        int xx = p[0].id;
        int st = xx;
        for( int i = 0; i < n; i += 2 ){
            Join( i, i+1 );
            //cout << p[i].x << " " << p[i].y << "--->";
            //cout << p[i+1].x << " " << p[i+1].y << endl;
        }
        sort( p, p+n, cmpY );
        for( int i = 0; i < n; i += 2 ){
            Join( i, i+1 );
        }
        mk[xx] = true;
        string sol;
        for( int k = 0; k < 2; k++ ){
            if( org[xx].x == org[ neig[xx][k] ].x ){
                sol += getdir( org[xx], org[ neig[xx][k] ]  );
                xx = neig[xx][k];
                break;
            }
        }
        int p = 0;
        while( !mk[xx] ){
            mk[xx] = true;
            if( xx == 0 )
                p = sol.size();
            for( int k = 0; k < 2; k++ ){
                if( !mk[ neig[xx][k] ] ){
                    sol += getdir( org[xx], org[ neig[xx][k] ] );
                    xx = neig[xx][k];
                    break;
                }
            }
        }
        sol += getdir( org[xx], org[st] );
        sol += sol;
        cout << sol.substr( p, n ) << '\n';;
    }
}
