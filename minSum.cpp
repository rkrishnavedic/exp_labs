#include <bits/stdc++.h>

#define fori(n) for(int i=0;i<n;i++)

using namespace std;

int min_index(int arr[],int n, int l, int u){
    int s=u;
    fori(u-l){
        if(arr[i+l]<arr[s]){s=i+l;}
    }
    return s;
}

int miniSum(int arr[],int n, int l, int u){
    int v=0,sum=0;
    if(l<n && u<n && l<=u && l>=0 && u>=0){
        v=min_index(arr, n, l, u);
        sum=arr[v]*(u-v+1)*(v-l+1);
        return miniSum(arr, n, l, v-1)+miniSum(arr, n, v+1, u)+sum;
    }
    else{
        return 0;
    }
}

int main(){
    //cout<<"Om\n";
    int n;
    cin>>n;
    int arr[n];
    
    fori(n) cin>>arr[i];
    cout<<miniSum(arr, n, 0, n-1);
    
    
    return 0;
}
