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

void no_of_appartments_filled(vi desired_size , vi actual_size , ll n , ll m , ll k){
    ll i,j,x,count=0,size = 0;
    filled.resize(m,false);
    for(i=0 , j= 0; i<n && j<m;){
       if(desired_size[i]+k < actual_size[j]){
         i++;
       }else if(desired_size[i] - k > actual_size[j]){
           j++;
       }else{
           count++;i++;j++;
       }

}
  cout<<count;
}

void solve(){
    ll n,m,k,i;
    cin>>n>>m>>k;
    vi desired_size(n),actual_size(m);
    for(i=0;i<n;i++){
        cin>>desired_size[i];
    }
    sort(all(desired_size));
    for(i=0;i<m;i++){
        cin>>actual_size[i];
    }
    sort(all(actual_size));
    no_of_appartments_filled(desired_size,actual_size,n,m,k);
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