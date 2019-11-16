// 2016-2017 CT S03E01: Codeforces Trainings Season 3 Episode 1 - 2010 Benelux Algorithm Programming Contest (BAPC 10)
// 101078I

#include <bits/stdc++.h>

using namespace std;

list<char> pass;
list<char>::iterator p, aux;
void go_left(  ){
    if( p == pass.begin() )
        return;
    p--;
}
void go_right(  ){
    if( p == pass.end() )
        return ;
    p++;
}
void backspace(  ){
    if( p == pass.begin() )
        return;
    aux = p; aux--;
    pass.erase( aux );
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    //freopen( "dat.txt", "r", stdin );

    int tc;
    cin >> tc;
    string command;
    while( tc-- ){
        pass.clear();
        p = pass.end();
        cin >> command;
        for( int i = 0; i < command.size(); i++ ){
            char c = command[i];
            if( c == '<' )
                go_left();
            else if( c == '>' )
                go_right();
            else if( c == '-' )
                backspace();
            else{
                pass.insert( p, c );
            }

        }
        for( p = pass.begin() ; p != pass.end(); p++ )
            cout << *p;
        cout << '\n';
    }

}