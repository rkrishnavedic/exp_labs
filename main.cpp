#define KR1shna

#ifdef KR1shna
#include "Header.h"
#else
#include <bits/stdc++.h>
#endif

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define sp(n) setprecision(n)
#define mkp make_pair
#define mkt make_tuple
#define pi 3.14159265358979323846264
#define d7 1000000007
#define l7 998244353

using namespace std;

bool isPrime(long long k){
    if(k<=1){return false;}
    if(k==2){return true;}
    if(k%2==0){return false;}
    long long i = 3;
   while (i*i <= k) {if (k % i == 0) {return false;}i += 2;}
return true;
}

ll binomialCoeff(ll n, ll k){
    ll C[n + 1][k + 1];ll i, j;
    for (i = 0; i <= n; i++){
        for (j = 0; j <= min(i, k); j++){
            if (j == 0 || j == i){C[i][j] = 1;}
            else{C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);}}}
    return C[n][k];
 }

ll gcd(ll a, ll b){if (b == 0)
        return a;return gcd(b, a % b);}

ll expmod(ll n,ll k,ll m){
    ll ans;
    ans=1;
    fori(k){
        ans=(ans*n)%m;
    }
    return ans;
}

void dfs(ll s, vector<bool> &v, vector<ll> adj[]){
    if(v[s]) return;
    v[s]=true;
    cout<<s+1<<" ";
    for(auto u: adj[s]){
        dfs(u,v,adj);
    }
}

//some definitions and global variables >>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<
vector<ll> primes;
void storePrime(ll n){
    fori(n){
        if(isPrime(i+1)&&(n%(i+1)==0)){primes.push_back(i+1);}
    }
}

void srihrg(){
    //code starts
   
    ll n,k;
    cin>>n;
    vector<ll> adj[n];
    cin>>k;
    fori(k){
        ll x,y;
        cin>>x>>y;
        x--;y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    vector<bool> visited(n);
    dfs(0,visited,adj);
    
    //code ends
}

int main(int argc, const char * argv[]) {
#ifdef KR1shna
    cout<<"||ओ३म्||"<<endl;
#endif
 //make cin/cout faster
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);cout.tie(NULL);
// code now

    ll t=1;
    //cin>>t;
    ll nt=1;
    while(t--){
        cout<<"Case #"<<nt<<": ";
        srihrg();
        nt++;
        cout<<endl;
    }
    
//code ends
    return 0;
}
