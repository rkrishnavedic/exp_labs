#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fori(n) for(long long i=0;i<n;i++)
#define d7 1000000007
#define sp(n) setprecision(n)
ll bs(ll v, ll a[],ll i, ll n){
    if(i>n){return -1;}
    if(i==n){
        if(v==a[n])return n;
        else{return -1;}
    }
    if(a[(i+n)/2]==v){
        return (i+n)/2;
    }
    if(a[(i+n)/2]>v){return bs(v,a,i, (i+n)/2);}
    if(a[(i+n)/2]<v){return bs(v,a,(i+n)/2+1,n);}
    return -1;
}

ll eu_dist2(pair<ll, ll> a, pair<ll, ll> b){
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

ll closestPair(vector<pair<ll,ll>> &v, ll a, ll b){
    ll d;
    if(b-a==1){return eu_dist2(v[0],v[1]);}
    if(b-a<1){return d7;}
    ll k=(b-a)/2;
    ll d1=closestPair(v,a,a+k);
    ll d2=closestPair(v,a+k+1,b);
    d=min(d1,d2);
    vector<pair<ll,ll>> x;
    for(ll h=a;h<=b;h++){
        if((v[a+k].first-v[h].first)*(v[a+k].first-v[h].first)<=d){
            x.push_back(v[h]);
        }
    }
    sort(x.begin(), x.end(),[](pair<ll, ll> a, pair<ll, ll> b){
        if(a.second==b.second) return a.first<b.first;
        return a.second>b.second;
    });
    fori(x.size()){
        for(ll j=i+1;j<=15&&j<x.size();j++){
            d=min(eu_dist2(x[i],x[j]),d);
        }
    }
    return d;
}

int main(int argc, const char * argv[]) {
 //cout<<"Om\n";
 //Praise to Lord
 //make cin/cout faster
 ios_base::sync_with_stdio(false);
 cin.tie(NULL);
    
// code now
   ll n;
   cin>>n;
   vector<pair<ll,ll>> v;
   fori(n){
       ll a,b;
       cin>>a>>b;
       v.push_back(make_pair(a,b));
   }
   sort(v.begin(), v.end(), [](pair<ll, ll> a, pair<ll, ll> b){
       if(a.first==b.first){
           return a.second>b.second;
       }
       return a.first<b.first;
   });
   
   cout<<sp(15)<<sqrt((double)closestPair(v, 0, n-1));
    
//code ends
    return 0;
}
