

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

 int backup=-1;
 int max_length(int a , int b1 , int min , int max , vector<vi> b){
     int i;
     for(i=0;i<b[a].size();i++){
         if(b[a][i] >= min){
             if(b[a][i]>=backup){
                 break;
             }
         }
     }
     
    
     
     backup = b[a][i];
     int j;
     for(j=b[b1].size()-1;j>=0;j--){
         if(b[b1][j] <= max){
             break;
         }
     }
      if(i>=b[a].size() || j<0){
         return(INT_MIN);
     }
       return(b[b1][j]-b[a][i]);
 }

void solve() {
    int width , max_width = INT_MIN,i,j;
  string s1,s2; cin>>s1>>s2;
  vector<vi> b(s2.size());
  for(i=0;i<s2.size();i++){
      for(j=0;j<s1.size();j++){
          if(s1[j] == s2[i]){
              b[i].push_back(j);
          }
      }
  }


int n = s2.size();
  for(i=0;i+1<s2.size();i++){
      width = max_length( i , i+1 , b[0][0] , b[n-1][b[n-1].size()-1] , b);
      max_width = max(width , max_width);
       cout<<"max_width : "<<max_width<<endl;
  }
  if(max_width > s1.size()){
      cout<<"-1\n";
  }else{
    cout<<"max_width : "<<max_width<<endl;
  }
}
int main() {
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return(0);
}


