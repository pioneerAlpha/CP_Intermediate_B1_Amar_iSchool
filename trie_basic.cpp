
int tri[nmax][26]; /// nodenumber , character -> nodnumber
int nodnum = 0;
int isleaf[nmax];
int cnt[nmax];

void adstring(string s){
    int cur = 0;
    for(char ch : s){
        int x = int(ch-'a');
        if(tri[cur][x]==-1) tri[cur][x] = ++nodnum;
        cur = tri[cur][x];
        cnt[cur]++;
    }
    isleaf[cur]++ ;
}

int query(string s){
    int cur = 0;
    int ans = 0;
    for(char ch : s){
        int x = int(ch-'a');
        for(int j=0; j<x; j++) if(tri[cur][j]!=-1){
            ans += cnt[ tri[cur][j] ];
        }
        if(tri[cur][x]==-1) tri[cur][x] = ++nodnum;
        cur = tri[cur][x];
        ans += isleaf[cur];
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(tri, -1, sizeof tri);

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        string s;
        cin>>s;
        adstring(s);
    }
}
