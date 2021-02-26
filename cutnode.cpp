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
const int nmax = 5e5+5;
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
    if( intime[u] <= lowtime[u] and child>0 and p!=-1) {
        iscutnode[u] = true;
    }
    if( p==-1 and child > 1 ){
        iscutnode[u] = true;
    }
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int u,v;
        cin>>u>>v;
    }
    dfs(1);
}
/*
*/
