// logic : 
// step 1 : take input weight , max weight , and item profits
// step 2 : sort the profit in descending order using sort() in built function which take O(nlogn), in worst case O(n2)
// step 3 : include the weight if it doesnt exceed and add profit to it and continue until it exceeds
// print the maximun profit

// time complexity :  O(n) + O(nlogn) is equal to O(nlogn) which is o(n2)

// space complexity : O(n);

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

class knapsack{
    int w;
    public : 
    void getdata();
}s;

void knapsack :: getdata(){
    int n,max_weigh,profit = 0, weigh = 0,i,j;
    cout<<"enter no of different items  : "; cin>>n;  //take no of items
    int w; cout<<"enter the weight of elements : "; cin>>w; // take weight
    vi p(n);
    cout<<"enter the profits all elements : ";
    for(i=0;i<n;i++){
        cin>>p[i];     // taking all the profits of each item
    }
    cout<<"enter max weigh : "; cin>>max_weigh;
   sort(al(p));  // sorting in decreasing order 
    for(i=0;i<n;i++){
         if(weigh + w <= max_weigh){
             profit += p[i];
             weigh += w;
         }
    }
    cout<<"profit is : "<<profit<<endl;
}



void solve(){
s.getdata();
}

int main(){
    solve();
    return(0);
}
