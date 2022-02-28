
  
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
bool flag = 0;



int main(){
    ll n,i;
    string s;
    vector<string> a;
    cin>>s;
  sort(all(s));
do{
    a.push_back(s);
}while(next_permutation(all(s)));
cout<<a.size()<<endl;
for(auto c : a) cout<<c<<endl;
}


