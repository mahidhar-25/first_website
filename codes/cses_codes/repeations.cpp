#include<iostream>
#include<iomanip>
using namespace std;
long long int count= 1;

int main(){
    string s;
    cin>>s;
    long long int l = s.size();
    long long int i,b,j = 0;
    for(i=1;i<l;i++){
        if(s[i] == s[i-1]){
            ++count;
         
        }
        else{
            if(j==0){
                b = count;
                j++;
            }else{
                if(b < count){
                    b = count;
                }
                j++;
            }
         
            count = 1;
        }
        
    }
    if(b<count){
        b = count;
    }
  if(count == l){
      b = l;
  }
 
   cout<<b;
}