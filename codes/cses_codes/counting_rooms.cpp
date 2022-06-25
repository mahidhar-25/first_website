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

vector<bool> filled;
 
    void dfs(int i , int j , vector<vector<char>>& grid , vector<vector<bool>>& visited ){
        if(i<0 || j<0) return;
        if(i>=grid.size() || j>=grid[0].size())return;
        if(visited[i][j]==true && grid[i][j]=='.')return;
        if(grid[i][j]!='.')return;
        if(visited[i][j]==false && grid[i][j]=='.'){
            visited[i][j]=true;
        }
         dfs(i-1 , j , grid , visited);
         dfs(i+1 , j , grid , visited);
         dfs(i , j-1 , grid , visited);
         dfs(i , j+1 , grid , visited);
        return;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        vector<vector<bool>>visited(grid.size() , vector<bool>(grid[0].size() , false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='.' && visited[i][j]==false){
                    dfs(i , j , grid , visited);
                    ans++;
                }
            }
        }
        return(ans);
    }


void solve(){
    int n,m,i,j;
    cin>>n>>m;
    vector<vector<char>>grid(n , vector<char>(m));
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    
    cout<<numIslands(grid);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return(0);
}