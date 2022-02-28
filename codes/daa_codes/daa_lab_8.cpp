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

class graph{
    int v;
    vector<vi> adj;
    public :
      void getdata_bfs();
      void bfs(int , vector<vi>);
      void getdata_dfs();
      void dfs(int , vector<vi> , vector<bool>&);
      void check_bipartite(int , vector<vi>);
      void check_cycle_bfs(vector<vi>);

}s;

void graph::check_cycle_bfs(vector<vi> adj){

    vector<int> in_degree(adj.size() , 0);

    for(int i=0;i<adj.size();i++){
        for(auto c : adj[i]){
            in_degree[c]++;
        }
    }

    queue<int> q;
    for(int i=0;i<adj.size();i++){
        if(in_degree[i]==0) q.push(i);
    }

    int count=0;

    vi top_order;

    while(!q.empty()){
        int sub_root = q.front(); q.pop();
        top_order.push_back(sub_root);

        for(auto c : adj[sub_root] ){
            if(--in_degree[c]==0){
                q.push(c);
            }
        }
        count++;
    }
cout<<"top order : ";

for(auto c : top_order) cout<<c<<" ";

cout<<"\n";
    if(count==v){
        cout<<"there doesnt exist any cycle\n";
    }else{
        cout<<"there exist a cycle\n";
    }
}

bool check_bipartite_1(int v , vector<vi> adj , int root , vi& colour_given){
    queue<int> q;
    q.push(root);
    colour_given[root] = 1;
    while(!q.empty())
    {
        int sub_root = q.front();
        q.pop();
        int colour = colour_given[sub_root];

        for(auto i : adj[sub_root]){
            if(colour_given[i] != -1){
               if(colour_given[i]==colour) return(false);
            }else{
                colour_given[i] = (colour==0)?1:0;
                q.push(i);
            }
        }
    }
    return(true);
}

void graph::check_bipartite(int v , vector<vi> adj){
    vector<int> colour_given(v , -1);

    for(int i=0;i<v;i++){
        if(colour_given[i] == -1){
            if(check_bipartite_1(v , adj , i , colour_given)==false) {
                cout<<"false : garph is not a bipartiate \n"; return;
        }
    }
    
}
cout<<"true : given graph is bipartite\n";
}



void graph::bfs(int root , vector<vi> adj ){
vector<bool> visited(adj.size() , false);

list<int> queue;
visited[root] = true;
queue.push_back(root);

// 1->2 3 6 
// 2 -> 4 3 7
while(!queue.empty()){
    int sub_root = queue.front();
    cout<<"sub root : "<<sub_root<<" \n";
    queue.pop_front();

    for(auto c : adj[sub_root]){
        if(visited[c] == false){
            visited[c] = true;
            queue.push_back(c);
        }
    }
}
}



void graph::getdata_bfs(){
    int v,m,i,j;
    cout<<"enter no of nodes : "; cin>>v;
    vector<vi> adj(v+1);
    cout<<"no of edges : "; cin>>m;
    cout<<"enter edges from to : ";
    for(i=0;i<m;i++){
        int x,y;  
        cout<<i <<"th edge : "; cin>>x>>y;
      adj[x].push_back(y);
    }
 cout<<"edges entered succesfully\n";
    int random = rand()%(v-1)+1;
    cout<<"random = "<<random;
    cout<<"\n values edges : \n";
  for(i=0;i<adj.size();i++){
      for(j=0;j<adj[i].size();j++){
          cout<<"edge  : "<<i<<" ->  "<<adj[i][j]<<"\n ";
      }
      cout<<"\n\n\n";
  }
    s.bfs(random , adj);
    s.check_bipartite(v+1 , adj);
    s.check_cycle_bfs(adj);

}

void graph::dfs(int root , vector<vi> adj , vector<bool> &visited){
visited[root] = true;
cout<<"sub root : "<<root<<"\n";
for(auto c : adj[root]){
    if(visited[c]==false){
        dfs(c , adj , visited);
    }
}
}

void graph::getdata_dfs(){
     int v,m,i,j;
    cout<<"enter no of nodes : "; cin>>v;
    vector<vi> adj(v+1);
    cout<<"no of edges : "; cin>>m;
    cout<<"enter edges from to : ";
    for(i=0;i<m;i++){
        int x,y;  
        cout<<i <<"th edge : "; cin>>x>>y;
      adj[x].push_back(y);
    }
 cout<<"edges entered succesfully\n";
 //1 4 7 5
 // 2 3
    int random = rand()%(v-1)+1;
    cout<<"random = "<<random;
    cout<<"\n values edges : \n";
  for(i=0;i<adj.size();i++){
      for(j=0;j<adj[i].size();j++){
          cout<<"edge  : "<<i<<" ->  "<<adj[i][j]<<"\n ";
      }
      cout<<"\n\n\n";
  }
  vector<bool> visited(adj.size() , false);
    s.dfs(random , adj ,visited);
}

void solve(){
 s.getdata_bfs();
  s.getdata_dfs();
}

int main() {
    
        solve();
    
    return(0);
}