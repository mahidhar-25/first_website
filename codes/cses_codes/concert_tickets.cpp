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

vector<bool> sold;


void solve(){
 ll n,m,i;
 cin>>n>>m;
 vi a(n),b(m);
 vector<bool> used(n , false);
 for(i=0;i<n;i++){
     cin>>a[i];
 }
 for(i=0;i<m;i++){
     cin>>b[i];
 }
 multiset<int,greater<int>>s;
	for(i=0;i<n;i++) s.insert(a[i]);
for(i=0;i<m;i++){
		auto it=s.lower_bound(b[i]);
		if(it==s.end())cout<<-1<<endl;
		else
		{
			cout<<*it<<endl;
			s.erase(it);
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
