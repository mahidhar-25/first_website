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
 multiset<int> a;
 vi temp;
 while(n--){
     int x; cin>>x; 
    auto it = a.upper_bound(x);

    if(it==a.end()) a.insert(x);
    else{
        a.erase(it); a.insert(x);
    }
     
}
cout<<a.size();
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