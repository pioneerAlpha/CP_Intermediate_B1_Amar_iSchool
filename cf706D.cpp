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
const int nmax = 6e5+5;
//const int MAXLG = log2(nmax)+1;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
//typedef tree< int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ost;


int tri[nmax][2]; /// nodenumber , character -> nodnumber
int nodnum = 0;
int isleaf[nmax];
int cnt[nmax];

void adstring(int x){
    int cur = 0;
    cnt[cur]++;
    for(int i=29; i>=0; i--){
        int k = 0;
        if(x>>i&1) k = 1;
        if( tri[cur][k] == -1) tri[cur][k] = ++nodnum;
        cur = tri[cur][k];
        cnt[cur]++;
    }
}

void delett(int x){
    int cur = 0;
    cnt[cur]--;
    for(int i=29; i>=0; i--){
        int k = 0;
        if(x>>i&1) k = 1;
        cur = tri[cur][k];
        cnt[cur]--;
    }
}

int query(int x){
    int cur = 0;
    int ans = 0;
    for(int i=29; i>=0; i--){
        int k = 1;
        if(x>>i&1) k = 0;
        if(  tri[cur][k] != -1 and cnt[ tri[cur][k] ]!=0 ){
            ans ^= (1<<i);
            cur = tri[cur][k];
        }
        else if( tri[cur][k^1]  !=-1 and cnt[ tri[cur][k^1] ]!=0 ){
            cur = tri[cur][k^1];
        }
        else break;
    }
    return ans;
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    memset(tri, -1, sizeof tri);

    int q;
    cin>>q;
    while(q--){
        char typ;
        int x;
        cin>>typ>>x;
        if(typ=='+'){
            adstring(x);
        }
        else if(typ=='-'){
            delett(x);
        }
        else{
            cout<<query(x)<<"\n";
        }
    }

}
/*
*/
