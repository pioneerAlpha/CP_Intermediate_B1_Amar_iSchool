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
const int nmax = 2e5+5;
//const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ost;

vector<pii>g[nmax];
vector<pii>g2[nmax];

int dst[nmax][12];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin>>tc;
    for(int ces=1; ces<=tc; ces++){

        int n,m,k,d;
        cin>>n>>m>>k>>d;

        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
        }
        for(int i=0; i<k; i++){
            int u,v,w;
            cin>>u>>v>>w;
            g2[u].push_back({v,w});
        }

        for(int i=1; i<=n; i++){
            for(int j=0; j<=d; j++)
                dst[i][j] = inf;
        }
        priority_queue< pair<int, pii> >pq; /// {-dist, node}
        for(int i=0; i<=d; i++){
            dst[0][i] = 0;
        }
        pq.push({0, {0,0} });
        while(!pq.empty()){
            auto z = pq.top();
            pq.pop();
            int u = z.second.first, w = -z.first, x = z.second.second;
            if(dst[u][x]!= w ) continue;
            for(pii v : g[u]){
                if( v.second + dst[u][x] < dst[v.first][x] ){
                    dst[ v.first ][x] = v.second + dst[u][x];
                    pq.push( { -dst[v.first][x] , {v.first,x} } );
                }
            }
            for(pii v : g2[u]) if(x<d) {
                if( v.second + dst[u][x] < dst[v.first][x+1] ){
                    dst[ v.first ][x+1] = v.second + dst[u][x];
                    pq.push( { -dst[v.first][x+1] , {v.first,x+1} } );
                }
            }
        }

        int ans = inf;
        for(int i=0; i<=d; i++){
            ans = min(ans, dst[n-1][i]);
        }
        if(ans==inf) cout<<"Case "<<ces<<": "<<"Impossible"<<"\n";
        else cout<<"Case "<<ces<<": "<<ans<<"\n";

        for(int i=0; i<n; i++) g[i].clear(), g2[i].clear();
    }
}
/*
*/
