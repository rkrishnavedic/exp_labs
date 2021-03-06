//#define KR1shna

#ifdef KR1shna
#include "Header.h"
#else
#include <bits/stdc++.h>
#endif

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define forj(n) for(long long j=0;j<n;j++)
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

//some definitions and global variables >>>>>>>>>>>>>>>>>>>>>>>>>><<<<<<<<<<<<<<<<<<<<<<<<
vector<ll> primes;
void storePrime(ll n){
    fori(n){
        if(isPrime(i+1)&&(n%(i+1)==0)){primes.push_back(i+1);}
    }
}

void srihrg(){
    //code starts
   
    ll n;
    cin>>n;
    ll a[n];
    fori(n) cin>>a[i];
    vector<pair<ll,ll>> dp(n,{0,-1});
    fori(n){
        dp[i].first=1;
        forj(i){
            if(a[i]>a[j]){
                if(dp[j].first+1 > dp[i].first){
                    dp[i].second = j;
                    dp[i].first=dp[j].first+1;
                }
            }
        }
    }
    ll id=0;
    fori(n){
        if(dp[id].first < dp[i].first){id=i;}
    }
    vector<ll> v;
    while(dp[id].second!=-1){
        v.push_back(a[id]);
        id=dp[id].second;
    }
    v.push_back(a[id]);
    reverse(v.begin(), v.end());
    for(auto x:v){cout<<x<<" ";}
    
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
