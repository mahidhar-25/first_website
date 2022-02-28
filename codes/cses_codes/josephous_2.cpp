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
    ll n,k,count=0; cin>>n>>k;
    int i;
   vi a(n);
    
    for(i=0;i<n;i++){
     a[i] = i+1;
    }
    if(k>n){
        k = k%n;
        cout<<" k = "<<k<<endl;
    }

    while(a.size()>k){
        vi b;
        count = 0;
        for(i=0;i<a.size();i++){
            if(count == k){
                count = 0;
                cout<<a[i]<<" ";
            }else{
                count++;
                b.push_back(a[i]);
            }
        }
        if(a.size()%(k+1)==0){
            a = b;
        }else{
            int c = (a.size()%(k+1));
            int d[c];
            for(i=c-1;i>=0;i--){
           d[i]= b.back();
            b.pop_back();
            }
            a.clear();
            for(i=0;i<c;i++){
                a.push_back(d[i]);
            }
              for(i=0;i<b.size();i++){
                a.push_back(b[i]);
            }
        }
    }
    if(k < n){
   for(i=0;i<k;i++){
       cout<<a[i]<<" ";
   }
    }
    else{
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
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