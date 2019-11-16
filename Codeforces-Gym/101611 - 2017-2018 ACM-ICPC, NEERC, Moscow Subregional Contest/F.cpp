// 2017-2018 ACM-ICPC, NEERC, Moscow Subregional Contest
// 101611F

#include <bits/stdc++.h>

using namespace std;
const int maxn = 1100;
struct problem{
    char state[5];
    int a, t;
};

struct row{
    int acc, time, last_acc;
    string name;
    bool operator <( const row &b ) const{
        if( acc != b.acc )
            return acc > b.acc;
        if( time != b.time )
            return time < b.time;
        if( last_acc != b.last_acc )
            return last_acc < b.last_acc;
        return name < b.name;
    }
};
row ranking[maxn];
int n, m, k;

string name[maxn];
vector<problem> prob[maxn];
namespace facke{
    string name[maxn];
    vector<problem> prob[maxn];
};

typedef unsigned long long ULL;

int find_and_remplace( int id ){
    for( int i = 0; i < m; i++ ){
        if( name[i] == facke::name[id] ){
            prob[i] = facke::prob[id];
            return i;
        }
    }
    cerr << "error!!!!!" << endl;
}

row get_best_points( int id ){
    row ans = (row){ 0,0,0, "" };
    //cerr << "n: " << n << endl;
    for( int j = 0; j < n; j++ ){
        ans.acc++;
        if( prob[id][j].state[0] == '+' ){
            ans.time += prob[id][j].t + (prob[id][j].a-1)*20;
            ans.last_acc = max( prob[id][j].t, ans.last_acc);
        }
        else{
            ans.time += 240 + prob[id][j].a*20;
            ans.last_acc = max( 240, ans.last_acc);
        }
    }
    ans.name = name[id];
    return ans;
}

bool can_win(  row a,  row b ){
    if( b.acc < n ) return true;

    int id;///find a
    for( int i = 0; i < m; i++ )
        if( a.name == name[i] ){
            id = i;
            break;
        }
    //cerr << "id: " << id << endl;
    row bp = get_best_points( id );
    //cerr << "bp: " << bp.acc << " " << bp.name << " " << bp.time << " " << bp.last_acc << endl;
    return bp < b;

}
bool check( int st ){
    if( st + k > m )
        return false;
    int i, j;
    for( i = 0, j = 0; i < k && st+j < m; i++,j++ ){
        while( st+j < m && facke::name[i] != ranking[st+j].name ){
            //cerr << "se jodio!!!" << endl;
            if( !can_win( ranking[st+j], ranking[st] ) )
                return false;
            j++;
        }

    }
    if( i != k )
        return false;

    return true;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    //freopen( "dat.txt", "r", stdin );
    cin >> n >> m >> k;

    for( int i = 0; i < m; i++ ){
        cin >> name[i];
        prob[i].resize(n);
        for( int j = 0; j < n; j++ ){
            cin >> prob[i][j].state >> prob[i][j].a >> prob[i][j].t;
        }

    }

    for( int i = 0; i < k; i++ ){
        cin >> facke::name[i];
        facke::prob[i].resize(n);
        for( int j = 0; j < n; j++ ){
            cin >> facke::prob[i][j].state >> facke::prob[i][j].a >> facke::prob[i][j].t;
        }
        find_and_remplace( i );
    }
    ///calculate
    for( int i = 0; i < m; i++ ){
        ranking[i].name = name[i];
        for( int j = 0; j < n; j++ ){
            if( prob[i][j].state[0] == '.' || prob[i][j].state[0] == '-' )
                continue;
            if( prob[i][j].state[0] == '+' ){
                ranking[i].acc++;
                ranking[i].time += prob[i][j].t + (prob[i][j].a-1)*20;
                ranking[i].last_acc = max( prob[i][j].t,  ranking[i].last_acc);
            }

        }

    }
    sort( ranking, ranking+m );

   /* for( int i = 0; i < m; i++ ){
        cout << ranking[i].name << " " << ranking[i].acc << " " << ranking[i].time << '\n';

    }*/

    int st = 0;
    while( ranking[st].name != facke::name[0] ) st++;

    if( check( st ) ){
        cout << "Leaked\n";
    }
    else{
        cout << "Fake\n";
    }

}
