int J[nmax], H[nmax];

void dfs(int u){
    if(g[u].size()==0){
        J[u] = false;
        H[u] = true;
    }
    bool canwin = false, canlose = false;
    for(int v : g[u]){
        dfs(v);
        if( ! J[v] ) canwin = true;
        if( ! H[v] ) canlose = true;
    }
    J[u] = canwin;
    H[u] = canlose;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    dfs(0);

    if( J[0] and H[0] ) cout<<"FIRST\n";
    else if( J[0] and !H[0] ) {
        if(k%2) cout<<"FIRST\n";
        else cout<<"SECOND\n";
    }
    else cout<<"SECOND\n";
}
