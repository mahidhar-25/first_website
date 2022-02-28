
#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define ar array
#define ll long long int
#define vi vector<int>
#define all(x) x.begin(),x.end()

class sorting{
    vi a;
    public :
    void bubble_sort(vi  , int);
    void selection_sort(vi , int);
    void insertion_sort(vi , int);
    void mergeSort(int*  , int , int);
    void heap_sort(vi , int);
}s;
//bubble sort involves n2 complexity
void sorting::bubble_sort(vi b , int n){
    int i,j,temp;
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(b[j] < b[i]){
               swap(b[i] , b[j]);
            }
        }
          for(auto c : b ){
        cout<<c<<" ";
    }cout<<endl;
    }

    cout<<"sorted array through bubble sort is : ";
    for(auto c : b ){
        cout<<c<<" ";
    }
}

//selection at each iteration picks the least element in right part array and store begin of right array
void sorting::selection_sort(vi b, int n){
    for(int i=0 ; i< n-1 ; i++){
        int min = i;
        for(int j = i+1 ;j<n ; j++){
             if(b[min] > b[j]){
                 min = j;
             }
        }
        if(min!=i){
           swap(b[i] , b[min]);
        }
        for(auto c : b ){
        cout<<c<<" ";
    }cout<<endl;
    }
     cout<<"sorted array through selection sort is : ";
    for(auto c : b ){
        cout<<c<<" ";
    }
}

//insertion sort at ith iteration first i elemnts are sorted
void sorting:: insertion_sort(vi b, int n){
    int i,j, temp;
    for(i=1;i<n;i++){
        temp = b[i];
        j = i-1;
        while(j>=0 && b[j] > temp ){
            b[j+1] = b[j]; j--;
        }
        b[j+1] = temp;
        for(auto c : b ){
        cout<<c<<" ";
    }cout<<endl;
    }
     cout<<"sorted array through insertion sort is : ";
    for(auto c : b ){
        cout<<c<<" ";
    }
}

//merge combines the two array in sorted manner
void merge(int *array, int l, int m, int r) {
   int i, j, k, nl, nr;
   //size of left and right sub-arrays
  int size1 = m-l+1, size2 = r-m;
   int first_arr[size1], second_arr[size2];
   //fill left and right sub-arrays
   for(i = 0; i<size1; i++)
       first_arr[i] = array[l+i];
   for(j = 0; j<size2; j++)
      second_arr[j] = array[m+1+j];
   i = 0; j = 0; k = l;
   //marge temp arrays to real array
   while(i < size1 && j<size2) {
      if( first_arr[i] <=second_arr[j]) {
         array[k] =  first_arr[i];
         i++;
      }else{
         array[k] = second_arr[j];
         j++;
      }
      k++;
   }
   
   while(i<size1) {       //extra element in left array
      array[k] =  first_arr[i];
      i++; k++;
   }
   while(j<size2) {     //extra element in right array
      array[k] = second_arr[j];
      j++; k++;
   }
}

//function of merge sort dividing the array size into 1
void sorting::mergeSort(int *array, int l, int r) {
   int m;
   if(l < r) {
      int m = l+(r-l)/2;
      // Sort first and second arrays
      mergeSort(array, l, m);
      mergeSort(array, m+1, r);
      merge(array, l, m, r);
   }
}

//heap sort del max ele and storing last index of an left array
void sorting:: heap_sort(vi a, int n){
    int j,i,temp;
    for(j=n-1;j>0;j--){
        for(i=j;i>0;i--){
            if(a[i]>a[(i-1)/2]){
             swap(a[i] , a[(i-1)/2]);
            }
        }
        swap(a[j] , a[0]);
        for(auto c : a ){
        cout<<c<<" ";
    }cout<<endl;
    }
    cout<<"heap sort: ";
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
}
void solve(){
    int n,i; 
    cout<<"enter the size of an array : "; cin>>n;
    vi a(n), b(n) ,c(n) ,d(n) ,e(n) ;
    int arr[n]; cout<<"entere the elements of an array :";
    for(i=0;i<n;i++){
        cin>>a[i];
        arr[i] = b[i] = a[i];
    }
    cout<<"bubble sort :"<<endl;
    s.bubble_sort(b , n); cout<<endl;
     cout<<"selection sort :"<<endl;
    s.selection_sort(b , n); cout<<endl;
     cout<<"insertion sort :"<<endl;
    s.insertion_sort(b , n); cout<<endl;
     cout<<"heap sort :"<<endl;
    s.heap_sort(b,n); cout<<endl;
      s.mergeSort(arr, 0, n-1);
      cout<<"merge_sort :"; 
    for(auto c : arr){
        cout<<" "<<c;
    }
    
}

int main(){
    solve();
}


