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
ll n; cin>>n;
vi a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
stack<int> s;
for(int i=0;i<n;i++){
     
     while(!s.empty() && a[s.top()]>=a[i]){
         s.pop();
     }

     if(s.empty()){
         cout<<"0 ";
     }else{
         cout<<s.top()+1<<" ";
     }
     s.push(i);
}
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