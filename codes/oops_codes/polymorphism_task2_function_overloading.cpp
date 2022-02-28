
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

class dynamic_overload{
    vi a;
    public : 
    void getdata();
    void knap_sack_getdata(int , vi , vi);
    void knap_sack_getdata(double , vector<double> ,vector<double>);
    void knap_sack_getdata(int , vi);
    void knap_sack_getdata(int , vi , vi , bool);

}s;

void dynamic_overload::knap_sack_getdata(int max_weigh , vi weight , vi profit){
    int n = weight.size();
    int i,j;
    int m = max_weigh;
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

void dynamic_overload::knap_sack_getdata(double max_weigh ,vector<double>weight ,vector<double>profit){
   
int i,n;
n = weight.size();
vector<array<double , 2>> a(n);
  for( i=0;i<n;i++)
  {
      a[i][0] = profit[i];
      a[i][1] = weight[i];
  }
  sort(al(a));
  cout<<"Elements enter by you is \n";
  for( i=0;i<n;i++)
  {
      cout<<"\nvalue "<<a[i][0]<<" weight "<<a[i][1];
  }
    double current=0,rem;
   double currentval=0;
     for(i=0;i<n;i++)
     { if((current<=max_weigh)&& (a[i][1]<=max_weigh-current))
       {    current=current+a[i][1];
        currentval=currentval+a[i][0];
        }
     }
     rem=max_weigh-current;
   cout<<"\n\nmaximum profit is: "<<currentval;
   cout<<"\ncurrent weight is: "<<current;
   cout<<"\nweight left: "<<rem;
   cout<<"\n";

}

void dynamic_overload::knap_sack_getdata(int max_weigh , vi weight){
    int n = weight.size(),i,index=0;
    sort(all(weight));
    int current_needed_weight = max_weigh;
    cout<<"the weight we include are : ";
    for(i=0;i<n;i++){
        if(current_needed_weight >= weight[i]){
         current_needed_weight -= weight[i];
         cout<<weight[i]<<" ";
         index = i;
        }
    }
    cout<<"cardinality : "<<index+1<<"\n";
    cout<<"remaining weight = "<<current_needed_weight<<"\n";
}

void dynamic_overload::knap_sack_getdata(int max_weigh , vi weight , vi profit1 , bool flag){
      int n = weight.size(),i,index=0;
       double target,sum,count=0,val,profit=0;
       vector<array<int , 2>> a(n);
       vector<array<double ,2>>b(n);
    if(flag){
        s.knap_sack_getdata(max_weigh,weight,profit1);
    }else{
    for(i=0;i<n;i++){
        a[i][0] = weight[i];
        a[i][1] = profit1[i]; // a[i][0] = x , a[i][1] = y
        b[i][0] = profit1[i]/weight[i] ;
        b[i][1] =  i;
    }
    sort(al(b));
    target = max_weigh;
    sum = target;
    for(i=0;i<n;i++){
        if(a[b[i][1]][0] <= sum){
            sum = sum - a[b[i][1]][0];
            cout<<"we taken weigh  "<< a[b[i][1]][0] <<"  and profit is : "<< a[b[i][1]][1]<<endl<<endl;
            profit = profit +  a[b[i][1]][1];
            count++;
        }else{
            val = (sum / a[b[i][1]][0])* a[b[i][1]][0];
            sum = sum - val;
            profit= profit + (val/ a[b[i][1]][0])*a[b[i][1]][1];
             cout<<"we taken weigh   "<< val <<" of  "<<a[b[i][1]][0] <<"  and profit is : "<< ((val/ a[b[i][1]][0])*a[b[i][1]][1])<<" of : "<<a[b[i][1]][1]<<endl<<endl;
            count = count + (val / a[b[i][1]][0]);
        }
    }
    cout<<"total count  is : "<<count<<endl<<endl;
    cout<<"total profit is : "<<profit<<endl;

    }
}
void dynamic_overload::getdata(){
    vi a,p;
    vector<double> a1,p1;
    double w1,v;
    int w,x,choice,choice1,n,i;
    bool flag;
    while(1){
        cout<<"\n1. knap_sack_getdata(int , int , int) ";
        cout<<"\n2. knap_sack_getdata(double , double ,double)";
        cout<<"\n3. void knap_sack_getdata(int , int)";
        cout<<"\n4. void knap_sack_getdata(int , int , int , bool)";
        cout<<"\n5. exit";
        cout<<"\nenter your choice : "; cin>>choice;
        switch(choice){
            case 1:
                   cout<<"enter the no of items :";cin>>n;
                   cout<<"enter weights in <int> : ";
                   for(i=0;i<n;i++){
                       cin>>x; a.push_back(x);
                   }
                   cout<<"enter profits in <int> : ";
                    for(i=0;i<n;i++){
                       cin>>x; p.push_back(x);
                   }
                   cout<<"enter max weight in <int> : "; cin>>w;
                   s.knap_sack_getdata(w,a,p);
            break;
            case 2: 
                   cout<<"enter the no of items :";cin>>n;
                   cout<<"enter weights in <double> : ";
                   for(i=0;i<n;i++){
                       cin>>v; a1.push_back(v);
                   }
                   cout<<"enter profits in <double> : ";
                    for(i=0;i<n;i++){
                       cin>>v; p1.push_back(v);
                   }
                   cout<<"enter max weight in <double> : "; cin>>w1;
                   s.knap_sack_getdata(w1,a1,p1);
            break;
            case 3 :
                   cout<<"enter the no of items :";cin>>n;
                   cout<<"enter weights in <int> : ";
                   for(i=0;i<n;i++){
                       cin>>x; a.push_back(x);
                   }
                   cout<<"enter max weight in <int> : "; cin>>w;
                   s.knap_sack_getdata(w,a);
            break;
            case 4 :
                   cout<<"enter the no of items :";cin>>n;
                   cout<<"enter weights in <int> : ";
                   for(i=0;i<n;i++){
                       cin>>x; a.push_back(x);
                   }
                   cout<<"enter profits in <int> : ";
                    for(i=0;i<n;i++){
                       cin>>x; p.push_back(x);
                   }
                   cout<<"enter max weight in <int> : "; cin>>w;
                   cout<<"0. for fractional kanpasack\n1. 0-1 knapsack \nenter your choice : ";cin>>flag;
                   s.knap_sack_getdata(w,a,p,flag);
            break;
            case 5 : exit(0); break;
            default : cout<<"enter a valid choice \n"; break;
               
                   
               
        }
    }
}

int main(){
    s.getdata();
    return(0);
}

