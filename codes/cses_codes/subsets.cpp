#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vi subset;
void generate_subsets(vi &a,int n ,int k){
   // cout<<"n  = "<<n<<"  k = "<<k<<endl;
    if(k==n){
        for(auto c: subset){
            cout<<c<<" ";
        }
        cout<<endl;
    }else{
        subset.push_back(a[k]);
        generate_subsets(a,n,k+1);
        subset.pop_back();
        generate_subsets(a,n,k+1);
    }
}

void solve(){
    int n,i;
    ll b;
   vi a;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>b;
        a.push_back(b);
    }
    generate_subsets(a,n,0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t  << ": ";
        solve();
    }
}