#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;

const int nmax = 500+5;

vector<int>g[nmax];
int shomoy = 0;
int intime[nmax], lowtime[nmax];
bool vis[nmax];
bool iscutnode[nmax];

set<pii>bridge;

void dfs2(int u, int p=-1){
    vis[u] = true;
    intime[u] = lowtime[u] = ++shomoy;
    for(int v : g[u]) if(v!=p){
        if(vis[v]){
            lowtime[u] = min(lowtime[u], intime[v]);
        }
        else{
            dfs2(v, u);
            lowtime[u] = min(lowtime[u], lowtime[v]);
            if(lowtime[v] > intime[u] ){
                bridge.insert( {u,v} );
            }
        }
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
