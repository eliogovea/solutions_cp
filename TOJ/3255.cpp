//============================================================================
// Name        : Contest2.cpp
// Author      : sUrPRise
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <bits/stdc++.h>


using namespace std;


int z[1000005];

void z_function(string &s){
	for(int i=0;i<=s.size();i++) z[i]=0;
	int L=0,R=0,n = s.length();
	for(int i=1;i<n;i++){
		if(i<=R) z[i] = min(z[i-L], R-i+1);
		while(i+z[i] < n && s[ i+z[i] ] == s[ z[i] ]) z[i]++;
		if(i+z[i]-1 > R) L = i, R = i+z[i]-1;
	}
}

int main(){ //freopen("dat.txt", "r", stdin);
	string p,s;
	int tc; cin >> tc;
	while(tc--){
		cin >> p >> s;
		s = p + '#' + s;
		z_function(s);
		long long ans = 0;
		for(int i=p.size()+1;i+p.size()<=s.size();i++) ans += z[i];
		cout << ans << '\n';
	}
}
