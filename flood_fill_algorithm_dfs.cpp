//#define Bharatvarsh

#ifndef Bharatvarsh
#include <bits/stdc++.h>
#else
#include "total.h"
#endif
#define fori(n) for(long long i=0;i<n;i++)
#define forr(i,x,y) for(long long i=x;i<y;i++)
#define forj(n) for(long long j=0;j<n;j++)
#define ll long long
#define d7 1000000007
#define en cout<<endl;
#define S second
#define F first
#define pii pair<int,int>
#define pll pair<ll,ll>

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

ll modexp(ll x, ll n,ll m){
    if(n==0) return 1%m;
    ll u=modexp(x,n/2,m);
    u=(u*u)%m;
    if(n%2==1) u=(u*x)%m;
    return u;
}

ll modinv(ll x, ll mod) { return modexp(x, mod - 2, mod); }
const int Nx=1e6+5;
ll fact[Nx];
void factorial(){fact[0]=1;
    for(int i=1;i<Nx;i++)
    {
        fact[i]=(fact[i-1]*i)%d7;
    }
    return ;}
ll binomial(ll a,ll b,ll mod){
    return ((fact[a]*modinv(fact[b],mod))%mod*modinv(fact[a-b],mod))%mod;}

ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}

//=======Template Graphs==============++++++++++++++
//template<typename T>

class Graph{
    
    map<pll, vector<pll>> adj;
    
public:
    void addEdge(pll x, pll y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    void bfs(pll start){
        map<pll, bool> visited;
        queue<pll> q;
        q.push(start);
        //dist[1]=0;
        
        visited[start]=true;
        
        while(!q.empty()){
            pll u=q.front();
            q.pop();
            //cout<<u<<" ";
            for(auto h: adj[u]){
                if(!visited[h]){
                    q.push(h);
                    visited[h]=true;
                    //dist[h]=dist[u]+1;
                }
            }
            
        }
    }
    
    void dfs(pll start, vector<string> &v, char color){
        map<pll, bool> visited;
        dfs_help(start, visited , v, color);
    }
    
    void dfs_help(pll help, map<pll,bool> &visited, vector<string> &v, char color){
        visited[help]=true;
        v[help.F][help.S]=color;
        //cout<<help<<" ";
        for(auto h: adj[help]){
            if(!visited[h]){
                dfs_help(h, visited, v, color);
            }
        }
        return;}
    
};

vector<vector<ll> > multiplymatrix(vector<vector<ll>> M, vector<vector<ll>> N, ll size, ll p){
    vector<vector<ll> > ans(size, vector<ll>(size,0));
    
    fori(size){
        forj(size){
            for(ll h=0;h<size;h++){
                ans[i][j]=(ans[i][j]+M[i][h]*N[h][j])%p;
            }
        } }
        return ans;
}
    

vector<vector<ll> > matrixexp(vector<vector<ll> > &v, ll n, ll k, ll p){
    
    vector<vector<ll> > identity(k,vector<ll>(k,0));
    fori(k) identity[i][i]=1;
    
    if(n==0){
        return identity;
    }
    
    vector<vector<ll> > M = matrixexp(v, n/2, k,p);
        vector<vector<ll> > ah= multiplymatrix(M,M,k,p);
    if(n%2==1){
        return multiplymatrix(ah, v, k,p);
    }
    
    return ah;
    
}

string addintstrreverse(string s,string t){
 
    if(s.size()>t.size()){
        return addintstrreverse(t, s);
    }
    string ans;
    ll carry=0;
    fori(s.size()){
        ans.push_back(((s[i]-'0')+(t[i]-'0')+carry)%10+'0');
        carry=((s[i]-'0')+(t[i]-'0')+carry)/10;
    }
    fori(t.size()-s.size()){
        ans.push_back(((t[i+s.size()]-'0')+carry)%10 + '0');
        carry=(carry+ (t[i+s.size()]-'0'))/10;
    }
    while(carry>0){
        ans.push_back(carry%10+'0');
        carry/=10;
    }
    return ans;
}

string multiplyintstrreverse(string s, string t){
    if(s.size()>t.size()){
        return multiplyintstrreverse(t, s);
    }
    
    string ans;
    ll n=s.size();
    vector<string> v(n);
    
    fori(n){
        forj(i){
            v[i].push_back('0');
        }
    }
    
    fori(n){
        ll carry=0;
        forj(t.size()){
            v[i].push_back(((s[i]-'0')*(t[j]-'0')+carry)%10+'0');
            carry=(carry+(s[i]-'0')*(t[j]-'0'))/10;
        }
        while(carry>0){
            v[i].push_back(carry%10+'0');
            carry/=10;
        }
    }
    string temp;
    fori(n){
        temp=addintstrreverse(v[i], ans);
        ans.clear();
        ans=temp;
        temp.clear();
    }
    
    return ans;
    
}

string minus2intstrrevrse(string s){
    string ans;
    
    if(s[0]-'0'>1){
        ans=s;
        ans[0]=((s[0]-'0')-2)+'0';
    }
    else{
         ll h=1;
        if(s[0]=='1'){
            ans.push_back('9');
                      
                       while(s[h]=='0'&&h<s.size()){
                           ans.push_back('9');
                           h++;
                       }
            ans.push_back(s[h]-'0'-1+'0');h++;
        }else{
            ans.push_back('8');
           
            while(s[h]=='0'&&h<s.size()){
                ans.push_back('9');
                h++;
            }
            ans.push_back(s[h]-'0'-1+'0');h++;
        }
        while(h<s.size()){
            ans.push_back(s[h]);
            h++;
        }
    }
    
    return ans;
}

//----++++-----Place all fuctions above and coding below---++++----

vector<ll> primes;

void solution(){
    
    ll n,m;cin>>n>>m;
    vector<string> graph(n);
    
    fori(n) cin>>graph[i];
    
    Graph g;
    
    ll x[4]= {1,-1,0,0};
    ll y[4]={0,0,1,-1};
    
    fori(n){
        forj(m){
            for(ll h=0;h<4;h++){
            if(i+x[h]>=0 && i+x[h]<n && j+y[h]<m && j+y[h]>=0){
                if(graph[i+x[h]][j+y[h]]!='#' && graph[i][j]!='#'){
                    g.addEdge({i+x[h],j+y[h]}, {i,j});
                }
            }}
        }
    }
    
    cout<<" Number of iterations: ";
    ll t; cin>>t;
    while(t--){
        cout<<"Input x <space> y, to fill colour on the connected region (x,y) : ";
        ll h,k;
        cin>>h>>k;
        if(h<0||h>n||k>m||h<0){
            cout<<"wrong co-ordinates\n";
        }else{
        if(graph[h][k]!='#'){
            cout<<" Colour to fill : ";
            char color;cin>>color;
            g.dfs({h,k}, graph, color);
            fori(n){
                cout<<graph[i]<<endl;
            }
            en;
        }else{
            cout<<"can't fill colour here\n";
        }
    }
    }
    
}


int main(){
    
//    int N=40000;
//
//    vector<bool> f(N,true);
//    primes.push_back(2);
//
//    for(ll i=3;i<N;i+=2){
//        while(i<N&& !f[i]) i+=2;
//        if(i<N && f[i]){
//            primes.push_back(i);
//
//        for(ll j=2*i;j<N;j+=i){
//            f[j]=false;
//        }}
//    }
    
    ll t=1;
    //cin>>t;
    
    while(t--){
        
    
        solution();
    
        cout<<endl;
    }
    
    return 0;
}
