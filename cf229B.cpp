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
vector<int>stop[nmax];
int dst[nmax];

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1; i<=n; i++){
        int k;
        cin>>k;
        for(int j=0; j<k; j++){
            int x;
            cin>>x;
            stop[i].push_back(x);
        }
        sort(stop[i].begin(), stop[i].end());
    }

    for(int i=1; i<=n; i++) dst[i] = inf;
    dst[1] = 0;
    priority_queue<pii>pq;
    pq.push({0, 1});
    while(!pq.empty()){
        pii z = pq.top();
        pq.pop();
        int u = z.second, d = -z.first;
        if(dst[u]!=d) continue;
        int extra = 0, cur = dst[u];
        while( binary_search(stop[u].begin(), stop[u].end(), cur) ) cur++, extra++;
        for(pii v : g[u]){
            if( v.second+ dst[u] + extra < dst[v.first] ){
                dst[v.first] = v.second+ dst[u] + extra;
                pq.push( {-dst[v.first] , v.first } );
            }
        }
    }

    int ans = dst[n];
    if(ans==inf) ans = -1;
    cout<<ans<<"\n";
}
/*
*/
