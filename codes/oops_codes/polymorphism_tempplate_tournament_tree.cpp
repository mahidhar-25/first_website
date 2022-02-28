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


// 1 5 7 2 3 8 9 11

// 5 1
// 7 2
// 8 3
// 11 9

// 7 2 5
// 11 9 8

//11 9 8 7

// 11   9 7

// 11 9
template<typename T>
void solve(){
    int n,i;
    cout<<"enter the size of an array : "; cin>>n;
    vector<T> a(n);
    vector<vector<T>>b(n);
    cout<<"enter the elemts of an array : ";
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

    while(b[0].size()>2){
        for(i=1;i+1<b[0].size();i=i+2){
            if(b[0][i]>b[0][i+1]){
                b[0].erase(b[0].begin()+i+1);
            }else{
                 b[0].erase(b[0].begin()+i);
            }
        }
    }

    cout<<"winner : "<<b[0][0]<<" runner : "<<b[0][1]<<endl;
    
}


int main() {
    int choice;
   

        while(1){
             cout<<"1. int datatype\n2. char datatype \n3. float datatype \n4. string datatype \n5. exit \nenter your choice : "; cin>>choice;
            switch(choice){
                case 1 : solve<int>() ;break;
                case 2 : solve<char>() ;break;
                case 3 : solve<float>() ;break;
                case 4 : solve<string>() ;break;
                case 5 : exit(0); break;
                default : cout<<"enter a valid choice\n" ;break;
            }
        }
    
    return(0);
}