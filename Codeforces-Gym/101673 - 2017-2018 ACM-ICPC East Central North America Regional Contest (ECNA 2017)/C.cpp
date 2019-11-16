// 2017-2018 ACM-ICPC East Central North America Regional Contest (ECNA 2017)
// 101673C

#include <bits/stdc++.h>

using namespace std;

string s, lo, hi;

int calc_rot( string &ss ){
    int ret = 0;
    for( auto e: ss ){
        ret += e - 'A';
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

  //  freopen("dat.txt","r",stdin);
    cin >> s;
    int n = s.size();

    lo = s.substr(0, n/2);
    hi = s.substr( n/2, n/2 );

   // cout << lo << endl;
    int r_lo = calc_rot(lo);
  //  cout << (char)(('U'-'A'+r_lo)%26 + 'A') << endl;
  //  cerr << "rot: " << r_lo << endl;
    for( int i = 0; i < lo.size(); i++ ){
        lo[i] = (lo[i] - 'A'+r_lo)%26 + 'A';
//        lo[i] += r_lo;
  //      lo[i] %= 26;
  //      lo[i] += 'A';
    }
  //  cerr << lo << endl;
    int r_hi = calc_rot(hi);
    for( int i = 0; i < hi.size(); i++ ){
        hi[i] = (hi[i] - 'A'+r_hi)%26 + 'A';

    }
    //cerr << hi << endl;
    for( int i = 0; i < lo.size(); i++ ){
        lo[i] -= 'A';
        lo[i] += hi[i] - 'A';
        lo[i] %= 26;
        lo[i] += 'A';

    }

    cout << lo << '\n';
}
