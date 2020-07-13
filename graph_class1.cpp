template<typename T>

class Graph{
    
    map<T, vector<T>> adj;
    
public:
    void addEdge(T x, T y){
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    void bfs(T start){
        map<T, bool> visited;
        queue<T> q;
        q.push(start);
        //dist[1]=0;
        
        visited[start]=true;
        
        while(!q.empty()){
            T u=q.front();
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
    
    void dfs(T start){
        map<T, bool> visited;
        dfs_help(start, visited);
    }
    
    void dfs_help(T help, map<T,bool> &visited){
        visited[help]=true;
        //cout<<help<<" ";
        for(auto h: adj[help]){
            if(!visited[h]){
                dfs_help(h, visited);
            }
        }
        return;}
    
    bool cycle_help(T start,map<T,bool> &visited, map<T,T> &parent){
        visited[start]=true;
        for(auto x: adj[start]){
            if(!visited[x]){
                parent[x]=start;
                return cycle_help(x, visited, parent);
            }else{
                if(x!=parent[start]){
                    return true;
                }
            }
        }
        return false;
    }
    
    bool contains_cycle(T start, T parent_initializer_to_start){
        map<T,bool> visited;
        map<T,T> parent;
        parent[start]=parent_initializer_to_start;
        return cycle_help(start, visited, parent);
    }
    
};

//----++++-----Place all fuctions above and coding below---++++----

vector<ll> primes;


void solution(){
  
    Graph<ll> g;
    
    ll n;cin>>n;
    fori(n){
        ll x,y;
        cin>>x>>y;
        g.addEdge(x, y);
    }
    if(g.contains_cycle(1, -1)){
        cout<<"Yes,cycle";
    }
    else{
        cout<<"No cycle";
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
