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
char* next_greater_no(char* input1, int input2) {
   int i, j;
   for (i = input2-1; i > 0; i--)
      if (*(input1 + i) > *(input1 + i-1))
         break;
   if (i==0) {
      cout<<"next number is impossible";return(0);
   }
   int next_great_digit = *(input1 + i-1), small_digit = i;
   for (j = i+1; j < input2; j++)
      if (*(input1 + j) > next_great_digit && *(input1 + j) < *(input1 + small_digit))
         small_digit = j;
   swap(*(input1 + small_digit) , *(input1 + i-1)); sort(*(input1 + 0) + i, *(input1+input2));
    return input1;
}

int main(){
    int n,i; cin>>n;
    string a,b;
        cin>>a;
    cout<<next_greater_no(a, n);
    return(0);
}

