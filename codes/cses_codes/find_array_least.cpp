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


ll find_divisors(ll ele, ll n){
    ll i,index,least = INT_MAX;
    for(i=1;i<=n;i++){
        if(n%i==0){
          if(i==ele){return(i);}
          if((ele-i)>0 && (ele-i)<least ){least = ele-i; index = i;}
          if((i-ele)>0 && (i-ele)<least ){least = i-ele; index = i;}
        }
    }
    return(index);
}

ll find_multiples(ll ele,ll n){
    ll rem,res;
    rem = ele % n; res = ele/n;
    if(rem >= n/2){ return(n*(res+1));}
    else if(rem < n/2){return(n*(res)); }
    return(0);
}



void solve(){
    ll cases,k,val,j,i,index = 0; cin>>cases;
    while(cases!=0){
        cin>>k;
        ll a[k],b[k],max= INT_MIN;
        for(i=0;i<k;i++){cin>>a[i]; if(a[i]>max){max = a[i]; index = i; } }
        b[index] = max;
        // left_array(b,a,index,k);
         for(j=index;j>0;j--){
        if((a[j-1]-a[j])<=0){ b[j-1] = find_divisors(a[j-1],b[j]); }
        if(a[j-1]>a[j]){ b[j-1] = find_multiples(a[j-1],b[j]); }
    }

       for(j=index;j<k;j++){
        if((a[j+1]-a[j])<=0){ b[j+1] = find_divisors(a[j+1],b[j]); }
        if(a[j+1]>a[j]){ b[j+1] = find_multiples(a[j+1],b[j]); }
    }




    for(j=0;j<k;j++){ cout<<b[j]<<" "; }
    cout<<endl; cases--;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
 
}