
#include<iostream>
#include<iomanip>
using namespace std;
const long long int MOD = 1e9 + 7;

int main() {
   long long int n,a=2;
   cin>>n;
 long long int result = 1;
 while(n>0){
     if(n%2!=0){
         result = (result % MOD * a % MOD) % MOD;
     }
       a = (a % MOD * a % MOD) % MOD;
       n = n/2;
    
 }
 cout<<result;
}