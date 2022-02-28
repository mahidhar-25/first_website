/*
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define al(x) x.rbegin(),x.rend()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

vector<bool> filled;



void solve(){
int n,i,j;
cin>>n;
vector<vi> a(n) ,  b(n);
for(i=0;i<n;i++){
    int k , min_armor = INT_MIN; cin>>k;
    for(j=0;j<k;j++){
        int x ; cin>>x;
        a[i].push_back(x);
        min_armor = max(min_armor , a[i][j]);
    }
   b[i].push_back(min_armor); b[i].push_back(i);
}
sort(all(b));

   int power ,backup;
   power = a[b[0][1]][0]+1;
   backup = power;
    cout<<"power : "<<power<<endl;
for(i=0;i<n;i++){
   cout<<b[i][0]<<"  "<<b[i][1]<<endl;

   power = backup;
   for(j=0;j<a[b[i][1]].size();j++){
         if(power>a[b[i][1]][i]){ power++ ; }
         else{
             int energy = a[b[i][1]][i] - power;
             power += energy + 1;
             power++;
         }
         cout<<"power : "<<power<<endl;
   }
   backup = power;

}

cout<<power<<endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
    return(0);
}*/
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define al(x) x.rbegin(),x.rend()
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

#include <iostream>
#include <vector>

using namespace std;

int findminpr(vector<int>a){
    int i,temppr=0;
    for(i=0;i<a.size();i++){
        if(temppr<=(a[i]-i)){
            temppr=(a[i]-i)+1;
        }
    }
    return temppr;
}

int main()
{
    int n,i,j,x,y,p;
    cout<<"eneter no of caves: ";
    cin>>n;
    vector <int> a[n];
    int minpr[n];
    vector<array<int , 2>> pr(n);
    for(i=0;i<n;i++){
        cout<<"no of opponents in cave "<<i+1<<": ";
        cin>>x;
        cout<<"enter the armor of all those opponents in order: ";
        a[i].resize(x);
        for(j=0;j<x;j++){
            cin>>a[i][j];
            
        }
        pr[i][1] = x; pr[i][0] = findminpr(a[i]);
    }
    sort(all(pr));
    int temppower=0,ans=0;
    for(i=0;i<n;i++){
        if(temppower<pr[i][0]){
            ans=ans+pr[i][0]-temppower;
            temppower=pr[i][0];
        }
        temppower=temppower+pr[i][1];
    }
    
    cout<<"\nfinal ans: "<<ans;
    return 0;
}

/*
ll gcd(ll a, ll b)
{
if (b == 0)
return a;
return gcd(b, a % b);
}
void solve()
{
    ll n;cin>>n;
    vector<pair<ll,ll>> power(n);
    for(int i=0;i<n;i++){
        ll x;cin>>x;vector<ll> p(x);
        ll mxp=-1;;
        for(int j=0;j<x;j++) {
            cin>>p[j];
           mxp=max(mxp,p[j]-j+1);
        }
        power[i]={mxp,x};
    }
    sort(power.begin(),power.end());
    ll l=power[0].first,r=power[n-1].first;
    ll ans=1e12;
    while(l<=r){
        ll mid=(l+r)/2;ll curr=mid;
        bool ok=1;
        for(int i=0;i<n;i++){
            if(curr>=power[i].first){
                curr+=power[i].second;
            }
            else{
                ok=0;break;
            }
        }
        if(ok){
            ans=mid;r=mid-1;
        }
        else l=mid+1;
    }
    cout<<ans<<endl;
}

*/