// 2008-2009 ACM-ICPC, NEERC, Moscow Subregional Contest
// 100861D

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MAXQ = 100005;
const ll oo = (1ll << 60);

string codes[MAXQ];
map<string,int> ids;
map<int,ll> reliab;
bool exist[MAXQ];

struct node;
typedef node* pnode;
struct node{
    int sum;
    int id;
    pnode L, R;

    node(){
        sum = id = 0;
        L = NULL;
        R = NULL;
    }
    node( int sum, int id ) : sum(sum), id(id), L(NULL), R(NULL) {}
};

void init_nod( pnode nod ){
    if( nod->L == NULL ){
        nod->L = new node();
    }
    if( nod->R == NULL ){
        nod->R = new node();
    }
}

void insert_st( pnode nod, ll l, ll r, ll h, int id ){
    //cerr << "l = " << l << "  r = " << r << '\n';

    //cerr << "---> ini\n";
    init_nod(nod);
    //cerr << "ini -->\n";

    if( l == r ){
        nod->sum = 1;
        nod->id = id;
        return;
    }

    ll mid = (l+r)/2ll;
    pnode L = nod->L;
    pnode R = nod->R;

    if( mid == r ){
        mid = l;
    }

    if( h <= mid ){
        insert_st( L, l, mid, h, id );
    }
    else{
        insert_st( R, mid+1ll, r, h, id );
    }

    nod->sum = L->sum + R->sum;
}

void delete_st( pnode nod, ll l, ll r, ll h ){
    init_nod( nod );

    if( l == r ){
        nod->sum = 0;
        return;
    }

    ll mid = (l+r)/2ll;
    pnode L = nod->L;
    pnode R = nod->R;

    if( mid == r ){
        mid = l;
    }

    if( h <= mid ){
        delete_st( L, l, mid, h );
    }
    else{
        delete_st( R, mid+1ll, r, h );
    }

    nod->sum = L->sum + R->sum;
}

int get_nth( pnode nod, ll l, ll r, ll n ){
    //cerr << "l = " << l << "  r = " << r << '\n';

    init_nod( nod );

    if( l == r ){
        return nod->id;
    }

    ll mid = (l+r)/2ll;
    pnode L = nod->L;
    pnode R = nod->R;

    if( mid == r ){
        mid = l;
    }

    if( L->sum >= n ){
        return get_nth( L, l, mid, n );
    }

    return get_nth( R, mid+1ll, r, n - L->sum );
}

inline ll get_hash( int id ){
    return -reliab[id] * MAXQ + id;
}

void print_st( pnode nod, ll l, ll r ){
    if( l == r ){
        if( nod->sum > 0 ){
            cerr << "id = " << nod->id << "  reliab = " << reliab[nod->id] << '\n';
        }

        return;
    }

    ll mid = (l+r)/2ll;
    pnode L = nod->L;
    pnode R = nod->R;

    if( mid == r ){
        mid = l;
    }

    if( L->sum > 0 ){
        print_st( L, l, mid );
    }
    if( R->sum > 0 ){
        print_st( R, mid+1ll, r );
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    int Q; cin >> Q;

    int sz = 0;
    int ID = 0;

    pnode ro = new node();

    for( int q = 1; q <= Q; q++ ){
        //cerr << "op == " << q << '\n';

        string op; cin >> op;

        if( op == "ISSUE" ){
            string code; cin >> code;
            if( ids.find( code ) == ids.end() ){
                int id = ID++;
                ids[code] = id;
                codes[id] = code;
                reliab[id] = 0ll;
                exist[id] = true;
                sz++;

                //cerr << "--> insert\n";
                insert_st( ro, -oo, oo, get_hash( id ) , id );
                //cerr << "insert -->\n";

                cout << "CREATED " << id << " 0\n";
            }
            else{
                int id = ids[code];
                cout << "EXISTS " << id << " " << reliab[id] << "\n";
            }
        }
        else if( op == "DELETE" ){
            string code; cin >> code;

            auto aux = ids.find( code );

            if( aux != ids.end() && exist[ (*aux).second ] ){
                exist[ (*aux).second ] = false;
                sz--;
                delete_st( ro, -oo, oo, get_hash( (*aux).second ) );

                cout << "OK " << (*aux).second << ' ' << reliab[ (*aux).second ] << '\n';
                ids.erase( aux );
            }
            else{
                cout << "BAD REQUEST\n";
            }
        }
        else if( op == "RELIABILITY" ){
            string code; cin >> code;
            ll m; cin >> m;

            auto aux = ids.find( code );

            if( aux != ids.end() && exist[ (*aux).second ] ){
                delete_st( ro, -oo, oo, get_hash( (*aux).second ) );
                reliab[ (*aux).second ] += m;
                insert_st( ro, -oo, oo, get_hash( (*aux).second ) , (*aux).second );

                cout << "OK " << (*aux).second << ' ' << reliab[ (*aux).second ] << '\n';
            }
            else{
                cout << "BAD REQUEST\n";
            }
        }
        else if( op == "FIND" ){
            int n; cin >> n; n++;

            if( sz == 0 ){
                cout << "EMPTY\n";
            }
            else{
                n = min( n , sz );
                int id = get_nth( ro, -oo, oo, n );
                cout << "OK " << codes[id] << ' ' << id << ' ' << reliab[id] << '\n';

                //print_st( ro, -oo, oo );
            }
        }
    }
}
