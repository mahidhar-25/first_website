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


void solve(){
int n,target,sum = 0,low,high,i,j;
cin>>n>>target;
vector<array<int , 2>> a(n);
for(i=0;i<n;i++){
    int x ; cin>>x;
    a[i] = {x , i+1};
}
sort(all(a));
for(i=0;i<n;i++){
    sum = a[i][0];
    low = i+1; high = n-1;
    while(low < high){
      if(a[low][0] + a[high][0] > target - sum){
          high--;
      }else if(a[low][0] + a[high][0]  < target - sum){
          low++;
      }else{
          cout<<a[i][1]<<" "<<a[low][1]<<" "<<a[high][1]<<endl; return;
      }
    }
}
cout<<"IMPOSSIBLE"<<endl;
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