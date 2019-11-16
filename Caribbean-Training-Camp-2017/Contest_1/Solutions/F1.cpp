#include <bits/stdc++.h>

using namespace std;

const int oo = 1000 * 1000 * 1000 + 1000;

typedef pair<int,int> par;

struct node;
typedef node* pnode;
struct node{
    int value;
	int min_value;

	par key;
	int pri, siz;//prioridad y size
	pnode l, r;

	node(par key , int value){
		this->value = value;
		this->min_value = value;
		this->key = key;
		pri = rand();
		siz = 1;
		l = NULL;
		r = NULL;
	}
};

pnode root;

inline int size(pnode t){
	return t == NULL ? 0 : t->siz;
}

inline int min_value( pnode t ){
    return t == NULL ? oo : t->min_value;
}

void update(pnode t){
	if (t != NULL){
		t->siz = size(t->l) + size(t->r) + 1;
		t->min_value = min( t->value , min( min_value( t->l ) , min_value( t->r ) ) );
	}
}

void split(pnode t, par key, pnode &l, pnode &r){
    if(!t){ l=r=NULL; return; }
    if(t->key <= key)
        split(t->r, key, t->r, r), l = t, update(l);
    else split(t->l, key, l, t->l), r = t, update(r);
}

pnode merge(pnode l, pnode r){
	pnode result = NULL;

	if (l == NULL || r == NULL) result = (l == NULL ? r : l);
	else if (l->pri > r->pri) l->r = merge(l->r, r), result = l;
	else r->l = merge(l, r->l), result = r;
    update(result);

	return result;
}

void insert(par key, int value){
	pnode n = new node(key , value);
	pnode l, r;
	split(root, key, l, r);
	root = merge(l, n);
	root = merge(root, r);
}

void kprint( pnode t ){
    if( t == NULL ){
        return;
    }

    kprint( t->l );
    cerr << "("<< t->key.first << '-' << t->key.second << ")  ";
    kprint( t->r );
}

void erase( par key ){
    pnode l , r;
    split( root , key , l , r );
    split( l , par( key.first , key.second-1 ) , l , root );
    root = merge( l , r );

    //cerr << "SIZE(l) = " << size(l) << '\n';
    //kprint(l);

}

void clear(){
    root = NULL;
}

struct seg{
    int l, r;
    int p;
    seg(){}
    seg( int l, int r, int p ){
        this->l = l;
        this->r = r;
        this->p = p;
    }

    bool operator < ( const seg &o ) const {
        if( l != o.l ){
            return l < o.l;
        }

        return r < o.r;
    }
};

const int MAXN = 1000100;
seg segs[MAXN];

int maxv = 0;
int n, K;
bool yes[MAXN];
vector<int> erase_op[MAXN];
vector<int> insert_op[MAXN];

bool ok( int L ){
    clear();
    for( int i = 0; i <= maxv; i++ ){
        erase_op[i].clear();
        insert_op[i].clear();
        yes[i] = false;
    }

    yes[0] = true;

    int ind_seg = 1;

    for( int i = 1; i <= K; i++ ){ //cerr << "i = " << i << '\n';
        //cerr << "BEGIN WITH  --->  SIZE == " << size(root) << '\n';

        for( int j = 0; j < insert_op[i].size(); j++ ){
            int id = insert_op[i][j];
            insert( par( segs[id].p , id ) , segs[id].r );
            //cerr << " inserting ----> id = (" << segs[id].p << "-" << id << ")" << '\n';
        }

        for( int j = 0; j < erase_op[i].size(); j++ ){
            int id = erase_op[i][j];
            //cerr << " deleting <---- id =  (" << segs[id].p << "-" << id << ")" << '\n';
            erase( par( segs[id].p , id ) );
        }

        //cerr << "END WITH   ---->  SIZE == " << size(root) << '\n';

        while( ind_seg <= n && segs[ind_seg].l <= i ){
            if( segs[ind_seg].p > L ){
                ind_seg++;
                continue;
            }

            //cerr << "ind_seg == " << ind_seg << '\n';
            //cerr << "l = " << segs[ind_seg].l << "  r = " << segs[ind_seg].r << '\n';

            if( yes[i-1] ){
                insert_op[ segs[ind_seg].l+1 ].push_back( ind_seg );
                erase_op[ segs[ind_seg].r+1 ].push_back( ind_seg );
                yes[ segs[ind_seg].r ] = true;
                //cerr << "---------kk----------->yes\n";
            }
            else{
                pnode l, r;
                split( root , par( L - segs[ind_seg].p , oo ) , l , r );
                if( l != NULL && l->min_value < segs[ind_seg].r ){
                    insert_op[ l->min_value + 1 ].push_back( ind_seg );
                    erase_op[ segs[ind_seg].r+1 ].push_back( ind_seg );
                    yes[ segs[ind_seg].r ] = true;
                    //cerr << "----------------------->yes\n";
                }
                root = merge( l , r );
            }

            ind_seg++;
        }
    }

    return yes[K];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);

    cin >> n >> K;

    vector<int> vs;
    vs.push_back(1);
    vs.push_back(K);

    for( int i = 1; i <= n; i++ ){
        cin >> segs[i].l >> segs[i].r >> segs[i].p;
        vs.push_back( segs[i].l );
        vs.push_back( max( segs[i].l-1 , 1 ) );

        vs.push_back( segs[i].r );
        vs.push_back( max( segs[i].r-1 , 1 ) );
    }

    sort( vs.begin() , vs.end() );
    vs.erase( unique( vs.begin() , vs.end() ), vs.end() );

    K = lower_bound( vs.begin() , vs.end() , K ) - vs.begin() + 1;
    maxv = vs.size() + 5;

    bool exist1 = false, existK = false;

    for( int i = 1; i <= n; i++ ){
        segs[i].l = lower_bound( vs.begin() , vs.end() , segs[i].l ) - vs.begin() + 1;
        segs[i].r = lower_bound( vs.begin() , vs.end() , segs[i].r ) - vs.begin() + 1;

        exist1 |= (segs[i].l == 1);
        existK |= (segs[i].r >= K);
    }

    if( !exist1 || !existK ){
        cout << "-1\n";
        return 0;
    }

    sort( segs + 1 , segs + 1 + n );

    /*for( int i = 1; i <= n; i++ ){
        cerr << segs[i].l << ' ' << segs[i].r << ' ' << segs[i].p << '\n';
    }

    cerr << "K = " << K << '\n';

    if( ok(5) ){
        cerr << "YES\n";
    }
    else{
        cerr << "NO\n";
    }

    return 0;*/

    int sol = -1;
    int ini = 1, fin = 2000000001;
    while( ini <= fin ){
        int mid = ( (long long)ini + (long long)fin ) / (long long)2; //cerr << "mid = " << mid << '\n';
        if( ok( mid ) ){
            sol = mid;
            fin = mid-1;
        }
        else{
            ini = mid+1;
        }
    }

    cout << sol << '\n';
}
