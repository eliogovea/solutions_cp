// 2014-2015 CT S02E03: Codeforces Trainings Season 2 Episode 3 (NCPC 2008 + USACO DEC07 + GCJ 2008 Qual)
// 100494L

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000;

struct ev{
    int time;
    bool arr;
    bool a;

    ev(){}

    bool operator < ( const ev &o ) const {
        if( time == o.time ){
            if( arr ){
                return true;
            }
            return false;
        }
        return time < o.time;
    }
};

ev s[MAXN];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("in.txt","r",stdin);

    int TC; cin >> TC;

    for( int tc = 1; tc <= TC; tc++ ){
        int t; cin >> t;

        int na, nb; cin >> na >> nb;

        int sz = 0;

        for( int i = 0; i < na; i++ ){
            string x; cin >> x;
            int time = 0;
            time = x[0] - '0';
            time *= 10;
            time += x[1] - '0';
            time *= 60;

            int time2 = x[3] - '0';
            time2 *= 10;
            time2 += x[4] - '0';
            time += time2;

            s[sz].time = time;
            s[sz].arr = false;
            s[sz++].a = true;

            cin >> x;
            time = 0;
            time = x[0] - '0';
            time *= 10;
            time += x[1] - '0';
            time *= 60;

            time2 = x[3] - '0';
            time2 *= 10;
            time2 += x[4] - '0';
            time += time2;

            s[sz].time = time + t;
            s[sz].arr = true;
            s[sz++].a = false;
        }

        for( int i = 0; i < nb; i++ ){
            string x; cin >> x;
            int time = 0;
            time = x[0] - '0';
            time *= 10;
            time += x[1] - '0';
            time *= 60;

            int time2 = x[3] - '0';
            time2 *= 10;
            time2 += x[4] - '0';
            time += time2;

            s[sz].time = time;
            s[sz].arr = false;
            s[sz++].a = false;

            x; cin >> x;
            time = 0;
            time = x[0] - '0';
            time *= 10;
            time += x[1] - '0';
            time *= 60;

            time2 = x[3] - '0';
            time2 *= 10;
            time2 += x[4] - '0';
            time += time2;

            s[sz].time = time + t;
            s[sz].arr = true;
            s[sz++].a = true;
        }

        sort( s , s + sz );

        int a = 0, b = 0;
        int solA = 0, solB = 0;

        for( int i = 0; i < sz; i++ ){
            if( s[i].arr ){
                if( s[i].a ){
                    a++;
                }
                else{
                    b++;
                }
            }
            else{
                if( s[i].a ){
                    if( a > 0 ){
                        a--;
                    }
                    else{
                        solA++;
                    }
                }
                else{
                    if( b > 0 ){
                        b--;
                    }
                    else{
                        solB++;
                    }
                }
            }
        }

        cout << "Case #" << tc << ": " << solA << ' ' << solB << '\n';
    }
}
