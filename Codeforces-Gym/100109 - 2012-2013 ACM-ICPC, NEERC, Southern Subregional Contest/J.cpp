// 2012-2013 ACM-ICPC, NEERC, Southern Subregional Contest
// 100109J

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen("dat.txt","r",stdin);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int cnt[3];
    int n; cin >> n >> cnt[0] >> cnt[1];
    cnt[2] = n - cnt[0] - cnt[1];

    if( cnt[2] < 0 ){
        cout << "-1\n";
        return 0;
    }

    string s; cin >> s;

    int c0 = 0, c1 = 0, c2 = 0;

    for( int i = 0; i < n; i++ ){
        if( s[i] == '0' ){
            c0++;
        }
        else if( s[i] == '1' ){
            c1++;
        }
        else{
            c2++;
        }
    }

    int sol = 0;

    for( int i = 0; i < n; i++ ){
        if( s[i] == '0' ){
            if( c0 > cnt[0] ){
                c0--;
                sol++;

                if( c1 < cnt[1] ){
                    s[i] = '1';
                    c1++;
                }
                else{
                    s[i] = '2';
                    c2++;
                }
            }
        }
        else if( s[i] == '1' ){
            if( c1 > cnt[1] ){
                c1--;
                sol++;

                if( c0 < cnt[0] ){
                    s[i] = '0';
                    c0++;
                }
                else{
                    s[i] = '2';
                    c2++;
                }
            }
        }
        else{
            if( c2 > cnt[2] ){
                c2--;
                sol++;

                if( c1 < cnt[1] ){
                    s[i] = '1';
                    c1++;
                }
                else{
                    s[i] = '0';
                    c0++;
                }
            }
        }
    }

    cout << sol << '\n';
    cout << s << '\n';
}
