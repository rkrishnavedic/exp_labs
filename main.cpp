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
    ll a[n][n];
    fori(n){
        forj(n){
            cin>>a[i][j];
        }
    }
    pair<ll,char> dp[n][n];
    dp[0][0].first=a[0][0];
    dp[0][0].second='0';
    forr(i,1,n){
        dp[i][0].first=dp[i-1][0].first+a[i][0];
        dp[i][0].second='D';
    }
    forr(i,1,n){
        dp[0][i].first=dp[0][i].first+a[0][i];
        dp[0][i].second='R';
    }
    forr(i,1,n){
        forr(k,1,n){
            if(dp[i][k-1].first>dp[i-1][k].first){
                dp[i][k].first=a[i][k]+dp[i][k-1].first;
                dp[i][k].second='R';
            }else{
                dp[i][k].first=a[i][k]+dp[i-1][k].first;
                dp[i][k].second='D';
            }
        }
    }
    string s;
    ll u=n-1,v=n-1;
    while(dp[u][v].second!='0'){
        s.push_back(dp[u][v].second);
        if(dp[u][v].second=='R'){v--;}
        else{u--;}
    }
    reverse(s.begin(), s.end());
    cout<<dp[n-1][n-1].first<<endl<<s;
    
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
