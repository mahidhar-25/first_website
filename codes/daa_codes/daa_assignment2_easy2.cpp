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



void solve(){
    int i;
  string s;
  cin>>s;
  if(s.size()%2==1){
      cout<<"string is unbalenced\n";
      return;
  }
  stack<char> a;
  for(i=0;i<s.size();i++){
      cout<<"s[i] = "<<s[i];
      if(s[i] == '('){
          cout<<" : pushes\n";
          a.push(s[i]);
      }else{
           cout<<" : pops\n";
          if(a.size()>0){
            a.pop();
      }else{
           cout<<"string is unbalenced\n";
      return;
      }
  }
  }
  
  if(a.size() == 0){
       cout<<"string is balenced\n";
      return;
  }else{
       cout<<"string is unbalenced\n";
      return;
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