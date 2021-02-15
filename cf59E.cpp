//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include<bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define eps 1e-10
#define eq(x,y) (fabs((x)-(y)) < eps)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int>pii;
const ll mod = 998244353;
long double pi = acosl(-1);
const ll infl = 1e17+100;
const int inf = 1e9+100;
const int nmax = 3000+5;
//const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

vector<int>g[nmax];

int dst[nmax][nmax];
pii from[nmax][nmax];
set<pii>bad[nmax];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m,k;
    cin>>n>>m>>k;
    for(int i=0; i<m; i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=0; i<k; i++){
        int a,b,c;
        cin>>a>>b>>c;
        bad[b].insert( {a,c} );
    }

    for(int i=1; i<=n; i++) for(int j=1; j<=n; j++) dst[i][j] = inf;

    dst[1][1] = 0;
    queue<pii>q;
    q.push({1,1});
    while(!q.empty()){
        pii zz = q.front();
        q.pop();
        int u = zz.first, v = zz.second;
        for(int x : g[u]){
            if( bad[u].find( {v, x} ) != bad[u].end() ) continue;
            if( dst[x][u] > dst[u][v] + 1 ){
                dst[x][u] = dst[u][v] + 1;
                from[x][u] = { u, v };
                q.push( {x,u} );
            }
        }
    }
    int secondlast = -1, mn = inf;
    for(int i=1; i<=n; i++){
        if(dst[n][i]<mn){
            secondlast = i;
            mn = dst[n][i];
        }
    }
    vector<int>path;
    if(mn!=inf){
        int cur = n;
        path.push_back(n);
        path.push_back(secondlast);
        while(secondlast!=1){
            int tmp = from[cur][secondlast].second;
            cur = secondlast, secondlast = tmp;
            path.push_back(tmp);
        }
    }
    if(mn==inf)
        cout<<-1<<"\n";
    else{
        cout<<mn<<"\n";
        reverse(path.begin(), path.end());
        for(int x : path) cout<<x<<" ";
    }

}
/*
*/
