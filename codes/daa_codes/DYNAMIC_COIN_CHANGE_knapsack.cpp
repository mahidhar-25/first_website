#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()
#define all(x) x.begin(),x.end()

const int MAX_N = 1e5 + 1;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;

class dynamic_coin{
    vi a;
    public : 
    void getdata();
    void knap_sack_getdata();
}s;

void dynamic_coin::getdata(){
int n,val,i,j;
cout<<"enter no of coins : "; cin>>n;
vi a(n);
cout<<"enter coins type : ";
for(i=0;i<n;i++){
    cin>>a[i];
}
sort(all(a));
cout<<"enter the value to convert it into change  : "; cin>>val;
vi dp(val+1 , INT_MAX);
dp[0] = 0;  //o no change 0 coins required minimum

for(i=1;i<val+1;i++){
  for(j=0;j<n;j++){
      if(a[j]<=i){
          int min_coins = dp[i-a[j]];
          if(min_coins!= INT_MAX && min_coins + 1 <dp[i]){
              dp[i] = min_coins + 1;
          }
      }
  }
}
cout<<"min coins needed for "<< val <<" is : "<<dp[val]<<endl;
}

void  dynamic_coin::knap_sack_getdata(){
    int n,m,i,j;
    cout<<"enter no of different type of weighs : "; cin>>n;
    vi weight(n),profit(n);
   
    for(i=0;i<n;i++){
       cout<<"enter each weigh and its profit : ";   cin>>weight[i]>>profit[i];
    }
    int max_weigh;

    cout<<"enter the max capacity of bag : "; cin>>max_weigh;
    m = max_weigh;
    int dp[n+1][m+1];

    for(i=0;i<=n;i++){

        // we will check for all profits and weights we will go through one by one 

        for(j=0;j<=max_weigh;j++){

            // we storre for evry kg/g of weight what is the max value of profit for such weight and we go upto max_weigh

            if(i==0||j==0){

                // as we declare our array n+1 , m+1 size we making first row and colum as zero minimum profit

              dp[i][j] = 0;
           }else if(weight[i-1] <= j){

               // if weight is less than our index(which is weight) we will check by considering that weight value and not considering that weight value
               dp[i][j] = max(profit[i-1] + dp[i-1][j-weight[i-1]] , dp[i-1][j]);
           }else{

               // if weigh is greater we wont consider it weight
               dp[i][j] = dp[i-1][j];
           }
        }
    }

    for(i=0;i<n+1;i++){
        for(j=1;j<m+1;j++){
            if(i<=j)
            cout<<dp[i][j]<<" ";
            else
            cout<<" ";
        }
        cout<<endl<<endl;
    }

    cout<<"max profit is : "<<dp[n][m]<<endl;
}

int main(){
    s.getdata();
    s.knap_sack_getdata();
    return(0);
}