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


template<typename T>
void solve(){
    int n,i,j,k=0;
    cout<<"enter the size of an array : ";
    cin>>n;
    vector<T> a(n);
    vector<vector<T>> b(n);
    cout<<"entered the elemets : ";
    for(i=0;i<n;i++){
        cin>>a[i];
        b[i].push_back(a[i]);
    }

    while(b.size()>1){
        for(i=0;i+1<b.size();i=i+2){
            if(b[i][0]>b[i+1][0]){
                b[i].push_back(b[i+1][0]);
               b.erase(b.begin()+i+1);
            }else{
                 b[i+1].push_back(b[i][0]);
                 b.erase(b.begin()+i);
            }
            i--;
        }
    }
    
    cout<<"fought with highest are : ";
        for(j=0;j<b[0].size();j++){
            cout<<b[0][j]<<" ";
        }
        cout<<"\n";
    

    while(b[0].size()>2){
    for(i=1;i+1<b[0].size();i=i+2){
        if(b[0][i]>b[0][i+1]){
            b[0].erase(b[0].begin()+i+1);
        }else{
             b[0].erase(b[0].begin()+i);
        }
    }
    }

    cout<<"winner = "<<b[0][0]<<"\nrunner = "<<b[0][1]<<"\n";
}

int main() {
    int choice;
    while(1){
        cout<<"\n1. char datatype\n2. float datatype\n3. int datatype\n4. string datatype\nenter your choice : "; cin>>choice;
      switch(choice){
          case 1 : solve<char>(); break;
          case 2 : solve<float>(); break;
          case 3 : solve<int>(); break;
          case 4 : solve<string>(); break;
          case 5 : exit(0); break;
          default : cout<<"entered a valid choice\n";
      }
    }
    
    return(0);
}