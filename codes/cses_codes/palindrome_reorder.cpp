//l.size() == odd --> one char should be odd remaining even
//l.size() == even--> all char should be even

#include<iostream>
#include<iomanip>
using namespace std;

int main(){
   long long int i, count[26],l,j,q=0,k=0;
    char b;
    string s;
    cin>>s;
    l = s.size();
    for(i=0;i<26;i++){
        count[i] = 0;
    }
    for(i=0;i<l;i++){
        for(j=0;j<26;j++){
            b = 65 + j;
            if(s[i] == b){
                count[j]++;
            }
        }
    }
    for(i=0;i<26;i++){
        cout<<count[i]<<" ";
    }
   /*
   for(i=0;i<26;i++){
       if(l%2==0){
           if(count[i]%2!=0){
               cout<<"NO SOLUTION";
               exit(0);
           }
       }else{
           if(count[i]%2!=0){
               q++;
               if(q>1){
              cout<<"NO SOLUTION";
              exit(0);               
               }
               const int c = i;
               b = 65 + i;
               s[l/2] = b;
               count[i]--;
           }
       }
   }

   //if yes prints palindrome
   for(i=0;i<26;i++){
     for(j=0;j<count[i];j = j + 2){
         b = 65 + i;
         s[k] = s[l-k-1] = b;
         k++;
     }
   }
    cout<<endl<<s;
    */
}