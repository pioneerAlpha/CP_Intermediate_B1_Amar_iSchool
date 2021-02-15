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
vector<pii>grev[nmax];
int dsts[nmax], dstt[nmax];


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tc;
    cin>>tc;
    for(int ces=1; ces<=tc; ces++){

        int n,m,s,t,p;
        cin>>n>>m>>s>>t>>p;

        vector< pair<pii, int> >ejes;
        for(int i=0; i<m; i++){
            int u,v,w;
            cin>>u>>v>>w;
            g[u].push_back({v,w});
            grev[v].push_back({u,w});
            ejes.push_back( {{u,v} , w } );
        }
        for(int i=1; i<=n; i++){
            dsts[i] = dstt[i] = inf;
        }
        priority_queue< pii >pq; /// {-dist, node}
        dsts[s] = 0;
        pq.push({0, s});
        while(!pq.empty()){
            auto z = pq.top();
            pq.pop();
            int u = z.second, d = -z.first;
            if(dsts[u]!=d) continue;
            for(pii v : g[u]){
                if( v.second + dsts[u] < dsts[v.first] ){
                    dsts[ v.first ] = v.second + dsts[u];
                    pq.push( { -dsts[v.first] , v.first } );
                }
            }
        }
        dstt[t] = 0;
        pq.push({0, t});
        while(!pq.empty()){
            auto z = pq.top();
            pq.pop();
            int u = z.second, d = -z.first;
            if(dstt[u]!=d) continue;
            for(pii v : grev[u]){
                if( v.second + dstt[u] < dstt[v.first] ){
                    dstt[ v.first ] = v.second + dstt[u];
                    pq.push( { -dstt[v.first] , v.first } );
                }
            }
        }

        int ans = -1;
        for(auto z : ejes){
            int u = z.first.first, v = z.first.second, w = z.second;
            if( dsts[u] + w + dstt[v] <= p){
                ans = max(ans, w);
            }
        }

        cout<<"Case "<<ces<<": "<<ans<<"\n";
        for(int i=0; i<=n; i++) g[i].clear(), grev[i].clear();
    }
}
/*
*/
