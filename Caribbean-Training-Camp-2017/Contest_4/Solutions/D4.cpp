#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2000;

int from[MAXN];
bool mk[MAXN];

vector<int> g[MAXN];

bool dfs( int u ){
    if( mk[u] ){
        return false;
    }

    mk[u] = true;

    for( int i = 0; i < g[u].size(); i++ ){
        int v = g[u][i];
        if( from[v] == -1 || dfs( from[v] ) ){
            from[v] = u;
            return true;
        }
    }

    return false;
}

typedef pair<int,int> par;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};

int id[MAXN][MAXN];

int n, m;
int wx[MAXN], wy[MAXN];
int bx[MAXN], by[MAXN];
int used[MAXN][MAXN];

inline bool inside(int x, int a, int b) {
    return (a <= x && x <= b);
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    // freopen("dat.txt","r",stdin);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        used[x][y] = true;
    }

    int w = 0;
    int b = 0;
    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (!used[x][y]) {
                //cerr << "  " << x << " " << y << " ";
                if ((x & 1) == (y & 1)) {
                    //cerr << " w" << w << "\n";
                    id[x][y] = w;
                    wx[w] = x;
                    wy[w] = y;
                    w++;
                } else {
                    //cerr << " b" << b << "\n";
                    id[x][y] = b;
                    bx[b] = x;
                    by[b] = y;
                    b++;
                }
            }
        }
    }

    if (w != b) {
        cout << "No\n";
        return 0;
    }

    for (int x = 1; x <= n; x++) {
        for (int y = 1; y <= n; y++) {
            if (!used[x][y] && ((x & 1) == (y & 1))) {
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if (inside(nx, 1, n) && inside(ny, 1, n)) {
                        if (!used[nx][ny]) {
                            //cerr << "edge: " << id[x][y] << " " << id[nx][ny] << "\n";
                            //cerr << "  " << x << " " << y <<  " " << nx <<  " " << ny << "\n";
                            g[id[x][y]].push_back(id[nx][ny]);
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < b; i++) {
        from[i] = -1;
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < w; j++) {
            mk[j] = false;
        }
        if (!dfs(i)) {
            cout << "No\n";
            return 0;
        }
    }

    vector <pair <int, int> > h, v;

    for (int i = 0; i < b; i++) {
        int p = from[i];
        //cerr << p << " " << i << "\n";
        //cerr << "-->> " << wx[p] << " " << wy[p] << "\n";
        //cerr << "-->> " << bx[i] << " " << by[i] << "\n";
        if (wx[p] == bx[i]) {
            v.push_back(make_pair(wx[p], min(wy[p], by[i])));
        } else {
            h.push_back(make_pair(min(wx[p], bx[i]), wy[p]));
        }
    }
    cout << "Yes\n";
    cout << h.size() << "\n";
    for (int i = 0; i < h.size(); i++) {
        cout << h[i].first << " " << h[i].second << "\n";
    }
    cout << v.size() << "\n";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}
