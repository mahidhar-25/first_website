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
ll n , count =0,i,sum; cin>>n;
vi a,b;
if((n*(n+1))/2 % 2 !=0){
    cout<<"NO";
}else{
    cout<<"YES"<<endl;
    sum = (n*(n+1))/4;
    for(ll i=n; i>0 ; i--){
        if(count + i<= sum){
            count += i; a.push_back(i);
        }else{
            b.push_back(i);
        }
    }
    cout<<a.size()<<endl;
    for(auto c : a) cout<<c<<" ";
    cout<<endl<<b.size()<<endl; 
    for(auto c : b) cout<<c<<" ";
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