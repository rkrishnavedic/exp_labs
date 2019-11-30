#include <bits/stdc++.h>

#define fori(n) for(int i=0;i<n;i++)
#define ll long long

using namespace std;

ll desify(ll n, ll r){
    return n*10+r;
}

int main(){
    //cout<<"Om\n";
    ll n,a=0,b=1,sum=0;
    string s;
    cin>>s;
    n=s.size();
    
    fori(n){
        if(s.at(i)=='+'){
            sum+=a*b;b=1;a=0;
        }
        if(s.at(i)=='-'){
            sum+=a*b;b=-1;a=0;
        }
        if(s.at(i)!='+' && s.at(i)!='-'){
            a=desify(a, s.at(i)-'0');
        }
    }
    sum+=a*b;
    cout<<sum<<endl;
    
    return 0;
}
