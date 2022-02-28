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

//even aitey starting same untadi odd aitey last safe elemnt tho start avvali

void solve(){
    ll n; cin>>n;
    int i;
   vi a(n);
    
    for(i=0;i<n;i++){
     a[i] = i+1;
    }

    while(a.size()>1){
        vi b;
        for(i=0;i<a.size();i++){
            if(i%2==1){
                cout<<a[i]<<" ";
            }else{
                b.push_back(a[i]);
            }
        }
        if(a.size()%2==0){
            a = b;
        }else{
            int last_odd = b.back();
            b.pop_back();
            a.clear();
            a.push_back(last_odd);
            for(i=0;i<b.size();i++){
                a.push_back(b[i]);
            }
        }
    }
    cout<<a[0]<<" ";

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