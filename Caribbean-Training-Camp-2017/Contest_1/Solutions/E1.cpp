#include <bits/stdc++.h>

using namespace std;

const int oo = 1000000007;

typedef pair<int,int> par;

struct task{
    int x, y, p, id;

    task(){}
    task( int x, int y, int p, int id ){
        this->x = x;
        this->y = y;
        this->p = p;
        this->id = id;
    }

    bool operator < ( const task &o ) const {
        if( x != o.x ){
            return ( x < o.x );
        }

        if( y != o.y ){
            return y > o.y;
        }

        return p < o.p;
    }
};

bool cmpX( const task &a, const task &b ){
    return a.x < b.x;
}

bool cmpY( const task &a, const task &b ){
    return a.y < b.y;
}

struct st{
    int n;
    vector<task> mx;

    st(){}

    st( int n ){
        this->n = n;
        mx.resize(4*n+4);
    }

    void build_st( int nod, int l, int r, vector<task> &vs ){
        if( l == r ){
            this->mx[nod] = vs[l];
            return;
        }

        int ls = nod * 2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        build_st( ls , l , mid , vs );
        build_st( rs , mid+1 , r , vs );

        this->mx[nod] = max( this->mx[ls] , this->mx[rs] );
    }

    task get_max( int nod, int l, int r, int lq, int rq ){
        if( l > rq || r < lq ){
            return task( -1 , oo , -1 , 0 );
        }

        if( lq <= l && r <= rq ){
            return this->mx[nod];
        }

        int ls = nod*2 , rs = ls + 1;
        int mid = ( l + r ) / 2;

        return max( get_max( ls , l , mid , lq , rq ) ,
                    get_max( rs , mid+1 , r , lq , rq ) );
    }
};


const int MAXN = 300100;

task tasks[MAXN];

st ST[4*MAXN];
int mn_X[4*MAXN];
int mx_X[4*MAXN];
vector<task> r_id[4*MAXN];

void build_st( int nod, int l, int r ){
    mn_X[nod] = tasks[l].x;
    mx_X[nod] = tasks[r].x;
    r_id[nod].resize( r - l + 1 );
    ST[nod] = st( r - l + 1 );

    if( l == r ){
        r_id[nod][0] = tasks[l];
        ST[nod].build_st( 1 , 0 , r - l , r_id[nod] );
        return;
    }

    int ls = nod * 2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    build_st( ls , l , mid );
    build_st( rs , mid+1 , r );

    merge( r_id[ls].begin() , r_id[ls].end() , r_id[rs].begin() , r_id[rs].end() , r_id[nod].begin() , cmpY );
    ST[nod].build_st( 1 , 0 , r - l , r_id[nod] );
}

task query_st( int nod, int l, int r, int x1, int x2, int y1, int y2 ){
    if( mn_X[nod] > x2 || mx_X[nod] < x1 ){
        return task( -1 , oo , -1 , 0 );
    }

    if( x1 <= mn_X[nod] && mx_X[nod] <= x2 ){
        int a = lower_bound( r_id[nod].begin() , r_id[nod].end(), task( 0, y1 , 0 , 0 ) , cmpY ) - r_id[nod].begin();
        int b = lower_bound( r_id[nod].begin() , r_id[nod].end(), task( 0, y2+1 , 0 , 0 ) , cmpY ) - r_id[nod].begin();
        b--;

        if( a > b ){
            return task( -1 , oo , -1 , 0 );
        }

        return ST[nod].get_max( 1 , 0 , r - l , a , b );
    }

    int ls = nod * 2 , rs = ls + 1;
    int mid = ( l + r ) / 2;

    return max( query_st( ls , l , mid , x1 , x2 , y1 , y2 ) ,
                query_st( rs , mid+1 , r , x1 , x2 , y1 , y2 ) );
}

bool cmpX2( const task &a, const task &b ){
    if( a.x != b.x ){
        return a.x < b.x;
    }

    return a.y > b.y;
}

bool cmpY2( const task &a, const task &b ){
    if( a.y != b.y ){
        return a.y < b.y;
    }

    return a.x > b.x;
}

int X[MAXN];
int Y[MAXN];
int P[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int n; cin >> n;
    for( int i = 1; i <= n; i++ ){
        cin >> tasks[i].x >> tasks[i].y >> tasks[i].p;
        tasks[i].id = i;
    }

    sort( tasks + 1 , tasks + 1 + n , cmpX2 );

    for( int i = 1; i <= n; i++ ){
        tasks[i].x = i;
    }

    sort( tasks + 1 , tasks + 1 + n , cmpY2 );

    for( int i = 1; i <= n; i++ ){
        tasks[i].y = i;
    }

    sort( tasks + 1 , tasks + 1 + n , cmpX );

    for( int i = 1; i <= n; i++ ){
        X[ tasks[i].id ] = tasks[i].x;
        Y[ tasks[i].id ] = tasks[i].y;
        P[ tasks[i].id ] = tasks[i].p;

        //cerr << "id = " << tasks[i].id << " ---->  x = " << tasks[i].x << "  y = " << tasks[i].y << '\n';
    }

    build_st( 1 , 1 , n );

    priority_queue<par> pq;
    set<par> g;

    int x = oo, y = 0;
    while( true ){
        task t = query_st( 1 , 1 , n , 0 , x , y , oo );
            //cerr << "zxcxzcxzc" << endl;

        if( t.id == 0 ){
            break;
        }

        pq.push( par( t.p , t.id ) );
        g.insert( par( t.x , t.id ) );

        x = t.x-1;
        y = t.y+1;
    }

    vector<int> sol;

    //cerr << "pqs.size = " << pq.size() << '\n';
    //cerr << "pq.top = " << pq.top().second << '\n';

    while( !pq.empty() ){
        par tmp = pq.top(); pq.pop();
        int id = tmp.second;

        sol.push_back( id );

        int xl = 0;

        set<par>::iterator it = g.find( par( X[id] , id ) );

        if( it != g.begin() ){
            it--;
            xl = it->first;
            it++;
        }

        int yl = 0;
        ++it;
        if( it != g.end() ){
            yl = Y[ it->second ];
        }
        it--;

        g.erase(it);

        int xr = X[id]-1;
        int yr = Y[id]-1;

        //cerr << "xl = " << xl << " xr = " << xr << " yl = " << yl << " yr = " << yr << '\n';
        task t = query_st( 1 , 1 , n , xl , xr , yl , yr );

        //cerr << "next.id = " << t.id << '\n';

        while( t.id ){
            pq.push( par( t.p , t.id ) );
            g.insert( par( t.x , t.id ) );

            xr = t.x-1;
            yl = t.y+1;

            t = query_st( 1 , 1 , n , xl , xr , yl , yr );
        }
    }

    for( int i = 1; i <= n; i++ ){
        cout << sol[i-1] << " \n"[i==n];
    }
}
