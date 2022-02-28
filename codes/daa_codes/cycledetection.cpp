#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi parent(MAX_N);
vi set_size(MAX_N);

void make_set(int v){
    parent[v] = v;
    set_size[v] = 1;
}

int find_set(int v){
    if(v == parent[v]) return v;
    else return(parent[v]=find_set(parent[v]));
}

void union_sets(int a , int b){
    a = find_set(a); b = find_set(b);
    if(a!=b){
        if(set_size[a] < set_size[b]){
            swap(a,b);
        }
        parent[b] = a;
        set_size[a] += set_size[b];
    }
}


void solve(){
    int i;
   for(i=0;i<MAX_N;i++){
       make_set(i);
   }

   int n,m; cin>>n>>m;
   vector<vi> edges;
   for(i=0;i<m;i++){
       int u,v; cin>>u>>v;
       edges.push_back({u , v});

   }
   bool cycle = false;

   for(auto i : edges){
       int x = i[0];
       int y = i[1];
       int u = find_set(x);
       int v = find_set(y);
       if(u==v) cycle = true;
       else union_sets(x,y);
   }

   if(cycle){
       cout<<"cycle is presnt \n";
   }else{
       cout<<"cycle is absent\n";
   }
}

int main() {
    
        solve();
    
    return(0);
}