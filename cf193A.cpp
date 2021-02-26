//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-4
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod = 998244353;
long double pi = acosl(-1);
const ll infl = 1e17+100;
const int inf = 1e9+100;
const int nmax = 2e5+5;
//const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

vector<int>g[nmax];
int shomoy = 0;
int intime[nmax], lowtime[nmax];
bool vis[nmax];
bool iscutnode[nmax];

void dfs(int u, int p=-1){
    vis[u] = true;
    intime[u] = lowtime[u] = ++shomoy;
    int child = 0;
    for(int v : g[u]) if(v!=p){
        if(vis[v]){
            lowtime[u] = min(lowtime[u], intime[v]);
        }
        else{
            dfs(v, u);
            lowtime[u] = min(lowtime[u], lowtime[v]);
            child++;
        }
    }
    if( intime[u] <= lowtime[u] and child>0) {
        iscutnode[u] = true;
    }
    if( p==-1 and child > 1 ){
        iscutnode[u] = true;
    }
}


int n,m;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};

vector<string>s;

/// 0 1 2 3 4 5 m-1
/// m m+1 m+2 ....
///.......... nm-1

bool ok(int i, int j){
    if(i<n and i>=0 and j<m and j>=0){
        if(s[i][j]=='#') return true;
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    s.resize(n);
    for(auto &z : s) cin>>z;
    int koyta = 0;

    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        if(s[i][j]!='#') continue;
        koyta++;
        for(int k=0; k<4; k++){
            if( ok(i+di[k], j+dj[k]) ){
                int i2 = i+di[k], j2 = j+dj[k];
                g[ i*m+j ].push_back( i2*m+j2  );
            }
        }
    }

    bool done = false;
    for(int i=0; i<n and !done; i++) for(int j=0; j<m and !done; j++){
        if(s[i][j]=='#'){
            done = true;
            dfs( i*m+j );
        }
    }

    for(int i=0; i<n; i++) for(int j=0; j<m; j++){
        if(s[i][j]=='#'){
            if(iscutnode[i*m+j]){
                cout<<"1", exit(0);
            }
        }
    }
    if(koyta<=2) cout<<"-1";
    else cout<<2<<"\n";
}
/*
*/
